#include <endian/endian.h>
#include <gtest/gtest.h>

#include <array>

#include "test_helpers.h"

using namespace endian;

template <typename T, std::size_t NBytes>
class load_template : public ::testing::Test
{
   protected:
    using uint_t = std::enable_if_t<
        (NBytes > 0) && (NBytes <= sizeof(T)) &&
            std::disjunction_v<
                std::is_same<T, std::uint8_t>, std::is_same<T, std::uint16_t>,
                std::is_same<T, std::uint32_t>, std::is_same<T, std::uint64_t>>,
        T>;
    using buffer_t = std::array<std::byte, NBytes>;
    inline static constexpr std::size_t N = NBytes;

    template <std::size_t... I>
    static constexpr buffer_t create_byte_array(
        std::index_sequence<I...>) noexcept
    {
        return {std::byte{I + 1}...};
    }

    static constexpr buffer_t buf_arr{
        create_byte_array(std::make_index_sequence<NBytes>{})};
    static constexpr std::byte const* buffer = buf_arr.data();
    //    inline static
};

// load std::uint8_t
using LoadUInt8From1Byte = load_template<std::uint8_t, 1>;
TEST_F(LoadUInt8From1Byte, FromLittle)
{
    uint_t expected{0x1};
    uint_t result = load<uint_t, eEndian::kLittle, N>(buffer);
    ASSERT_EQ(expected, result);
}

TEST_F(LoadUInt8From1Byte, ConstexprFromLittle)
{
    constexpr uint_t expected{0x1};
    constexpr uint_t result = load<uint_t, eEndian::kLittle, N>(buffer);
    static_assert(expected == result);
}

TEST_F(LoadUInt8From1Byte, FromBig)
{
    uint_t expected{0x1};
    uint_t result = load<uint_t, eEndian::kBig, N>(buffer);
    ASSERT_EQ(expected, result);
}

TEST_F(LoadUInt8From1Byte, ConstexprFromBig)
{
    constexpr uint_t expected{0x1};
    constexpr uint_t result = load<uint_t, eEndian::kBig, N>(buffer);
    static_assert(expected == result);
}

// load std::uint16_t
using LoadUInt16From1Byte = load_template<std::uint16_t, 1>;
TEST_F(LoadUInt16From1Byte, FromLittle)
{
    uint_t expected{0x1};
    uint_t result = load<uint_t, eEndian::kLittle, N>(buffer);
    ASSERT_EQ(expected, result);
}

TEST_F(LoadUInt16From1Byte, ConstexprFromLittle)
{
    constexpr uint_t expected{0x1};
    constexpr uint_t result = load<uint_t, eEndian::kLittle, N>(buffer);
    static_assert(expected == result);
}

TEST_F(LoadUInt16From1Byte, FromBig)
{
    uint_t expected{0x1};
    uint_t result = load<uint_t, eEndian::kBig, N>(buffer);
    ASSERT_EQ(expected, result);
}

TEST_F(LoadUInt16From1Byte, ConstexprFromBig)
{
    constexpr uint_t expected{0x1};
    constexpr uint_t result = load<uint_t, eEndian::kBig, N>(buffer);
    static_assert(expected == result);
}

using LoadUInt16From2Bytes = load_template<std::uint16_t, 2>;
TEST_F(LoadUInt16From2Bytes, FromLittle)
{
    uint_t expected = {0x201};
    uint_t result = load<uint_t, eEndian::kLittle, N>(buffer);
    ASSERT_EQ(expected, result);
}

TEST_F(LoadUInt16From2Bytes, ConstexprFromLittle)
{
    constexpr uint_t expected = {0x201};
    constexpr uint_t result = load<uint_t, eEndian::kLittle, N>(buffer);
    static_assert(expected == result);
}

TEST_F(LoadUInt16From2Bytes, FromBig)
{
    uint_t expected = uint_t{0x102};
    uint_t result = load<uint_t, eEndian::kBig, N>(buffer);
    ASSERT_EQ(expected, result);
}

TEST_F(LoadUInt16From2Bytes, ConstexprFromBig)
{
    constexpr uint_t expected = uint_t{0x102};
    constexpr uint_t result = load<uint_t, eEndian::kBig, N>(buffer);
    static_assert(expected == result);
}

