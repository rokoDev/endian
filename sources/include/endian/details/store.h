#ifndef endian_store_h
#define endian_store_h

#include <array>
#include <cassert>
#include <cstddef>
#include <cstring>
#include <type_traits>

#include "convert.h"
#include "enum.h"

namespace endian
{
template <eEndian TO_E, std::size_t N, typename T>
inline constexpr void store(std::byte *aBuffer, const T &aValue) noexcept;

namespace details
{
template <typename T, std::size_t N, eEndian FROM_E, eEndian TO_E>
struct store_constexpr_impl
{
};

template <typename T, std::size_t N, eEndian FROM_E>
struct store_constexpr_impl<T, N, FROM_E, eEndian::kLittle>
{
    inline constexpr void operator()(std::byte *aBuffer,
                                     const T &aValue) noexcept
    {
        static_assert(N <= sizeof(T));
        for (std::size_t i = 0; i < N; ++i)
        {
            aBuffer[i] = static_cast<std::byte>(aValue >> i * CHAR_BIT);
        }
    }
};

template <typename T, std::size_t N, eEndian FROM_E>
struct store_constexpr_impl<T, N, FROM_E, eEndian::kBig>
{
    inline constexpr void operator()(std::byte *aBuffer,
                                     const T &aValue) noexcept
    {
        static_assert(N <= sizeof(T));
        for (std::size_t i = 0; i < N; ++i)
        {
            aBuffer[i] =
                static_cast<std::byte>(aValue >> (N - 1 - i) * CHAR_BIT);
        }
    }
};

template <typename T, std::size_t N, eEndian FROM_E, eEndian TO_E>
struct store_impl
{
    inline constexpr void operator()(std::byte *aBuffer,
                                     const T &aValue) noexcept
    {
        if (__builtin_is_constant_evaluated())
        {
            return store_constexpr_impl<T, N, FROM_E, TO_E>()(aBuffer, aValue);
        }
        else
        {
            const T v = convert<TO_E, FROM_E>(aValue);
            if constexpr (TO_E == eEndian::kLittle)
            {
                std::memcpy(aBuffer, &v, N);
            }
            else
            {
                std::memcpy(
                    aBuffer,
                    reinterpret_cast<std::byte const *>(&v) + sizeof(T) - N, N);
            }
        }
    }
};

template <typename T, eEndian TO_E, std::size_t... I>
constexpr decltype(auto) create_store_funcs_array(std::index_sequence<I...>)
{
    using store_func = void (*)(std::byte *, const T &) noexcept;
    return std::array<store_func, sizeof...(I)>{store<TO_E, I + 1, T>...};
}

template <typename T, eEndian TO_E>
inline constexpr auto store_functions =
    create_store_funcs_array<T, TO_E>(std::make_index_sequence<sizeof(T)>{});
}  // namespace details

template <eEndian TO_E, std::size_t N, typename T>
inline constexpr void store(std::byte *aBuffer, const T &aValue) noexcept
{
    assert(aBuffer);
    static_assert(N > 0);
    static_assert(N <= sizeof(T));
    static_assert(details::is_sizeof_one_of_v<T, 1, 2, 4, 8>);
    static_assert(details::is_uint_v<T>);
    static_assert((TO_E == eEndian::kLittle) || (TO_E == eEndian::kBig));
    details::store_impl<T, N, eEndian::kNative, TO_E>()(aBuffer, aValue);
}

template <eEndian TO_E, typename T>
inline constexpr void store(std::byte *aBuffer, const T &aValue) noexcept
{
    store<TO_E, sizeof(T)>(aBuffer, aValue);
}

template <eEndian TO_E, typename T>
inline constexpr void store(std::byte *aBuffer, const T &aValue,
                            std::size_t N) noexcept
{
    assert(N > 0);
    assert(N <= sizeof(T));
    details::store_functions<T, TO_E>[N - 1](aBuffer, aValue);
}
}  // namespace endian

#endif /* endian_store_h */
