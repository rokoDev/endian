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
namespace details
{
template <typename T, eEndian TO_E, eEndian FROM_E>
struct load_constexpr_impl
{
};

template <typename T, eEndian TO_E>
struct load_constexpr_impl<T, TO_E, eEndian::kLittle>
{
    inline constexpr T operator()(std::byte const *const aBuffer,
                                  std::size_t N) noexcept
    {
        assert(N <= sizeof(T));
        T v{};
        for (std::size_t i = 0; i < N; ++i)
        {
            v |= static_cast<T>(static_cast<T>(aBuffer[i]) << i * CHAR_BIT);
        }
        return v;
    }
};

template <typename T, eEndian TO_E>
struct load_constexpr_impl<T, TO_E, eEndian::kBig>
{
    inline constexpr T operator()(std::byte const *const aBuffer,
                                  std::size_t N) noexcept
    {
        assert(N <= sizeof(T));
        T v{};
        for (std::size_t i = 0; i < N; ++i)
        {
            v |= static_cast<T>(static_cast<T>(aBuffer[i])
                                << (N - 1 - i) * CHAR_BIT);
        }
        return v;
    }
};

template <typename T, eEndian TO_E, eEndian FROM_E>
struct load_impl
{
    inline constexpr T operator()(std::byte const *const aBuffer,
                                  std::size_t N) noexcept
    {
        if (__builtin_is_constant_evaluated())
        {
            return load_constexpr_impl<T, TO_E, FROM_E>()(aBuffer, N);
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
}  // namespace details

template <typename T, eEndian FROM_E>
inline constexpr T load(std::byte const *const aBuffer, std::size_t N) noexcept
{
    assert(aBuffer);
    assert(N <= sizeof(T));
    static_assert(details::is_sizeof_one_of_v<T, 1, 2, 4, 8>);
    static_assert(details::is_uint_v<T>);
    static_assert((FROM_E == eEndian::kLittle) || (FROM_E == eEndian::kBig));
    return details::load_impl<T, eEndian::kNative, FROM_E>()(aBuffer, N);
}

template <typename T, eEndian FROM_E>
inline constexpr T load(std::byte const *const aBuffer) noexcept
{
    return load<T, FROM_E>(aBuffer, sizeof(T));
}

template <eEndian FROM_E, typename T>
inline constexpr void load_inplace(T &aValue, std::byte const *const aBuffer,
                                   std::size_t N) noexcept
{
    aValue = load<T, FROM_E>(aBuffer, N);
}

template <eEndian FROM_E, typename T>
inline constexpr void load_inplace(T &aValue,
                                   std::byte const *const aBuffer) noexcept
{
    load_inplace<T, FROM_E>(aValue, aBuffer, sizeof(T));
}
}  // namespace endian

#endif /* endian_load_h */