// load std::uint32_t
using LoadUInt32From1Byte = load_template<std::uint32_t, 1>;
TEST_F(LoadUInt32From1Byte, FromLittle)
{
    uint_t expected{0x1};
    uint_t result = load<uint_t, eEndian::kLittle, N>(buffer);
    ASSERT_EQ(expected, result);
}

TEST_F(LoadUInt32From1Byte, ConstexprFromLittle)
{
    constexpr uint_t expected{0x1};
    constexpr uint_t result = load<uint_t, eEndian::kLittle, N>(buffer);
    static_assert(expected == result);
}

TEST_F(LoadUInt32From1Byte, FromBig)
{
    uint_t expected{0x1};
    uint_t result = load<uint_t, eEndian::kBig, N>(buffer);
    ASSERT_EQ(expected, result);
}

TEST_F(LoadUInt32From1Byte, ConstexprFromBig)
{
    constexpr uint_t expected{0x1};
    constexpr uint_t result = load<uint_t, eEndian::kBig, N>(buffer);
    static_assert(expected == result);
}

using LoadUInt32From2Bytes = load_template<std::uint32_t, 2>;
TEST_F(LoadUInt32From2Bytes, FromLittle)
{
    uint_t expected = {0x201};
    uint_t result = load<uint_t, eEndian::kLittle, N>(buffer);
    ASSERT_EQ(expected, result);
}

TEST_F(LoadUInt32From2Bytes, ConstexprFromLittle)
{
    constexpr uint_t expected = {0x201};
    constexpr uint_t result = load<uint_t, eEndian::kLittle, N>(buffer);
    static_assert(expected == result);
}

TEST_F(LoadUInt32From2Bytes, FromBig)
{
    uint_t expected = uint_t{0x102};
    uint_t result = load<uint_t, eEndian::kBig, N>(buffer);
    ASSERT_EQ(expected, result);
}

TEST_F(LoadUInt32From2Bytes, ConstexprFromBig)
{
    constexpr uint_t expected = uint_t{0x102};
    constexpr uint_t result = load<uint_t, eEndian::kBig, N>(buffer);
    static_assert(expected == result);
}

using LoadUInt32From3Bytes = load_template<std::uint32_t, 3>;
TEST_F(LoadUInt32From3Bytes, FromLittle)
{
    uint_t expected = {0x30201};
    uint_t result = load<uint_t, eEndian::kLittle, N>(buffer);
    ASSERT_EQ(expected, result);
}

TEST_F(LoadUInt32From3Bytes, ConstexprFromLittle)
{
    constexpr uint_t expected = {0x30201};
    constexpr uint_t result = load<uint_t, eEndian::kLittle, N>(buffer);
    static_assert(expected == result);
}

TEST_F(LoadUInt32From3Bytes, FromBig)
{
    uint_t expected = uint_t{0x10203};
    uint_t result = load<uint_t, eEndian::kBig, N>(buffer);
    ASSERT_EQ(expected, result);
}

TEST_F(LoadUInt32From3Bytes, ConstexprFromBig)
{
    constexpr uint_t expected = uint_t{0x10203};
    constexpr uint_t result = load<uint_t, eEndian::kBig, N>(buffer);
    static_assert(expected == result);
}

using LoadUInt32From4Bytes = load_template<std::uint32_t, 4>;
TEST_F(LoadUInt32From4Bytes, FromLittle)
{
    uint_t expected = {0x4030201};
    uint_t result = load<uint_t, eEndian::kLittle, N>(buffer);
    ASSERT_EQ(expected, result);
}

TEST_F(LoadUInt32From4Bytes, ConstexprFromLittle)
{
    constexpr uint_t expected = {0x4030201};
    constexpr uint_t result = load<uint_t, eEndian::kLittle, N>(buffer);
    static_assert(expected == result);
}

TEST_F(LoadUInt32From4Bytes, FromBig)
{
    uint_t expected = uint_t{0x1020304};
    uint_t result = load<uint_t, eEndian::kBig, N>(buffer);
    ASSERT_EQ(expected, result);
}

TEST_F(LoadUInt32From4Bytes, ConstexprFromBig)
{
    constexpr uint_t expected = uint_t{0x1020304};
    constexpr uint_t result = load<uint_t, eEndian::kBig, N>(buffer);
    static_assert(expected == result);
}

