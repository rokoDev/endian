#include <endian/endian.h>
#include <gtest/gtest.h>

using namespace endian;

// convert 1 byte tests
TEST(ConvertUInt8, LittleToLittle)
{
    using uint_t = std::uint8_t;
    uint_t value{0x1};
    uint_t expected{0x1};
    uint_t converted = convert<eEndian::kLittle, eEndian::kLittle>(value);
    ASSERT_EQ(expected, converted);
}

TEST(ConvertUInt8, BigToBig)
{
    using uint_t = std::uint8_t;
    uint_t value{0x1};
    uint_t expected{0x1};
    uint_t converted = convert<eEndian::kBig, eEndian::kBig>(value);
    ASSERT_EQ(expected, converted);
}

TEST(ConvertUInt8, LittleToBig)
{
    using uint_t = std::uint8_t;
    uint_t value{0x1};
    uint_t expected{0x1};
    uint_t converted = convert<eEndian::kBig, eEndian::kLittle>(value);
    ASSERT_EQ(expected, converted);
}

TEST(ConvertUInt8, BigToLittle)
{
    using uint_t = std::uint8_t;
    uint_t value{0x1};
    uint_t expected{0x1};
    uint_t converted = convert<eEndian::kLittle, eEndian::kBig>(value);
    ASSERT_EQ(expected, converted);
}

TEST(ConstexprConvertUInt8, LittleToLittle)
{
    using uint_t = std::uint8_t;
    constexpr uint_t value{0x1};
    constexpr uint_t expected{0x1};
    constexpr uint_t converted =
        convert<eEndian::kLittle, eEndian::kLittle>(value);
    static_assert(expected == converted);
}

TEST(ConstexprConvertUInt8, BigToBig)
{
    using uint_t = std::uint8_t;
    constexpr uint_t value{0x1};
    constexpr uint_t expected{0x1};
    constexpr uint_t converted = convert<eEndian::kBig, eEndian::kBig>(value);
    static_assert(expected == converted);
}

TEST(ConstexprConvertUInt8, LittleToBig)
{
    using uint_t = std::uint8_t;
    constexpr uint_t value{0x1};
    constexpr uint_t expected{0x1};
    constexpr uint_t converted =
        convert<eEndian::kBig, eEndian::kLittle>(value);
    static_assert(expected == converted);
}

TEST(ConstexprConvertUInt8, BigToLittle)
{
    using uint_t = std::uint8_t;
    constexpr uint_t value{0x1};
    constexpr uint_t expected{0x1};
    constexpr uint_t converted =
        convert<eEndian::kLittle, eEndian::kBig>(value);
    static_assert(expected == converted);
}

// convert 2 bytes tests

TEST(ConvertUInt16, LittleToLittle)
{
    using uint_t = std::uint16_t;
    uint_t value{0x102};
    uint_t expected{0x102};
    uint_t converted = convert<eEndian::kLittle, eEndian::kLittle>(value);
    ASSERT_EQ(expected, converted);
}

TEST(ConvertUInt16, BigToBig)
{
    using uint_t = std::uint16_t;
    uint_t value{0x102};
    uint_t expected{0x102};
    uint_t converted = convert<eEndian::kBig, eEndian::kBig>(value);
    ASSERT_EQ(expected, converted);
}

TEST(ConvertUInt16, LittleToBig)
{
    using uint_t = std::uint16_t;
    uint_t value{0x102};
    uint_t expected{0x201};
    uint_t converted = convert<eEndian::kBig, eEndian::kLittle>(value);
    ASSERT_EQ(expected, converted);
}

TEST(ConvertUInt16, BigToLittle)
{
    using uint_t = std::uint16_t;
    uint_t value{0x102};
    uint_t expected{0x201};
    uint_t converted = convert<eEndian::kLittle, eEndian::kBig>(value);
    ASSERT_EQ(expected, converted);
}

TEST(ConstexprConvertUInt16, LittleToLittle)
{
    using uint_t = std::uint16_t;
    constexpr uint_t value{0x102};
    constexpr uint_t expected{0x102};
    constexpr uint_t converted =
        convert<eEndian::kLittle, eEndian::kLittle>(value);
    static_assert(expected == converted);
}

TEST(ConstexprConvertUInt16, BigToBig)
{
    using uint_t = std::uint16_t;
    constexpr uint_t value{0x102};
    constexpr uint_t expected{0x102};
    constexpr uint_t converted = convert<eEndian::kBig, eEndian::kBig>(value);
    static_assert(expected == converted);
}

TEST(ConstexprConvertUInt16, LittleToBig)
{
    using uint_t = std::uint16_t;
    constexpr uint_t value{0x102};
    constexpr uint_t expected{0x201};
    constexpr uint_t converted =
        convert<eEndian::kBig, eEndian::kLittle>(value);
    static_assert(expected == converted);
}

TEST(ConstexprConvertUInt16, BigToLittle)
{
    using uint_t = std::uint16_t;
    constexpr uint_t value{0x102};
    constexpr uint_t expected{0x201};
    constexpr uint_t converted =
        convert<eEndian::kLittle, eEndian::kBig>(value);
    static_assert(expected == converted);
}

// convert 4 bytes tests

TEST(ConvertUInt32, LittleToLittle)
{
    using uint_t = std::uint32_t;
    uint_t value{0x1020304};
    uint_t expected{0x1020304};
    uint_t converted = convert<eEndian::kLittle, eEndian::kLittle>(value);
    ASSERT_EQ(expected, converted);
}

TEST(ConvertUInt32, BigToBig)
{
    using uint_t = std::uint32_t;
    uint_t value{0x1020304};
    uint_t expected{0x1020304};
    uint_t converted = convert<eEndian::kBig, eEndian::kBig>(value);
    ASSERT_EQ(expected, converted);
}

TEST(ConvertUInt32, LittleToBig)
{
    using uint_t = std::uint32_t;
    uint_t value{0x1020304};
    uint_t expected{0x4030201};
    uint_t converted = convert<eEndian::kBig, eEndian::kLittle>(value);
    ASSERT_EQ(expected, converted);
}

TEST(ConvertUInt32, BigToLittle)
{
    using uint_t = std::uint32_t;
    uint_t value{0x1020304};
    uint_t expected{0x4030201};
    uint_t converted = convert<eEndian::kLittle, eEndian::kBig>(value);
    ASSERT_EQ(expected, converted);
}

TEST(ConstexprConvertUInt32, LittleToLittle)
{
    using uint_t = std::uint32_t;
    constexpr uint_t value{0x1020304};
    constexpr uint_t expected{0x1020304};
    constexpr uint_t converted =
        convert<eEndian::kLittle, eEndian::kLittle>(value);
    static_assert(expected == converted);
}

TEST(ConstexprConvertUInt32, BigToBig)
{
    using uint_t = std::uint32_t;
    constexpr uint_t value{0x1020304};
    constexpr uint_t expected{0x1020304};
    constexpr uint_t converted = convert<eEndian::kBig, eEndian::kBig>(value);
    static_assert(expected == converted);
}

TEST(ConstexprConvertUInt32, LittleToBig)
{
    using uint_t = std::uint32_t;
    constexpr uint_t value{0x1020304};
    constexpr uint_t expected{0x4030201};
    constexpr uint_t converted =
        convert<eEndian::kBig, eEndian::kLittle>(value);
    static_assert(expected == converted);
}

