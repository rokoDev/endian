#ifndef endian_convert_h
#define endian_convert_h

#include "bswap.h"
#include "enum.h"

namespace endian
{
template <eEndian To, eEndian From, typename T>
inline constexpr T convert(T aValue) noexcept
{
    static_assert(details::is_uint_v<T>);
    static_assert((To == eEndian::kBig) || (To == eEndian::kLittle));
    static_assert((From == eEndian::kBig) || (From == eEndian::kLittle));
    if constexpr (To == From)
    {
        return aValue;
    }
    else
    {
        return bswap(aValue);
    }
}

template <eEndian To, eEndian From, typename T>
inline constexpr void convert_inplace(T &aValue) noexcept
{
    aValue = convert<To, From>(aValue);
}

template <eEndian From, typename T>
inline constexpr T to_native(T aValue) noexcept
{
    return convert<eEndian::kNative, From>(aValue);
}

template <eEndian To, typename T>
inline constexpr T from_native(T aValue) noexcept
{
    return convert<To, eEndian::kNative>(aValue);
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
