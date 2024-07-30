#ifndef endian_load_h
#define endian_load_h

#include <array>
#include <cassert>
#include <cstddef>
#include <cstring>
#include <type_traits>
#include <utility>

#include "convert.h"
#include "enum.h"

namespace endian
{
template <typename T, eEndian FROM_E, std::size_t N = sizeof(T)>
inline constexpr T load(std::byte const *aBuffer) noexcept;

namespace details
{
template <typename T, std::size_t N, eEndian TO_E, eEndian FROM_E>
struct load_constexpr_impl
{
};

template <typename T, std::size_t N, eEndian TO_E>
struct load_constexpr_impl<T, N, TO_E, eEndian::kLittle>
{
    inline constexpr T operator()(std::byte const *aBuffer) noexcept
    {
        static_assert(N <= sizeof(T));
        T v{};
        for (std::size_t i = 0; i < N; ++i)
        {
            v |= static_cast<T>(static_cast<T>(aBuffer[i]) << i * CHAR_BIT);
        }
        return v;
    }
};

template <typename T, std::size_t N, eEndian TO_E>
struct load_constexpr_impl<T, N, TO_E, eEndian::kBig>
{
    inline constexpr T operator()(std::byte const *aBuffer) noexcept
    {
        static_assert(N <= sizeof(T));
        T v{};
        for (std::size_t i = 0; i < N; ++i)
        {
            v |= static_cast<T>(static_cast<T>(aBuffer[i])
                                << (N - 1 - i) * CHAR_BIT);
        }
        return v;
    }
};

template <typename T, std::size_t N, eEndian TO_E, eEndian FROM_E>
struct load_impl
{
    inline constexpr T operator()(std::byte const *aBuffer) noexcept
    {
        if (__builtin_is_constant_evaluated())
        {
            return load_constexpr_impl<T, N, TO_E, FROM_E>()(aBuffer);
        }
        else
        {
            T v{};
            if constexpr (FROM_E == eEndian::kLittle)
            {
                std::memcpy(&v, aBuffer, N);
            }
            else
            {
                std::memcpy(reinterpret_cast<std::byte *>(&v) + sizeof(T) - N,
                            aBuffer, N);
            }
            convert_inplace<TO_E, FROM_E>(v);
            return v;
        }
    }
};

template <typename T, eEndian FROM_E, std::size_t... I>
constexpr decltype(auto) create_load_funcs_array(std::index_sequence<I...>)
{
    using load_func = T (*)(std::byte const *) noexcept;
    return std::array<load_func, sizeof...(I)>{load<T, FROM_E, I + 1>...};
}

template <typename T, eEndian FROM_E>
inline constexpr auto load_functions =
    create_load_funcs_array<T, FROM_E>(std::make_index_sequence<sizeof(T)>{});
}  // namespace details

template <typename T, eEndian FROM_E, std::size_t N>
inline constexpr T load(std::byte const *aBuffer) noexcept
{
    assert(aBuffer);
    static_assert(N > 0);
    static_assert(N <= sizeof(T));
    static_assert(details::is_sizeof_one_of_v<T, 1, 2, 4, 8>);
    static_assert(details::is_uint_v<T>);
    static_assert((FROM_E == eEndian::kLittle) || (FROM_E == eEndian::kBig));
    return details::load_impl<T, N, eEndian::kNative, FROM_E>()(aBuffer);
}

template <typename T, eEndian FROM_E>
inline constexpr T load(std::byte const *aBuffer, std::size_t N) noexcept
{
    assert(N > 0);
    assert(N <= sizeof(T));
    return details::load_functions<T, FROM_E>[N - 1](aBuffer);
}

template <eEndian FROM_E, typename T, std::size_t N = sizeof(T)>
inline constexpr void load_inplace(T &aValue, std::byte const *aBuffer) noexcept
{
    aValue = load<T, FROM_E, N>(aBuffer);
}

template <eEndian FROM_E, typename T>
inline constexpr void load_inplace(T &aValue, std::size_t N,
                                   std::byte const *aBuffer) noexcept
{
    aValue = load<T, FROM_E>(aBuffer, N);
}
}  // namespace endian

#endif /* endian_load_h */