TEST(ConstexprConvertUInt32, BigToLittle)
{
    using uint_t = std::uint32_t;
    constexpr uint_t value{0x1020304};
    constexpr uint_t expected{0x4030201};
    constexpr uint_t converted =
        convert<eEndian::kLittle, eEndian::kBig>(value);
    static_assert(expected == converted);
}

// convert 8 bytes tests

TEST(ConvertUInt64, LittleToLittle)
{
    using uint_t = std::uint64_t;
    uint_t value{0x102030405060708};
    uint_t expected{0x102030405060708};
    uint_t converted = convert<eEndian::kLittle, eEndian::kLittle>(value);
    ASSERT_EQ(expected, converted);
}

TEST(ConvertUInt64, BigToBig)
{
    using uint_t = std::uint64_t;
    uint_t value{0x102030405060708};
    uint_t expected{0x102030405060708};
    uint_t converted = convert<eEndian::kBig, eEndian::kBig>(value);
    ASSERT_EQ(expected, converted);
}

TEST(ConvertUInt64, LittleToBig)
{
    using uint_t = std::uint64_t;
    uint_t value{0x102030405060708};
    uint_t expected{0x807060504030201};
    uint_t converted = convert<eEndian::kBig, eEndian::kLittle>(value);
    ASSERT_EQ(expected, converted);
}

TEST(ConvertUInt64, BigToLittle)
{
    using uint_t = std::uint64_t;
    uint_t value{0x102030405060708};
    uint_t expected{0x807060504030201};
    uint_t converted = convert<eEndian::kLittle, eEndian::kBig>(value);
    ASSERT_EQ(expected, converted);
}

TEST(ConstexprConvertUInt64, LittleToLittle)
{
    using uint_t = std::uint64_t;
    constexpr uint_t value{0x102030405060708};
    constexpr uint_t expected{0x102030405060708};
    constexpr uint_t converted =
        convert<eEndian::kLittle, eEndian::kLittle>(value);
    static_assert(expected == converted);
}

TEST(ConstexprConvertUInt64, BigToBig)
{
    using uint_t = std::uint64_t;
    constexpr uint_t value{0x102030405060708};
    constexpr uint_t expected{0x102030405060708};
    constexpr uint_t converted = convert<eEndian::kBig, eEndian::kBig>(value);
    static_assert(expected == converted);
}

TEST(ConstexprConvertUInt64, LittleToBig)
{
    using uint_t = std::uint64_t;
    constexpr uint_t value{0x102030405060708};
    constexpr uint_t expected{0x807060504030201};
    constexpr uint_t converted =
        convert<eEndian::kBig, eEndian::kLittle>(value);
    static_assert(expected == converted);
}

TEST(ConstexprConvertUInt64, BigToLittle)
{
    using uint_t = std::uint64_t;
    constexpr uint_t value{0x102030405060708};
    constexpr uint_t expected{0x807060504030201};
    constexpr uint_t converted =
        convert<eEndian::kLittle, eEndian::kBig>(value);
    static_assert(expected == converted);
}

// convert inplace 1 byte tests

TEST(ConvertInplaceUInt8, LittleToLittle)
{
    using uint_t = std::uint8_t;
    uint_t value{0x1};
    uint_t expected{0x1};
    convert_inplace<eEndian::kLittle, eEndian::kLittle>(value);
    ASSERT_EQ(expected, value);
}

TEST(ConvertInplaceUInt8, BigToBig)
{
    using uint_t = std::uint8_t;
    uint_t value{0x1};
    uint_t expected{0x1};
    convert_inplace<eEndian::kBig, eEndian::kBig>(value);
    ASSERT_EQ(expected, value);
}

TEST(ConvertInplaceUInt8, LittleToBig)
{
    using uint_t = std::uint8_t;
    uint_t value{0x1};
    uint_t expected{0x1};
    convert_inplace<eEndian::kBig, eEndian::kLittle>(value);
    ASSERT_EQ(expected, value);
}

TEST(ConvertInplaceUInt8, BigToLittle)
{
    using uint_t = std::uint8_t;
    uint_t value{0x1};
    uint_t expected{0x1};
    convert_inplace<eEndian::kLittle, eEndian::kBig>(value);
    ASSERT_EQ(expected, value);
}

TEST(ConstexprConvertInplaceUInt8, LittleToLittle)
{
    using uint_t = std::uint8_t;
    constexpr uint_t value{0x1};
    constexpr uint_t expected{0x1};
    constexpr auto result = [](uint_t aValue)
    {
        convert_inplace<eEndian::kLittle, eEndian::kLittle>(aValue);
        return aValue;
    }(value);
    static_assert(expected == result);
}

TEST(ConstexprConvertInplaceUInt8, BigToBig)
{
    using uint_t = std::uint8_t;
    constexpr uint_t value{0x1};
    constexpr uint_t expected{0x1};
    constexpr auto result = [](uint_t aValue)
    {
        convert_inplace<eEndian::kBig, eEndian::kBig>(aValue);
        return aValue;
    }(value);
    static_assert(expected == result);
}

TEST(ConstexprConvertInplaceUInt8, LittleToBig)
{
    using uint_t = std::uint8_t;
    constexpr uint_t value{0x1};
    constexpr uint_t expected{0x1};
    constexpr auto result = [](uint_t aValue)
    {
        convert_inplace<eEndian::kBig, eEndian::kLittle>(aValue);
        return aValue;
    }(value);
    static_assert(expected == result);
}

TEST(ConstexprConvertInplaceUInt8, BigToLittle)
{
    using uint_t = std::uint8_t;
    constexpr uint_t value{0x1};
    constexpr uint_t expected{0x1};
    constexpr auto result = [](uint_t aValue)
    {
        convert_inplace<eEndian::kLittle, eEndian::kBig>(aValue);
        return aValue;
    }(value);
    static_assert(expected == result);
}

// convert inplace 2 bytes tests

TEST(ConvertInplaceUInt16, LittleToLittle)
{
    using uint_t = std::uint16_t;
    uint_t value{0x102};
    uint_t expected{0x102};
    convert_inplace<eEndian::kLittle, eEndian::kLittle>(value);
    ASSERT_EQ(expected, value);
}

TEST(ConvertInplaceUInt16, BigToBig)
{
    using uint_t = std::uint16_t;
    uint_t value{0x102};
    uint_t expected{0x102};
    convert_inplace<eEndian::kBig, eEndian::kBig>(value);
    ASSERT_EQ(expected, value);
}

TEST(ConvertInplaceUInt16, LittleToBig)
{
    using uint_t = std::uint16_t;
    uint_t value{0x102};
    uint_t expected{0x201};
    convert_inplace<eEndian::kBig, eEndian::kLittle>(value);
    ASSERT_EQ(expected, value);
}

TEST(ConvertInplaceUInt16, BigToLittle)
{
    using uint_t = std::uint16_t;
    uint_t value{0x102};
    uint_t expected{0x201};
    convert_inplace<eEndian::kLittle, eEndian::kBig>(value);
    ASSERT_EQ(expected, value);
}

