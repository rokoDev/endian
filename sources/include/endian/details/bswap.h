#ifndef endian_bswap_h
#define endian_bswap_h

#include "bswap_intrinsics.h"
#include "typedefs.h"

namespace endian
{
namespace details
{
template <typename T, std::size_t... I>
constexpr decltype(auto) crafted_bswap_impl(T aValue,
                                            std::index_sequence<I...>) noexcept
{
    static_assert(is_uint_v<T>);
    return static_cast<T>(
        (... | static_cast<T>((0b11111111 & (aValue >> (I * CHAR_BIT)))
                              << ((sizeof(T) - 1 - I) * CHAR_BIT))));
};

template <typename T>
constexpr T crafted_bswap(T aValue) noexcept
{
    static_assert(is_uint_v<T>);
    return details::crafted_bswap_impl(std::move(aValue),
                                       std::make_index_sequence<sizeof(T)>{});
}
#ifndef BSWAP_NO_INTRINSICS
template <typename T>
inline T intrinsics_bswap(T aValue) noexcept
{
    static_assert(is_uint_v<T>);
    static_assert(sizeof(T) <= sizeof(std::uint64_t));

    if constexpr (sizeof(T) == 1)
    {
        return aValue;
    }
    else if constexpr (sizeof(T) == 2)
    {
        return BSWAP_INTRINSIC_2(aValue);
    }
    else if constexpr (sizeof(T) == 4)
    {
        return BSWAP_INTRINSIC_4(aValue);
    }
    else
    {
        return BSWAP_INTRINSIC_8(aValue);
    }
}
#endif  // BSWAP_NO_INTRINSICS
}  // namespace details
template <typename T>
inline constexpr T bswap(T aValue) noexcept
{
    if (__builtin_is_constant_evaluated())
    {
        return details::crafted_bswap(std::move(aValue));
    }
    else
    {
#ifdef BSWAP_NO_INTRINSICS
        return details::crafted_bswap(std::move(aValue));
#else
        return details::intrinsics_bswap(std::move(aValue));
#endif
    }
}
}  // namespace endian

#endif /* endian_bswap_h */
