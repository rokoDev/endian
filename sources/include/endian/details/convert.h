#ifndef endian_convert_h
#define endian_convert_h

#include "bswap.h"
#include "enum.h"

namespace endian
{
template <eEndian To, eEndian From, typename T>
inline constexpr auto convert(T &&aValue) noexcept
{
    static_assert(
        details::is_uint_v<std::remove_cv_t<std::remove_reference_t<T>>>);
    static_assert((To == eEndian::kBig) || (To == eEndian::kLittle));
    static_assert((From == eEndian::kBig) || (From == eEndian::kLittle));
    if constexpr (To == From)
    {
        return aValue;
    }
    else
    {
        return bswap(std::forward<T>(aValue));
    }
}

template <eEndian To, eEndian From, typename T>
inline constexpr void convert_inplace(T &aValue) noexcept
{
    aValue = convert<To, From>(aValue);
}

template <eEndian From, typename T>
inline constexpr auto to_native(T &&aValue) noexcept
{
    return convert<eEndian::kNative, From>(std::forward<T>(aValue));
}

template <eEndian To, typename T>
inline constexpr auto from_native(T &&aValue) noexcept
{
    return convert<To, eEndian::kNative>(std::forward<T>(aValue));
}

template <eEndian From, typename T>
inline constexpr void to_native_inplace(T &aValue) noexcept
{
    aValue = convert<eEndian::kNative, From>(aValue);
}

template <eEndian To, typename T>
inline constexpr void from_native_inplace(T &aValue) noexcept
{
    aValue = convert<To, eEndian::kNative>(aValue);
}
}  // namespace endian

#endif /* endian_convert_h */