TEST(ConstexprConvertInplaceUInt16, LittleToLittle)
{
    using uint_t = std::uint16_t;
    constexpr uint_t value{0x102};
    constexpr uint_t expected{0x102};
    constexpr auto result = [](uint_t aValue)
    {
        convert_inplace<eEndian::kLittle, eEndian::kLittle>(aValue);
        return aValue;
    }(value);
    static_assert(expected == result);
}

TEST(ConstexprConvertInplaceUInt16, BigToBig)
{
    using uint_t = std::uint16_t;
    constexpr uint_t value{0x102};
    constexpr uint_t expected{0x102};
    constexpr auto result = [](uint_t aValue)
    {
        convert_inplace<eEndian::kBig, eEndian::kBig>(aValue);
        return aValue;
    }(value);
    static_assert(expected == result);
}

TEST(ConstexprConvertInplaceUInt16, LittleToBig)
{
    using uint_t = std::uint16_t;
    constexpr uint_t value{0x102};
    constexpr uint_t expected{0x201};
    constexpr auto result = [](uint_t aValue)
    {
        convert_inplace<eEndian::kBig, eEndian::kLittle>(aValue);
        return aValue;
    }(value);
    static_assert(expected == result);
}

TEST(ConstexprConvertInplaceUInt16, BigToLittle)
{
    using uint_t = std::uint16_t;
    constexpr uint_t value{0x102};
    constexpr uint_t expected{0x201};
    constexpr auto result = [](uint_t aValue)
    {
        convert_inplace<eEndian::kLittle, eEndian::kBig>(aValue);
        return aValue;
    }(value);
    static_assert(expected == result);
}

// convert inplace 4 bytes tests

TEST(ConvertInplaceUInt32, LittleToLittle)
{
    using uint_t = std::uint32_t;
    uint_t value{0x1020304};
    uint_t expected{0x1020304};
    convert_inplace<eEndian::kLittle, eEndian::kLittle>(value);
    ASSERT_EQ(expected, value);
}

TEST(ConvertInplaceUInt32, BigToBig)
{
    using uint_t = std::uint32_t;
    uint_t value{0x1020304};
    uint_t expected{0x1020304};
    convert_inplace<eEndian::kBig, eEndian::kBig>(value);
    ASSERT_EQ(expected, value);
}

TEST(ConvertInplaceUInt32, LittleToBig)
{
    using uint_t = std::uint32_t;
    uint_t value{0x1020304};
    uint_t expected{0x4030201};
    convert_inplace<eEndian::kBig, eEndian::kLittle>(value);
    ASSERT_EQ(expected, value);
}

TEST(ConvertInplaceUInt32, BigToLittle)
{
    using uint_t = std::uint32_t;
    uint_t value{0x1020304};
    uint_t expected{0x4030201};
    convert_inplace<eEndian::kLittle, eEndian::kBig>(value);
    ASSERT_EQ(expected, value);
}

TEST(ConstexprConvertInplaceUInt32, LittleToLittle)
{
    using uint_t = std::uint32_t;
    constexpr uint_t value{0x1020304};
    constexpr uint_t expected{0x1020304};
    constexpr auto result = [](uint_t aValue)
    {
        convert_inplace<eEndian::kLittle, eEndian::kLittle>(aValue);
        return aValue;
    }(value);
    static_assert(expected == result);
}

TEST(ConstexprConvertInplaceUInt32, BigToBig)
{
    using uint_t = std::uint32_t;
    constexpr uint_t value{0x1020304};
    constexpr uint_t expected{0x1020304};
    constexpr auto result = [](uint_t aValue)
    {
        convert_inplace<eEndian::kBig, eEndian::kBig>(aValue);
        return aValue;
    }(value);
    static_assert(expected == result);
}

TEST(ConstexprConvertInplaceUInt32, LittleToBig)
{
    using uint_t = std::uint32_t;
    constexpr uint_t value{0x1020304};
    constexpr uint_t expected{0x4030201};
    constexpr auto result = [](uint_t aValue)
    {
        convert_inplace<eEndian::kBig, eEndian::kLittle>(aValue);
        return aValue;
    }(value);
    static_assert(expected == result);
}

TEST(ConstexprConvertInplaceUInt32, BigToLittle)
{
    using uint_t = std::uint32_t;
    constexpr uint_t value{0x1020304};
    constexpr uint_t expected{0x4030201};
    constexpr auto result = [](uint_t aValue)
    {
        convert_inplace<eEndian::kLittle, eEndian::kBig>(aValue);
        return aValue;
    }(value);
    static_assert(expected == result);
}

// convert inplace 8 bytes tests

TEST(ConvertInplaceUInt64, LittleToLittle)
{
    using uint_t = std::uint64_t;
    uint_t value{0x102030405060708};
    uint_t expected{0x102030405060708};
    convert_inplace<eEndian::kLittle, eEndian::kLittle>(value);
    ASSERT_EQ(expected, value);
}

TEST(ConvertInplaceUInt64, BigToBig)
{
    using uint_t = std::uint64_t;
    uint_t value{0x102030405060708};
    uint_t expected{0x102030405060708};
    convert_inplace<eEndian::kBig, eEndian::kBig>(value);
    ASSERT_EQ(expected, value);
}

TEST(ConvertInplaceUInt64, LittleToBig)
{
    using uint_t = std::uint64_t;
    uint_t value{0x102030405060708};
    uint_t expected{0x807060504030201};
    convert_inplace<eEndian::kBig, eEndian::kLittle>(value);
    ASSERT_EQ(expected, value);
}

TEST(ConvertInplaceUInt64, BigToLittle)
{
    using uint_t = std::uint64_t;
    uint_t value{0x102030405060708};
    uint_t expected{0x807060504030201};
    convert_inplace<eEndian::kLittle, eEndian::kBig>(value);
    ASSERT_EQ(expected, value);
}

TEST(ConstexprConvertInplaceUInt64, LittleToLittle)
{
    using uint_t = std::uint64_t;
    constexpr uint_t value{0x102030405060708};
    constexpr uint_t expected{0x102030405060708};
    constexpr auto result = [](uint_t aValue)
    {
        convert_inplace<eEndian::kLittle, eEndian::kLittle>(aValue);
        return aValue;
    }(value);
    static_assert(expected == result);
}

TEST(ConstexprConvertInplaceUInt64, BigToBig)
{
    using uint_t = std::uint64_t;
    constexpr uint_t value{0x102030405060708};
    constexpr uint_t expected{0x102030405060708};
    constexpr auto result = [](uint_t aValue)
    {
        convert_inplace<eEndian::kBig, eEndian::kBig>(aValue);
        return aValue;
    }(value);
    static_assert(expected == result);
}

TEST(ConstexprConvertInplaceUInt64, LittleToBig)
{
    using uint_t = std::uint64_t;
    constexpr uint_t value{0x102030405060708};
    constexpr uint_t expected{0x807060504030201};
    constexpr auto result = [](uint_t aValue)
    {
        convert_inplace<eEndian::kBig, eEndian::kLittle>(aValue);
        return aValue;
    }(value);
    static_assert(expected == result);
}