// load std::uint64_t
using LoadUInt64From1Byte = load_template<std::uint64_t, 1>;
TEST_F(LoadUInt64From1Byte, FromLittle)
{
    uint_t expected{0x1};
    uint_t result = load<uint_t, eEndian::kLittle, N>(buffer);
    ASSERT_EQ(expected, result);
}

TEST_F(LoadUInt64From1Byte, ConstexprFromLittle)
{
    constexpr uint_t expected{0x1};
    constexpr uint_t result = load<uint_t, eEndian::kLittle, N>(buffer);
    static_assert(expected == result);
}

TEST_F(LoadUInt64From1Byte, FromBig)
{
    uint_t expected{0x1};
    uint_t result = load<uint_t, eEndian::kBig, N>(buffer);
    ASSERT_EQ(expected, result);
}

TEST_F(LoadUInt64From1Byte, ConstexprFromBig)
{
    constexpr uint_t expected{0x1};
    constexpr uint_t result = load<uint_t, eEndian::kBig, N>(buffer);
    static_assert(expected == result);
}

using LoadUInt64From2Bytes = load_template<std::uint64_t, 2>;
TEST_F(LoadUInt64From2Bytes, FromLittle)
{
    uint_t expected = {0x201};
    uint_t result = load<uint_t, eEndian::kLittle, N>(buffer);
    ASSERT_EQ(expected, result);
}

TEST_F(LoadUInt64From2Bytes, ConstexprFromLittle)
{
    constexpr uint_t expected = {0x201};
    constexpr uint_t result = load<uint_t, eEndian::kLittle, N>(buffer);
    static_assert(expected == result);
}

TEST_F(LoadUInt64From2Bytes, FromBig)
{
    uint_t expected = uint_t{0x102};
    uint_t result = load<uint_t, eEndian::kBig, N>(buffer);
    ASSERT_EQ(expected, result);
}

TEST_F(LoadUInt64From2Bytes, ConstexprFromBig)
{
    constexpr uint_t expected = uint_t{0x102};
    constexpr uint_t result = load<uint_t, eEndian::kBig, N>(buffer);
    static_assert(expected == result);
}

using LoadUInt64From3Bytes = load_template<std::uint64_t, 3>;
TEST_F(LoadUInt64From3Bytes, FromLittle)
{
    uint_t expected = {0x30201};
    uint_t result = load<uint_t, eEndian::kLittle, N>(buffer);
    ASSERT_EQ(expected, result);
}

TEST_F(LoadUInt64From3Bytes, ConstexprFromLittle)
{
    constexpr uint_t expected = {0x30201};
    constexpr uint_t result = load<uint_t, eEndian::kLittle, N>(buffer);
    static_assert(expected == result);
}

TEST_F(LoadUInt64From3Bytes, FromBig)
{
    uint_t expected = uint_t{0x10203};
    uint_t result = load<uint_t, eEndian::kBig, N>(buffer);
    ASSERT_EQ(expected, result);
}

TEST_F(LoadUInt64From3Bytes, ConstexprFromBig)
{
    constexpr uint_t expected = uint_t{0x10203};
    constexpr uint_t result = load<uint_t, eEndian::kBig, N>(buffer);
    static_assert(expected == result);
}

using LoadUInt64From4Bytes = load_template<std::uint64_t, 4>;
TEST_F(LoadUInt64From4Bytes, FromLittle)
{
    uint_t expected = {0x4030201};
    uint_t result = load<uint_t, eEndian::kLittle, N>(buffer);
    ASSERT_EQ(expected, result);
}

TEST_F(LoadUInt64From4Bytes, ConstexprFromLittle)
{
    constexpr uint_t expected = {0x4030201};
    constexpr uint_t result = load<uint_t, eEndian::kLittle, N>(buffer);
    static_assert(expected == result);
}

TEST_F(LoadUInt64From4Bytes, FromBig)
{
    uint_t expected = uint_t{0x1020304};
    uint_t result = load<uint_t, eEndian::kBig, N>(buffer);
    ASSERT_EQ(expected, result);
}

TEST_F(LoadUInt64From4Bytes, ConstexprFromBig)
{
    constexpr uint_t expected = uint_t{0x1020304};
    constexpr uint_t result = load<uint_t, eEndian::kBig, N>(buffer);
    static_assert(expected == result);
}

