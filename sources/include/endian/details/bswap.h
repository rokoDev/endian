#ifndef endian_bswap_h
#define endian_bswap_h

#include "bswap_intrinsics.h"
#include "typedefs.h"

namespace endian
{
namespace details
{
template <typename T, std::size_t... I>
constexpr auto crafted_bswap_impl(T&& aValue,
                                  std::index_sequence<I...>) noexcept
{
    using u_t = std::remove_cv_t<std::remove_reference_t<T>>;
    static_assert(is_uint_v<u_t>);
    return static_cast<u_t>(
        (... | static_cast<u_t>((0b11111111 & (aValue >> (I * CHAR_BIT)))
                                << ((sizeof(u_t) - 1 - I) * CHAR_BIT))));
};

template <typename T>
constexpr auto crafted_bswap(T&& aValue) noexcept
{
    using u_t = std::remove_cv_t<std::remove_reference_t<T>>;
    static_assert(is_uint_v<u_t>);
    return details::crafted_bswap_impl(std::forward<T>(aValue),
                                       std::make_index_sequence<sizeof(u_t)>{});
}
#ifndef BSWAP_NO_INTRINSICS
template <typename T>
inline auto intrinsics_bswap(T&& aValue) noexcept
{
    using u_t = std::remove_cv_t<std::remove_reference_t<T>>;
    static_assert(is_uint_v<u_t>);
    static_assert(sizeof(u_t) <= sizeof(std::uint64_t));

    if constexpr (sizeof(u_t) == 1)
    {
        return aValue;
    }
    else if constexpr (sizeof(u_t) == 2)
    {
        return BSWAP_INTRINSIC_2(aValue);
    }
    else if constexpr (sizeof(u_t) == 4)
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
inline constexpr auto bswap(T&& aValue) noexcept
{
    if (__builtin_is_constant_evaluated())
    {
        return details::crafted_bswap(std::forward<T>(aValue));
    }
    else
    {
#ifdef BSWAP_NO_INTRINSICS
        return details::crafted_bswap(std::forward<T>(aValue));
#else
        return details::intrinsics_bswap(std::forward<T>(aValue));
#endif
    }
}
}  // namespace endian

#endif /* endian_bswap_h */