TEST(ConstexprConvertInplaceUInt64, BigToLittle)
{
    using uint_t = std::uint64_t;
    constexpr uint_t value{0x102030405060708};
    constexpr uint_t expected{0x807060504030201};
    constexpr auto result = [](uint_t aValue)
    {
        convert_inplace<eEndian::kLittle, eEndian::kBig>(aValue);
        return aValue;
    }(value);
    static_assert(expected == result);
}

// to native 8 bytes tests

TEST(ToNativeUInt64, FromLittle)
{
    using uint_t = std::uint64_t;
    uint_t value{0x102030405060708};
    uint_t expected = []() -> uint_t
    {
        static_assert((eEndian::kNative == eEndian::kLittle) ||
                      (eEndian::kNative == eEndian::kBig));
        if constexpr (eEndian::kNative == eEndian::kLittle)
        {
            return uint_t{0x102030405060708};
        }
        else
        {
            return uint_t{0x807060504030201};
        }
    }();
    const auto result = to_native<eEndian::kLittle>(value);
    ASSERT_EQ(expected, result);
}

TEST(ToNativeUInt64, FromBig)
{
    using uint_t = std::uint64_t;
    uint_t value{0x102030405060708};
    uint_t expected = []() -> uint_t
    {
        static_assert((eEndian::kNative == eEndian::kLittle) ||
                      (eEndian::kNative == eEndian::kBig));
        if constexpr (eEndian::kNative == eEndian::kLittle)
        {
            return uint_t{0x807060504030201};
        }
        else
        {
            return uint_t{0x102030405060708};
        }
    }();
    const auto result = to_native<eEndian::kBig>(value);
    ASSERT_EQ(expected, result);
}

TEST(ConstexprToNativeUInt64, FromLittle)
{
    using uint_t = std::uint64_t;
    constexpr uint_t value{0x102030405060708};
    constexpr uint_t expected = []() -> uint_t
    {
        static_assert((eEndian::kNative == eEndian::kLittle) ||
                      (eEndian::kNative == eEndian::kBig));
        if constexpr (eEndian::kNative == eEndian::kLittle)
        {
            return uint_t{0x102030405060708};
        }
        else
        {
            return uint_t{0x807060504030201};
        }
    }();
    constexpr auto result = to_native<eEndian::kLittle>(value);
    static_assert(expected == result);
}

TEST(ConstexprToNativeUInt64, FromBig)
{
    using uint_t = std::uint64_t;
    constexpr uint_t value{0x102030405060708};
    constexpr uint_t expected = []() -> uint_t
    {
        static_assert((eEndian::kNative == eEndian::kLittle) ||
                      (eEndian::kNative == eEndian::kBig));
        if constexpr (eEndian::kNative == eEndian::kLittle)
        {
            return uint_t{0x807060504030201};
        }
        else
        {
            return uint_t{0x102030405060708};
        }
    }();
    constexpr auto result = to_native<eEndian::kBig>(value);
    static_assert(expected == result);
}

// to native 4 bytes tests

TEST(ToNativeUInt32, FromLittle)
{
    using uint_t = std::uint32_t;
    uint_t value{0x1020304};
    uint_t expected = []() -> uint_t
    {
        static_assert((eEndian::kNative == eEndian::kLittle) ||
                      (eEndian::kNative == eEndian::kBig));
        if constexpr (eEndian::kNative == eEndian::kLittle)
        {
            return uint_t{0x1020304};
        }
        else
        {
            return uint_t{0x4030201};
        }
    }();
    const auto result = to_native<eEndian::kLittle>(value);
    ASSERT_EQ(expected, result);
}

TEST(ToNativeUInt32, FromBig)
{
    using uint_t = std::uint32_t;
    uint_t value{0x1020304};
    uint_t expected = []() -> uint_t
    {
        static_assert((eEndian::kNative == eEndian::kLittle) ||
                      (eEndian::kNative == eEndian::kBig));
        if constexpr (eEndian::kNative == eEndian::kLittle)
        {
            return uint_t{0x4030201};
        }
        else
        {
            return uint_t{0x1020304};
        }
    }();
    const auto result = to_native<eEndian::kBig>(value);
    ASSERT_EQ(expected, result);
}

TEST(ConstexprToNativeUInt32, FromLittle)
{
    using uint_t = std::uint32_t;
    constexpr uint_t value{0x1020304};
    constexpr uint_t expected = []() -> uint_t
    {
        static_assert((eEndian::kNative == eEndian::kLittle) ||
                      (eEndian::kNative == eEndian::kBig));
        if constexpr (eEndian::kNative == eEndian::kLittle)
        {
            return uint_t{0x1020304};
        }
        else
        {
            return uint_t{0x4030201};
        }
    }();
    constexpr auto result = to_native<eEndian::kLittle>(value);
    static_assert(expected == result);
}

TEST(ConstexprToNativeUInt32, FromBig)
{
    using uint_t = std::uint32_t;
    constexpr uint_t value{0x1020304};
    constexpr uint_t expected = []() -> uint_t
    {
        static_assert((eEndian::kNative == eEndian::kLittle) ||
                      (eEndian::kNative == eEndian::kBig));
        if constexpr (eEndian::kNative == eEndian::kLittle)
        {
            return uint_t{0x4030201};
        }
        else
        {
            return uint_t{0x1020304};
        }
    }();
    constexpr auto result = to_native<eEndian::kBig>(value);
    static_assert(expected == result);
}

// to native 2 bytes tests

TEST(ToNativeUInt16, FromLittle)
{
    using uint_t = std::uint16_t;
    uint_t value{0x102};
    uint_t expected = []() -> uint_t
    {
        static_assert((eEndian::kNative == eEndian::kLittle) ||
                      (eEndian::kNative == eEndian::kBig));
        if constexpr (eEndian::kNative == eEndian::kLittle)
        {
            return uint_t{0x102};
        }
        else
        {
            return uint_t{0x201};
        }
    }();
    const auto result = to_native<eEndian::kLittle>(value);
    ASSERT_EQ(expected, result);
}

TEST(ToNativeUInt16, FromBig)
{
    using uint_t = std::uint16_t;
    uint_t value{0x102};
    uint_t expected = []() -> uint_t
    {
        static_assert((eEndian::kNative == eEndian::kLittle) ||
                      (eEndian::kNative == eEndian::kBig));
        if constexpr (eEndian::kNative == eEndian::kLittle)
        {
            return uint_t{0x201};
        }
        else
        {
            return uint_t{0x102};
        }
    }();
    const auto result = to_native<eEndian::kBig>(value);
    ASSERT_EQ(expected, result);
}

TEST(ConstexprToNativeUInt16, FromLittle)
{
    using uint_t = std::uint16_t;
    constexpr uint_t value{0x102};
    constexpr uint_t expected = []() -> uint_t
    {
        static_assert((eEndian::kNative == eEndian::kLittle) ||
                      (eEndian::kNative == eEndian::kBig));
        if constexpr (eEndian::kNative == eEndian::kLittle)
        {
            return uint_t{0x102};
        }
        else
        {
            return uint_t{0x201};
        }
    }();
    constexpr auto result = to_native<eEndian::kLittle>(value);
    static_assert(expected == result);
}

