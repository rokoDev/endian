#ifndef endian_enum_h
#define endian_enum_h

namespace endian
{
enum class eEndian
{
    kLittle,
    kBig,
    kMixed,
#ifndef HOST_BIG_ENDIAN
    kNative = kLittle
#else
    kNative = kBig
#endif
};

template <typename T = uint32_t>
typename std::enable_if_t<std::is_trivial_v<T> && std::is_standard_layout_v<T>,
                          eEndian>
native_endian() noexcept
{
    static_assert(sizeof(T) == 4, "sizeof(T) must be 4");
    constexpr uint32_t hostOrder = 0x1020304;
    T result;

    constexpr uint8_t bigOrderBytes[sizeof(T)]{1, 2, 3, 4};
    std::memcpy(&result, &bigOrderBytes, sizeof(T));
    if (hostOrder == result)
    {
        return eEndian::kBig;
    }

    constexpr uint8_t littleOrderBytes[sizeof(T)]{4, 3, 2, 1};
    std::memcpy(&result, &littleOrderBytes, sizeof(T));
    if (hostOrder == result)
    {
        return eEndian::kLittle;
    }
    return eEndian::kMixed;
}
}  // namespace endian

#endif /* endian_enum_h */
