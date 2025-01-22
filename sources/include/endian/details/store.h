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
namespace details
{
template <eEndian FROM_E, eEndian TO_E>
struct store_constexpr_impl
{
};

template <eEndian FROM_E>
struct store_constexpr_impl<FROM_E, eEndian::kLittle>
{
    template <typename T>
    inline constexpr void operator()(std::byte *aBuffer, T &&aValue,
                                     std::size_t N) noexcept
    {
        assert(N <= sizeof(T));
        for (std::size_t i = 0; i < N; ++i)
        {
            aBuffer[i] = static_cast<std::byte>(aValue >> i * CHAR_BIT);
        }
    }
};

template <eEndian FROM_E>
struct store_constexpr_impl<FROM_E, eEndian::kBig>
{
    template <typename T>
    inline constexpr void operator()(std::byte *aBuffer, T &&aValue,
                                     std::size_t N) noexcept
    {
        assert(N <= sizeof(T));
        for (std::size_t i = 0; i < N; ++i)
        {
            aBuffer[i] =
                static_cast<std::byte>(aValue >> (N - 1 - i) * CHAR_BIT);
        }
    }
};

template <eEndian FROM_E, eEndian TO_E>
struct store_impl
{
    template <typename T>
    static inline constexpr void store(std::byte *aBuffer, T &&aValue,
                                       std::size_t N) noexcept
    {
        if (__builtin_is_constant_evaluated())
        {
            store_constexpr_impl<FROM_E, TO_E>()(aBuffer,
                                                 std::forward<T>(aValue), N);
        }
        else
        {
            const auto v = convert<TO_E, FROM_E>(std::forward<T>(aValue));
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
}  // namespace details

template <eEndian TO_E, typename T>
inline constexpr void store(std::byte *aBuffer, T &&aValue,
                            std::size_t N) noexcept
{
    assert(aBuffer);
    assert(N > 0);
    assert(N <= sizeof(T));
    static_assert(details::is_sizeof_one_of_v<T, 1, 2, 4, 8>);
    static_assert(
        details::is_uint_v<std::remove_cv_t<std::remove_reference_t<T>>>);
    static_assert((TO_E == eEndian::kLittle) || (TO_E == eEndian::kBig));
    details::store_impl<eEndian::kNative, TO_E>::store(
        aBuffer, std::forward<T>(aValue), N);
}

template <eEndian TO_E, typename T>
inline constexpr void store(std::byte *aBuffer, T &&aValue) noexcept
{
    using u_t = std::remove_cv_t<std::remove_reference_t<T>>;
    store<TO_E>(aBuffer, std::forward<T>(aValue), sizeof(u_t));
}
}  // namespace endian

#endif /* endian_store_h */