TEST(ConstexprToNativeUInt16, FromBig)
{
    using uint_t = std::uint16_t;
    constexpr uint_t value{0x102};
    constexpr uint_t expected = []() -> uint_t
    {
        static_assert((eEndian::kNative == eEndian::kLittle) ||
                      (eEndian::kNative == eEndian::kBig));
        if constexpr (eEndian::kNative == eEndian::kLittle)
        {
            return uint_t{0x201};
        }
        else
        {
            return uint_t{0x102};
        }
    }();
    constexpr auto result = to_native<eEndian::kBig>(value);
    static_assert(expected == result);
}

// to native 1 byte tests

TEST(ToNativeUInt8, FromLittle)
{
    using uint_t = std::uint8_t;
    uint_t value{0x1};
    uint_t expected{0x1};
    const auto result = to_native<eEndian::kLittle>(value);
    ASSERT_EQ(expected, result);
}

TEST(ToNativeUInt8, FromBig)
{
    using uint_t = std::uint8_t;
    uint_t value{0x1};
    uint_t expected{0x1};
    const auto result = to_native<eEndian::kBig>(value);
    ASSERT_EQ(expected, result);
}

TEST(ConstexprToNativeUInt8, FromLittle)
{
    using uint_t = std::uint8_t;
    constexpr uint_t value{0x1};
    constexpr uint_t expected{0x1};
    constexpr auto result = to_native<eEndian::kLittle>(value);
    static_assert(expected == result);
}

TEST(ConstexprToNativeUInt8, FromBig)
{
    using uint_t = std::uint8_t;
    constexpr uint_t value{0x1};
    constexpr uint_t expected{0x1};
    constexpr auto result = to_native<eEndian::kBig>(value);
    static_assert(expected == result);
}

// from native 8 bytes tests

TEST(FromNativeUInt64, ToLittle)
{
    using uint_t = std::uint64_t;
    uint_t value{0x102030405060708};
    uint_t expected = []() -> uint_t
    {
        static_assert((eEndian::kNative == eEndian::kLittle) ||
                      (eEndian::kNative == eEndian::kBig));
        if constexpr (eEndian::kNative == eEndian::kLittle)
        {
            return uint_t{0x102030405060708};
        }
        else
        {
            return uint_t{0x807060504030201};
        }
    }();
    const auto result = from_native<eEndian::kLittle>(value);
    ASSERT_EQ(expected, result);
}

TEST(FromNativeUInt64, ToBig)
{
    using uint_t = std::uint64_t;
    uint_t value{0x102030405060708};
    uint_t expected = []() -> uint_t
    {
        static_assert((eEndian::kNative == eEndian::kLittle) ||
                      (eEndian::kNative == eEndian::kBig));
        if constexpr (eEndian::kNative == eEndian::kLittle)
        {
            return uint_t{0x807060504030201};
        }
        else
        {
            return uint_t{0x102030405060708};
        }
    }();
    const auto result = from_native<eEndian::kBig>(value);
    ASSERT_EQ(expected, result);
}

TEST(ConstexprFromNativeUInt64, ToLittle)
{
    using uint_t = std::uint64_t;
    constexpr uint_t value{0x102030405060708};
    constexpr uint_t expected = []() -> uint_t
    {
        static_assert((eEndian::kNative == eEndian::kLittle) ||
                      (eEndian::kNative == eEndian::kBig));
        if constexpr (eEndian::kNative == eEndian::kLittle)
        {
            return uint_t{0x102030405060708};
        }
        else
        {
            return uint_t{0x807060504030201};
        }
    }();
    constexpr auto result = from_native<eEndian::kLittle>(value);
    static_assert(expected == result);
}

TEST(ConstexprFromNativeUInt64, ToBig)
{
    using uint_t = std::uint64_t;
    constexpr uint_t value{0x102030405060708};
    constexpr uint_t expected = []() -> uint_t
    {
        static_assert((eEndian::kNative == eEndian::kLittle) ||
                      (eEndian::kNative == eEndian::kBig));
        if constexpr (eEndian::kNative == eEndian::kLittle)
        {
            return uint_t{0x807060504030201};
        }
        else
        {
            return uint_t{0x102030405060708};
        }
    }();
    constexpr auto result = from_native<eEndian::kBig>(value);
    static_assert(expected == result);
}

// from native 4 bytes tests

TEST(FromNativeUInt32, ToLittle)
{
    using uint_t = std::uint32_t;
    uint_t value{0x1020304};
    uint_t expected = []() -> uint_t
    {
        static_assert((eEndian::kNative == eEndian::kLittle) ||
                      (eEndian::kNative == eEndian::kBig));
        if constexpr (eEndian::kNative == eEndian::kLittle)
        {
            return uint_t{0x1020304};
        }
        else
        {
            return uint_t{0x4030201};
        }
    }();
    const auto result = from_native<eEndian::kLittle>(value);
    ASSERT_EQ(expected, result);
}

TEST(FromNativeUInt32, ToBig)
{
    using uint_t = std::uint32_t;
    uint_t value{0x1020304};
    uint_t expected = []() -> uint_t
    {
        static_assert((eEndian::kNative == eEndian::kLittle) ||
                      (eEndian::kNative == eEndian::kBig));
        if constexpr (eEndian::kNative == eEndian::kLittle)
        {
            return uint_t{0x4030201};
        }
        else
        {
            return uint_t{0x1020304};
        }
    }();
    const auto result = from_native<eEndian::kBig>(value);
    ASSERT_EQ(expected, result);
}

TEST(ConstexprFromNativeUInt32, ToLittle)
{
    using uint_t = std::uint32_t;
    constexpr uint_t value{0x1020304};
    constexpr uint_t expected = []() -> uint_t
    {
        static_assert((eEndian::kNative == eEndian::kLittle) ||
                      (eEndian::kNative == eEndian::kBig));
        if constexpr (eEndian::kNative == eEndian::kLittle)
        {
            return uint_t{0x1020304};
        }
        else
        {
            return uint_t{0x4030201};
        }
    }();
    constexpr auto result = from_native<eEndian::kLittle>(value);
    static_assert(expected == result);
}

TEST(ConstexprFromNativeUInt32, ToBig)
{
    using uint_t = std::uint32_t;
    constexpr uint_t value{0x1020304};
    constexpr uint_t expected = []() -> uint_t
    {
        static_assert((eEndian::kNative == eEndian::kLittle) ||
                      (eEndian::kNative == eEndian::kBig));
        if constexpr (eEndian::kNative == eEndian::kLittle)
        {
            return uint_t{0x4030201};
        }
        else
        {
            return uint_t{0x1020304};
        }
    }();
    constexpr auto result = from_native<eEndian::kBig>(value);
    static_assert(expected == result);
}

// from native 2 bytes tests

TEST(FromNativeUInt16, ToLittle)
{
    using uint_t = std::uint16_t;
    uint_t value{0x102};
    uint_t expected = []() -> uint_t
    {
        static_assert((eEndian::kNative == eEndian::kLittle) ||
                      (eEndian::kNative == eEndian::kBig));
        if constexpr (eEndian::kNative == eEndian::kLittle)
        {
            return uint_t{0x102};
        }
        else
        {
            return uint_t{0x201};
        }
    }();
    const auto result = from_native<eEndian::kLittle>(value);
    ASSERT_EQ(expected, result);
}

