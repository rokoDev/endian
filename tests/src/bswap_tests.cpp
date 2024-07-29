#include <endian/endian.h>
#include <gtest/gtest.h>

TEST(BSwap, OneByte)
{
    std::uint8_t value{0x1};
    std::uint8_t expected{0x1};
    ASSERT_EQ(expected, endian::bswap(value));
}

TEST(BSwap, TwoBytes)
{
    std::uint16_t value{0x102};
    std::uint16_t expected{0x201};
    ASSERT_EQ(expected, endian::bswap(value));
}

TEST(BSwap, FourBytes)
{
    std::uint32_t value{0x1020304};
    std::uint32_t expected{0x4030201};
    ASSERT_EQ(expected, endian::bswap(value));
}

TEST(BSwap, EightBytes)
{
    std::uint64_t value{0x102030405060708};
    std::uint64_t expected{0x807060504030201};
    ASSERT_EQ(expected, endian::bswap(value));
}

TEST(ConstexprBSwap, OneByte)
{
    constexpr std::uint8_t value{0x1};
    constexpr std::uint8_t expected{0x1};
    static_assert(expected == endian::bswap(value));
}

TEST(ConstexprBSwap, TwoBytes)
{
    constexpr std::uint16_t value{0x102};
    constexpr std::uint16_t expected{0x201};
    static_assert(expected == endian::bswap(value));
}

TEST(ConstexprBSwap, FourBytes)
{
    constexpr std::uint32_t value{0x1020304};
    constexpr std::uint32_t expected{0x4030201};
    static_assert(expected == endian::bswap(value));
}

TEST(ConstexprBSwap, EightBytes)
{
    constexpr std::uint64_t value{0x102030405060708};
    constexpr std::uint64_t expected{0x807060504030201};
    static_assert(expected == endian::bswap(value));
}