using LoadUInt64From5Bytes = load_template<std::uint64_t, 5>;
TEST_F(LoadUInt64From5Bytes, FromLittle)
{
    uint_t expected = {0x504030201};
    uint_t result = load<uint_t, eEndian::kLittle, N>(buffer);
    ASSERT_EQ(expected, result);
}

TEST_F(LoadUInt64From5Bytes, ConstexprFromLittle)
{
    constexpr uint_t expected = {0x504030201};
    constexpr uint_t result = load<uint_t, eEndian::kLittle, N>(buffer);
    static_assert(expected == result);
}

TEST_F(LoadUInt64From5Bytes, FromBig)
{
    uint_t expected = uint_t{0x102030405};
    uint_t result = load<uint_t, eEndian::kBig, N>(buffer);
    ASSERT_EQ(expected, result);
}

TEST_F(LoadUInt64From5Bytes, ConstexprFromBig)
{
    constexpr uint_t expected = uint_t{0x102030405};
    constexpr uint_t result = load<uint_t, eEndian::kBig, N>(buffer);
    static_assert(expected == result);
}

using LoadUInt64From6Bytes = load_template<std::uint64_t, 6>;
TEST_F(LoadUInt64From6Bytes, FromLittle)
{
    uint_t expected = {0x60504030201};
    uint_t result = load<uint_t, eEndian::kLittle, N>(buffer);
    ASSERT_EQ(expected, result);
}

TEST_F(LoadUInt64From6Bytes, ConstexprFromLittle)
{
    constexpr uint_t expected = {0x60504030201};
    constexpr uint_t result = load<uint_t, eEndian::kLittle, N>(buffer);
    static_assert(expected == result);
}

TEST_F(LoadUInt64From6Bytes, FromBig)
{
    uint_t expected = uint_t{0x10203040506};
    uint_t result = load<uint_t, eEndian::kBig, N>(buffer);
    ASSERT_EQ(expected, result);
}

TEST_F(LoadUInt64From6Bytes, ConstexprFromBig)
{
    constexpr uint_t expected = uint_t{0x10203040506};
    constexpr uint_t result = load<uint_t, eEndian::kBig, N>(buffer);
    static_assert(expected == result);
}

using LoadUInt64From7Bytes = load_template<std::uint64_t, 7>;
TEST_F(LoadUInt64From7Bytes, FromLittle)
{
    uint_t expected = {0x7060504030201};
    uint_t result = load<uint_t, eEndian::kLittle, N>(buffer);
    ASSERT_EQ(expected, result);
}

TEST_F(LoadUInt64From7Bytes, ConstexprFromLittle)
{
    constexpr uint_t expected = {0x7060504030201};
    constexpr uint_t result = load<uint_t, eEndian::kLittle, N>(buffer);
    static_assert(expected == result);
}

TEST_F(LoadUInt64From7Bytes, FromBig)
{
    uint_t expected = uint_t{0x1020304050607};
    uint_t result = load<uint_t, eEndian::kBig, N>(buffer);
    ASSERT_EQ(expected, result);
}

TEST_F(LoadUInt64From7Bytes, ConstexprFromBig)
{
    constexpr uint_t expected = uint_t{0x1020304050607};
    constexpr uint_t result = load<uint_t, eEndian::kBig, N>(buffer);
    static_assert(expected == result);
}

using LoadUInt64From8Bytes = load_template<std::uint64_t, 8>;
TEST_F(LoadUInt64From8Bytes, FromLittle)
{
    uint_t expected = {0x807060504030201};
    uint_t result = load<uint_t, eEndian::kLittle, N>(buffer);
    ASSERT_EQ(expected, result);
}

TEST_F(LoadUInt64From8Bytes, ConstexprFromLittle)
{
    constexpr uint_t expected = {0x807060504030201};
    constexpr uint_t result = load<uint_t, eEndian::kLittle, N>(buffer);
    static_assert(expected == result);
}

TEST_F(LoadUInt64From8Bytes, FromBig)
{
    uint_t expected = uint_t{0x102030405060708};
    uint_t result = load<uint_t, eEndian::kBig, N>(buffer);
    ASSERT_EQ(expected, result);
}

TEST_F(LoadUInt64From8Bytes, ConstexprFromBig)
{
    constexpr uint_t expected = uint_t{0x102030405060708};
    constexpr uint_t result = load<uint_t, eEndian::kBig, N>(buffer);
    static_assert(expected == result);
}