TEST(FromNativeUInt16, ToBig)
{
    using uint_t = std::uint16_t;
    uint_t value{0x102};
    uint_t expected = []() -> uint_t
    {
        static_assert((eEndian::kNative == eEndian::kLittle) ||
                      (eEndian::kNative == eEndian::kBig));
        if constexpr (eEndian::kNative == eEndian::kLittle)
        {
            return uint_t{0x201};
        }
        else
        {
            return uint_t{0x102};
        }
    }();
    const auto result = from_native<eEndian::kBig>(value);
    ASSERT_EQ(expected, result);
}

TEST(ConstexprFromNativeUInt16, ToLittle)
{
    using uint_t = std::uint16_t;
    constexpr uint_t value{0x102};
    constexpr uint_t expected = []() -> uint_t
    {
        static_assert((eEndian::kNative == eEndian::kLittle) ||
                      (eEndian::kNative == eEndian::kBig));
        if constexpr (eEndian::kNative == eEndian::kLittle)
        {
            return uint_t{0x102};
        }
        else
        {
            return uint_t{0x201};
        }
    }();
    constexpr auto result = from_native<eEndian::kLittle>(value);
    static_assert(expected == result);
}

TEST(ConstexprFromNativeUInt16, ToBig)
{
    using uint_t = std::uint16_t;
    constexpr uint_t value{0x102};
    constexpr uint_t expected = []() -> uint_t
    {
        static_assert((eEndian::kNative == eEndian::kLittle) ||
                      (eEndian::kNative == eEndian::kBig));
        if constexpr (eEndian::kNative == eEndian::kLittle)
        {
            return uint_t{0x201};
        }
        else
        {
            return uint_t{0x102};
        }
    }();
    constexpr auto result = from_native<eEndian::kBig>(value);
    static_assert(expected == result);
}

// from native 1 byte tests

TEST(FromNativeUInt8, ToLittle)
{
    using uint_t = std::uint8_t;
    uint_t value{0x1};
    uint_t expected{0x1};
    const auto result = from_native<eEndian::kLittle>(value);
    ASSERT_EQ(expected, result);
}

TEST(FromNativeUInt8, ToBig)
{
    using uint_t = std::uint8_t;
    uint_t value{0x1};
    uint_t expected{0x1};
    const auto result = from_native<eEndian::kBig>(value);
    ASSERT_EQ(expected, result);
}

TEST(ConstexprFromNativeUInt8, ToLittle)
{
    using uint_t = std::uint8_t;
    constexpr uint_t value{0x1};
    constexpr uint_t expected{0x1};
    constexpr auto result = from_native<eEndian::kLittle>(value);
    static_assert(expected == result);
}

TEST(ConstexprFromNativeUInt8, ToBig)
{
    using uint_t = std::uint8_t;
    constexpr uint_t value{0x1};
    constexpr uint_t expected{0x1};
    constexpr auto result = from_native<eEndian::kBig>(value);
    static_assert(expected == result);
}

// to native inplace 8 bytes tests

TEST(ToNativeInplaceUInt64, FromLittle)
{
    using uint_t = std::uint64_t;
    uint_t value{0x102030405060708};
    uint_t expected = []() -> uint_t
    {
        static_assert((eEndian::kNative == eEndian::kLittle) ||
                      (eEndian::kNative == eEndian::kBig));
        if constexpr (eEndian::kNative == eEndian::kLittle)
        {
            return uint_t{0x102030405060708};
        }
        else
        {
            return uint_t{0x807060504030201};
        }
    }();
    to_native_inplace<eEndian::kLittle>(value);
    ASSERT_EQ(expected, value);
}

TEST(ToNativeInplaceUInt64, FromBig)
{
    using uint_t = std::uint64_t;
    uint_t value{0x102030405060708};
    uint_t expected = []() -> uint_t
    {
        static_assert((eEndian::kNative == eEndian::kLittle) ||
                      (eEndian::kNative == eEndian::kBig));
        if constexpr (eEndian::kNative == eEndian::kLittle)
        {
            return uint_t{0x807060504030201};
        }
        else
        {
            return uint_t{0x102030405060708};
        }
    }();
    to_native_inplace<eEndian::kBig>(value);
    ASSERT_EQ(expected, value);
}

TEST(ConstexprToNativeInplaceUInt64, FromLittle)
{
    using uint_t = std::uint64_t;
    constexpr uint_t value{0x102030405060708};
    constexpr uint_t expected = []() -> uint_t
    {
        static_assert((eEndian::kNative == eEndian::kLittle) ||
                      (eEndian::kNative == eEndian::kBig));
        if constexpr (eEndian::kNative == eEndian::kLittle)
        {
            return uint_t{0x102030405060708};
        }
        else
        {
            return uint_t{0x807060504030201};
        }
    }();
    constexpr auto result = [](uint_t aValue)
    {
        to_native_inplace<eEndian::kLittle>(aValue);
        return aValue;
    }(value);
    static_assert(expected == result);
}

TEST(ConstexprToNativeInplaceUInt64, FromBig)
{
    using uint_t = std::uint64_t;
    constexpr uint_t value{0x102030405060708};
    constexpr uint_t expected = []() -> uint_t
    {
        static_assert((eEndian::kNative == eEndian::kLittle) ||
                      (eEndian::kNative == eEndian::kBig));
        if constexpr (eEndian::kNative == eEndian::kLittle)
        {
            return uint_t{0x807060504030201};
        }
        else
        {
            return uint_t{0x102030405060708};
        }
    }();
    constexpr auto result = [](uint_t aValue)
    {
        to_native_inplace<eEndian::kBig>(aValue);
        return aValue;
    }(value);
    static_assert(expected == result);
}

// to native inplace 4 bytes tests

TEST(ToNativeInplaceUInt32, FromLittle)
{
    using uint_t = std::uint32_t;
    uint_t value{0x1020304};
    uint_t expected = []() -> uint_t
    {
        static_assert((eEndian::kNative == eEndian::kLittle) ||
                      (eEndian::kNative == eEndian::kBig));
        if constexpr (eEndian::kNative == eEndian::kLittle)
        {
            return uint_t{0x1020304};
        }
        else
        {
            return uint_t{0x4030201};
        }
    }();
    to_native_inplace<eEndian::kLittle>(value);
    ASSERT_EQ(expected, value);
}

TEST(ToNativeInplaceUInt32, FromBig)
{
    using uint_t = std::uint32_t;
    uint_t value{0x1020304};
    uint_t expected = []() -> uint_t
    {
        static_assert((eEndian::kNative == eEndian::kLittle) ||
                      (eEndian::kNative == eEndian::kBig));
        if constexpr (eEndian::kNative == eEndian::kLittle)
        {
            return uint_t{0x4030201};
        }
        else
        {
            return uint_t{0x1020304};
        }
    }();
    to_native_inplace<eEndian::kBig>(value);
    ASSERT_EQ(expected, value);
}