using LoadUInt64WithNParam = LoadUInt64From8Bytes;
TEST_F(LoadUInt64WithNParam, FromLittle)
{
    using val_array = std::array<uint_t, sizeof(uint_t)>;
    val_array expected{
        0x1,         0x201,         0x30201,         0x4030201,
        0x504030201, 0x60504030201, 0x7060504030201, 0x807060504030201};

    val_array result;
    for (std::size_t i = 0; i < sizeof(uint_t); ++i)
    {
        result[i] = load<uint_t, eEndian::kLittle>(buffer, i + 1);
    }
    ASSERT_EQ(expected, result);
}

TEST_F(LoadUInt64WithNParam, ConstexprFromLittle)
{
    using val_array = std::array<uint_t, sizeof(uint_t)>;
    constexpr val_array expected{
        0x1,         0x201,         0x30201,         0x4030201,
        0x504030201, 0x60504030201, 0x7060504030201, 0x807060504030201};

    constexpr val_array result = [](auto buf)
    {
        val_array tmp{};
        for (std::size_t i = 0; i < sizeof(uint_t); ++i)
        {
            tmp[i] = load<uint_t, eEndian::kLittle>(buf, i + 1);
        }
        return tmp;
    }(buffer);

    static_assert(is_equal_arrays(expected, result));
}

TEST_F(LoadUInt64WithNParam, FromBig)
{
    using val_array = std::array<uint_t, sizeof(uint_t)>;
    val_array expected{
        0x1,         0x102,         0x10203,         0x1020304,
        0x102030405, 0x10203040506, 0x1020304050607, 0x102030405060708};

    val_array result;
    for (std::size_t i = 0; i < sizeof(uint_t); ++i)
    {
        result[i] = load<uint_t, eEndian::kBig>(buffer, i + 1);
    }
    ASSERT_EQ(expected, result);
}

TEST_F(LoadUInt64WithNParam, ConstexprFromBig)
{
    using val_array = std::array<uint_t, sizeof(uint_t)>;
    constexpr val_array expected{
        0x1,         0x102,         0x10203,         0x1020304,
        0x102030405, 0x10203040506, 0x1020304050607, 0x102030405060708};

    constexpr val_array result = [](auto buf)
    {
        val_array tmp{};
        for (std::size_t i = 0; i < sizeof(uint_t); ++i)
        {
            tmp[i] = load<uint_t, eEndian::kBig>(buf, i + 1);
        }
        return tmp;
    }(buffer);

    static_assert(is_equal_arrays(expected, result));
}

using LoadUInt32WithNParam = LoadUInt32From4Bytes;
TEST_F(LoadUInt32WithNParam, FromLittle)
{
    using val_array = std::array<uint_t, sizeof(uint_t)>;
    val_array expected{0x1, 0x201, 0x30201, 0x4030201};

    val_array result;
    for (std::size_t i = 0; i < sizeof(uint_t); ++i)
    {
        result[i] = load<uint_t, eEndian::kLittle>(buffer, i + 1);
    }
    ASSERT_EQ(expected, result);
}

TEST_F(LoadUInt32WithNParam, ConstexprFromLittle)
{
    using val_array = std::array<uint_t, sizeof(uint_t)>;
    constexpr val_array expected{0x1, 0x201, 0x30201, 0x4030201};

    constexpr val_array result = [](auto buf)
    {
        val_array tmp{};
        for (std::size_t i = 0; i < sizeof(uint_t); ++i)
        {
            tmp[i] = load<uint_t, eEndian::kLittle>(buf, i + 1);
        }
        return tmp;
    }(buffer);

    static_assert(is_equal_arrays(expected, result));
}

TEST_F(LoadUInt32WithNParam, FromBig)
{
    using val_array = std::array<uint_t, sizeof(uint_t)>;
    val_array expected{0x1, 0x102, 0x10203, 0x1020304};

    val_array result;
    for (std::size_t i = 0; i < sizeof(uint_t); ++i)
    {
        result[i] = load<uint_t, eEndian::kBig>(buffer, i + 1);
    }
    ASSERT_EQ(expected, result);
}