TEST(ConstexprToNativeInplaceUInt32, FromLittle)
{
    using uint_t = std::uint32_t;
    constexpr uint_t value{0x1020304};
    constexpr uint_t expected = []() -> uint_t
    {
        static_assert((eEndian::kNative == eEndian::kLittle) ||
                      (eEndian::kNative == eEndian::kBig));
        if constexpr (eEndian::kNative == eEndian::kLittle)
        {
            return uint_t{0x1020304};
        }
        else
        {
            return uint_t{0x4030201};
        }
    }();
    constexpr auto result = [](uint_t aValue)
    {
        to_native_inplace<eEndian::kLittle>(aValue);
        return aValue;
    }(value);
    static_assert(expected == result);
}

TEST(ConstexprToNativeInplaceUInt32, FromBig)
{
    using uint_t = std::uint32_t;
    constexpr uint_t value{0x1020304};
    constexpr uint_t expected = []() -> uint_t
    {
        static_assert((eEndian::kNative == eEndian::kLittle) ||
                      (eEndian::kNative == eEndian::kBig));
        if constexpr (eEndian::kNative == eEndian::kLittle)
        {
            return uint_t{0x4030201};
        }
        else
        {
            return uint_t{0x1020304};
        }
    }();
    constexpr auto result = [](uint_t aValue)
    {
        to_native_inplace<eEndian::kBig>(aValue);
        return aValue;
    }(value);
    static_assert(expected == result);
}

// to native inplace 2 bytes tests

TEST(ToNativeInplaceUInt16, FromLittle)
{
    using uint_t = std::uint16_t;
    uint_t value{0x102};
    uint_t expected = []() -> uint_t
    {
        static_assert((eEndian::kNative == eEndian::kLittle) ||
                      (eEndian::kNative == eEndian::kBig));
        if constexpr (eEndian::kNative == eEndian::kLittle)
        {
            return uint_t{0x102};
        }
        else
        {
            return uint_t{0x201};
        }
    }();
    to_native_inplace<eEndian::kLittle>(value);
    ASSERT_EQ(expected, value);
}

TEST(ToNativeInplaceUInt16, FromBig)
{
    using uint_t = std::uint16_t;
    uint_t value{0x102};
    uint_t expected = []() -> uint_t
    {
        static_assert((eEndian::kNative == eEndian::kLittle) ||
                      (eEndian::kNative == eEndian::kBig));
        if constexpr (eEndian::kNative == eEndian::kLittle)
        {
            return uint_t{0x201};
        }
        else
        {
            return uint_t{0x102};
        }
    }();
    to_native_inplace<eEndian::kBig>(value);
    ASSERT_EQ(expected, value);
}

TEST(ConstexprToNativeInplaceUInt16, FromLittle)
{
    using uint_t = std::uint16_t;
    constexpr uint_t value{0x102};
    constexpr uint_t expected = []() -> uint_t
    {
        static_assert((eEndian::kNative == eEndian::kLittle) ||
                      (eEndian::kNative == eEndian::kBig));
        if constexpr (eEndian::kNative == eEndian::kLittle)
        {
            return uint_t{0x102};
        }
        else
        {
            return uint_t{0x201};
        }
    }();
    constexpr auto result = [](uint_t aValue)
    {
        to_native_inplace<eEndian::kLittle>(aValue);
        return aValue;
    }(value);
    static_assert(expected == result);
}

TEST(ConstexprToNativeInplaceUInt16, FromBig)
{
    using uint_t = std::uint16_t;
    constexpr uint_t value{0x102};
    constexpr uint_t expected = []() -> uint_t
    {
        static_assert((eEndian::kNative == eEndian::kLittle) ||
                      (eEndian::kNative == eEndian::kBig));
        if constexpr (eEndian::kNative == eEndian::kLittle)
        {
            return uint_t{0x201};
        }
        else
        {
            return uint_t{0x102};
        }
    }();
    constexpr auto result = [](uint_t aValue)
    {
        to_native_inplace<eEndian::kBig>(aValue);
        return aValue;
    }(value);
    static_assert(expected == result);
}

// to native inplace 1 byte tests

TEST(ToNativeInplaceUInt8, FromLittle)
{
    using uint_t = std::uint8_t;
    uint_t value{0x1};
    uint_t expected{0x1};
    to_native_inplace<eEndian::kLittle>(value);
    ASSERT_EQ(expected, value);
}

TEST(ToNativeInplaceUInt8, FromBig)
{
    using uint_t = std::uint8_t;
    uint_t value{0x1};
    uint_t expected{0x1};
    to_native_inplace<eEndian::kBig>(value);
    ASSERT_EQ(expected, value);
}

TEST(ConstexprToNativeInplaceUInt8, FromLittle)
{
    using uint_t = std::uint8_t;
    constexpr uint_t value{0x1};
    constexpr uint_t expected{0x1};
    constexpr auto result = [](uint_t aValue)
    {
        to_native_inplace<eEndian::kLittle>(aValue);
        return aValue;
    }(value);
    static_assert(expected == result);
}

TEST(ConstexprToNativeInplaceUInt8, FromBig)
{
    using uint_t = std::uint8_t;
    constexpr uint_t value{0x1};
    constexpr uint_t expected{0x1};
    constexpr auto result = [](uint_t aValue)
    {
        to_native_inplace<eEndian::kBig>(aValue);
        return aValue;
    }(value);
    static_assert(expected == result);
}

// from native inplace 8 bytes tests

TEST(FromNativeInplaceUInt64, ToLittle)
{
    using uint_t = std::uint64_t;
    uint_t value{0x102030405060708};
    uint_t expected = []() -> uint_t
    {
        static_assert((eEndian::kNative == eEndian::kLittle) ||
                      (eEndian::kNative == eEndian::kBig));
        if constexpr (eEndian::kNative == eEndian::kLittle)
        {
            return uint_t{0x102030405060708};
        }
        else
        {
            return uint_t{0x807060504030201};
        }
    }();
    from_native_inplace<eEndian::kLittle>(value);
    ASSERT_EQ(expected, value);
}

TEST(FromNativeInplaceUInt64, ToBig)
{
    using uint_t = std::uint64_t;
    uint_t value{0x102030405060708};
    uint_t expected = []() -> uint_t
    {
        static_assert((eEndian::kNative == eEndian::kLittle) ||
                      (eEndian::kNative == eEndian::kBig));
        if constexpr (eEndian::kNative == eEndian::kLittle)
        {
            return uint_t{0x807060504030201};
        }
        else
        {
            return uint_t{0x102030405060708};
        }
    }();
    from_native_inplace<eEndian::kBig>(value);
    ASSERT_EQ(expected, value);
}

TEST(ConstexprFromNativeInplaceUInt64, ToLittle)
{
    using uint_t = std::uint64_t;
    constexpr uint_t value{0x102030405060708};
    constexpr uint_t expected = []() -> uint_t
    {
        static_assert((eEndian::kNative == eEndian::kLittle) ||
                      (eEndian::kNative == eEndian::kBig));
        if constexpr (eEndian::kNative == eEndian::kLittle)
        {
            return uint_t{0x102030405060708};
        }
        else
        {
            return uint_t{0x807060504030201};
        }
    }();
    constexpr auto result = [](uint_t aValue)
    {
        from_native_inplace<eEndian::kLittle>(aValue);
        return aValue;
    }(value);
    static_assert(expected == result);
}

TEST(ConstexprFromNativeInplaceUInt64, ToBig)
{
    using uint_t = std::uint64_t;
    constexpr uint_t value{0x102030405060708};
    constexpr uint_t expected = []() -> uint_t
    {
        static_assert((eEndian::kNative == eEndian::kLittle) ||
                      (eEndian::kNative == eEndian::kBig));
        if constexpr (eEndian::kNative == eEndian::kLittle)
        {
            return uint_t{0x807060504030201};
        }
        else
        {
            return uint_t{0x102030405060708};
        }
    }();
    constexpr auto result = [](uint_t aValue)
    {
        from_native_inplace<eEndian::kBig>(aValue);
        return aValue;
    }(value);
    static_assert(expected == result);
}

// from native inplace 4 bytes tests

TEST(FromNativeInplaceUInt32, ToLittle)
{
    using uint_t = std::uint32_t;
    uint_t value{0x1020304};
    uint_t expected = []() -> uint_t
    {
        static_assert((eEndian::kNative == eEndian::kLittle) ||
                      (eEndian::kNative == eEndian::kBig));
        if constexpr (eEndian::kNative == eEndian::kLittle)
        {
            return uint_t{0x1020304};
        }
        else
        {
            return uint_t{0x4030201};
        }
    }();
    from_native_inplace<eEndian::kLittle>(value);
    ASSERT_EQ(expected, value);
}

TEST(FromNativeInplaceUInt32, ToBig)
{
    using uint_t = std::uint32_t;
    uint_t value{0x1020304};
    uint_t expected = []() -> uint_t
    {
        static_assert((eEndian::kNative == eEndian::kLittle) ||
                      (eEndian::kNative == eEndian::kBig));
        if constexpr (eEndian::kNative == eEndian::kLittle)
        {
            return uint_t{0x4030201};
        }
        else
        {
            return uint_t{0x1020304};
        }
    }();
    from_native_inplace<eEndian::kBig>(value);
    ASSERT_EQ(expected, value);
}

TEST(ConstexprFromNativeInplaceUInt32, ToLittle)
{
    using uint_t = std::uint32_t;
    constexpr uint_t value{0x1020304};
    constexpr uint_t expected = []() -> uint_t
    {
        static_assert((eEndian::kNative == eEndian::kLittle) ||
                      (eEndian::kNative == eEndian::kBig));
        if constexpr (eEndian::kNative == eEndian::kLittle)
        {
            return uint_t{0x1020304};
        }
        else
        {
            return uint_t{0x4030201};
        }
    }();
    constexpr auto result = [](uint_t aValue)
    {
        from_native_inplace<eEndian::kLittle>(aValue);
        return aValue;
    }(value);
    static_assert(expected == result);
}

TEST(ConstexprFromNativeInplaceUInt32, ToBig)
{
    using uint_t = std::uint32_t;
    constexpr uint_t value{0x1020304};
    constexpr uint_t expected = []() -> uint_t
    {
        static_assert((eEndian::kNative == eEndian::kLittle) ||
                      (eEndian::kNative == eEndian::kBig));
        if constexpr (eEndian::kNative == eEndian::kLittle)
        {
            return uint_t{0x4030201};
        }
        else
        {
            return uint_t{0x1020304};
        }
    }();
    constexpr auto result = [](uint_t aValue)
    {
        from_native_inplace<eEndian::kBig>(aValue);
        return aValue;
    }(value);
    static_assert(expected == result);
}

// from native inplace 2 bytes tests

TEST(FromNativeInplaceUInt16, ToLittle)
{
    using uint_t = std::uint16_t;
    uint_t value{0x102};
    uint_t expected = []() -> uint_t
    {
        static_assert((eEndian::kNative == eEndian::kLittle) ||
                      (eEndian::kNative == eEndian::kBig));
        if constexpr (eEndian::kNative == eEndian::kLittle)
        {
            return uint_t{0x102};
        }
        else
        {
            return uint_t{0x201};
        }
    }();
    from_native_inplace<eEndian::kLittle>(value);
    ASSERT_EQ(expected, value);
}

TEST(FromNativeInplaceUInt16, ToBig)
{
    using uint_t = std::uint16_t;
    uint_t value{0x102};
    uint_t expected = []() -> uint_t
    {
        static_assert((eEndian::kNative == eEndian::kLittle) ||
                      (eEndian::kNative == eEndian::kBig));
        if constexpr (eEndian::kNative == eEndian::kLittle)
        {
            return uint_t{0x201};
        }
        else
        {
            return uint_t{0x102};
        }
    }();
    from_native_inplace<eEndian::kBig>(value);
    ASSERT_EQ(expected, value);
}

TEST(ConstexprFromNativeInplaceUInt16, ToLittle)
{
    using uint_t = std::uint16_t;
    constexpr uint_t value{0x102};
    constexpr uint_t expected = []() -> uint_t
    {
        static_assert((eEndian::kNative == eEndian::kLittle) ||
                      (eEndian::kNative == eEndian::kBig));
        if constexpr (eEndian::kNative == eEndian::kLittle)
        {
            return uint_t{0x102};
        }
        else
        {
            return uint_t{0x201};
        }
    }();
    constexpr auto result = [](uint_t aValue)
    {
        from_native_inplace<eEndian::kLittle>(aValue);
        return aValue;
    }(value);
    static_assert(expected == result);
}

TEST(ConstexprFromNativeInplaceUInt16, ToBig)
{
    using uint_t = std::uint16_t;
    constexpr uint_t value{0x102};
    constexpr uint_t expected = []() -> uint_t
    {
        static_assert((eEndian::kNative == eEndian::kLittle) ||
                      (eEndian::kNative == eEndian::kBig));
        if constexpr (eEndian::kNative == eEndian::kLittle)
        {
            return uint_t{0x201};
        }
        else
        {
            return uint_t{0x102};
        }
    }();
    constexpr auto result = [](uint_t aValue)
    {
        from_native_inplace<eEndian::kBig>(aValue);
        return aValue;
    }(value);
    static_assert(expected == result);
}

// from native inplace 1 byte tests

TEST(FromNativeInplaceUInt8, ToLittle)
{
    using uint_t = std::uint8_t;
    uint_t value{0x1};
    uint_t expected{0x1};
    from_native_inplace<eEndian::kLittle>(value);
    ASSERT_EQ(expected, value);
}

TEST(FromNativeInplaceUInt8, ToBig)
{
    using uint_t = std::uint8_t;
    uint_t value{0x1};
    uint_t expected{0x1};
    from_native_inplace<eEndian::kBig>(value);
    ASSERT_EQ(expected, value);
}

TEST(ConstexprFromNativeInplaceUInt8, ToLittle)
{
    using uint_t = std::uint8_t;
    constexpr uint_t value{0x1};
    constexpr uint_t expected{0x1};
    constexpr auto result = [](uint_t aValue)
    {
        from_native_inplace<eEndian::kLittle>(aValue);
        return aValue;
    }(value);
    static_assert(expected == result);
}

TEST(ConstexprFromNativeInplaceUInt8, ToBig)
{
    using uint_t = std::uint8_t;
    constexpr uint_t value{0x1};
    constexpr uint_t expected{0x1};
    constexpr auto result = [](uint_t aValue)
    {
        from_native_inplace<eEndian::kBig>(aValue);
        return aValue;
    }(value);
    static_assert(expected == result);
}