TEST_F(LoadUInt32WithNParam, ConstexprFromBig)
{
    using val_array = std::array<uint_t, sizeof(uint_t)>;
    constexpr val_array expected{0x1, 0x102, 0x10203, 0x1020304};

    constexpr val_array result = [](auto buf)
    {
        val_array tmp{};
        for (std::size_t i = 0; i < sizeof(uint_t); ++i)
        {
            tmp[i] = load<uint_t, eEndian::kBig>(buf, i + 1);
        }
        return tmp;
    }(buffer);

    static_assert(is_equal_arrays(expected, result));
}

using LoadUInt16WithNParam = LoadUInt16From2Bytes;
TEST_F(LoadUInt16WithNParam, FromLittle)
{
    using val_array = std::array<uint_t, sizeof(uint_t)>;
    val_array expected{0x1, 0x201};

    val_array result;
    for (std::size_t i = 0; i < sizeof(uint_t); ++i)
    {
        result[i] = load<uint_t, eEndian::kLittle>(buffer, i + 1);
    }
    ASSERT_EQ(expected, result);
}

TEST_F(LoadUInt16WithNParam, ConstexprFromLittle)
{
    using val_array = std::array<uint_t, sizeof(uint_t)>;
    constexpr val_array expected{0x1, 0x201};

    constexpr val_array result = [](auto buf)
    {
        val_array tmp{};
        for (std::size_t i = 0; i < sizeof(uint_t); ++i)
        {
            tmp[i] = load<uint_t, eEndian::kLittle>(buf, i + 1);
        }
        return tmp;
    }(buffer);

    static_assert(is_equal_arrays(expected, result));
}

TEST_F(LoadUInt16WithNParam, FromBig)
{
    using val_array = std::array<uint_t, sizeof(uint_t)>;
    val_array expected{0x1, 0x102};

    val_array result;
    for (std::size_t i = 0; i < sizeof(uint_t); ++i)
    {
        result[i] = load<uint_t, eEndian::kBig>(buffer, i + 1);
    }
    ASSERT_EQ(expected, result);
}

TEST_F(LoadUInt16WithNParam, ConstexprFromBig)
{
    using val_array = std::array<uint_t, sizeof(uint_t)>;
    constexpr val_array expected{0x1, 0x102};

    constexpr val_array result = [](auto buf)
    {
        val_array tmp{};
        for (std::size_t i = 0; i < sizeof(uint_t); ++i)
        {
            tmp[i] = load<uint_t, eEndian::kBig>(buf, i + 1);
        }
        return tmp;
    }(buffer);

    static_assert(is_equal_arrays(expected, result));
}

using LoadUInt8WithNParam = LoadUInt8From1Byte;
TEST_F(LoadUInt8WithNParam, FromLittle)
{
    using val_array = std::array<uint_t, sizeof(uint_t)>;
    val_array expected{0x1};

    val_array result;
    for (std::size_t i = 0; i < sizeof(uint_t); ++i)
    {
        result[i] = load<uint_t, eEndian::kLittle>(buffer, i + 1);
    }
    ASSERT_EQ(expected, result);
}

TEST_F(LoadUInt8WithNParam, ConstexprFromLittle)
{
    using val_array = std::array<uint_t, sizeof(uint_t)>;
    constexpr val_array expected{0x1};

    constexpr val_array result = [](auto buf)
    {
        val_array tmp{};
        for (std::size_t i = 0; i < sizeof(uint_t); ++i)
        {
            tmp[i] = load<uint_t, eEndian::kLittle>(buf, i + 1);
        }
        return tmp;
    }(buffer);

    static_assert(is_equal_arrays(expected, result));
}

TEST_F(LoadUInt8WithNParam, FromBig)
{
    using val_array = std::array<uint_t, sizeof(uint_t)>;
    val_array expected{0x1};

    val_array result;
    for (std::size_t i = 0; i < sizeof(uint_t); ++i)
    {
        result[i] = load<uint_t, eEndian::kBig>(buffer, i + 1);
    }
    ASSERT_EQ(expected, result);
}

TEST_F(LoadUInt8WithNParam, ConstexprFromBig)
{
    using val_array = std::array<uint_t, sizeof(uint_t)>;
    constexpr val_array expected{0x1};

    constexpr val_array result = [](auto buf)
    {
        val_array tmp{};
        for (std::size_t i = 0; i < sizeof(uint_t); ++i)
        {
            tmp[i] = load<uint_t, eEndian::kBig>(buf, i + 1);
        }
        return tmp;
    }(buffer);

    static_assert(is_equal_arrays(expected, result));
}
