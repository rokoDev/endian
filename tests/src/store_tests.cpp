#include <endian/endian.h>
#include <gtest/gtest.h>

#include <array>
#include <type_traits>

#include "test_helpers.h"

using namespace endian;

template <typename T, std::size_t NBytes>
class store_template : public ::testing::Test
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
};

template <typename Buf, eEndian To, std::size_t N, typename U>
constexpr Buf store_result(U aValue) noexcept
{
    Buf buffer{};
    endian::store<To>(buffer.data(), aValue, N);
    return buffer;
}

// store std::uint8_t
using Store0ByteOfUInt8 = store_template<std::uint8_t, 1>;
TEST_F(Store0ByteOfUInt8, ToLittle)
{
    const buffer_t expected{std::byte{}};
    auto result = store_result<buffer_t, eEndian::kLittle, 0>(uint_t{0x1});
    ASSERT_EQ(expected, result);
}

using Store1ByteOfUInt8 = store_template<std::uint8_t, 1>;
TEST_F(Store1ByteOfUInt8, ToLittle)
{
    const buffer_t expected{std::byte{0x1}};
    auto result = store_result<buffer_t, eEndian::kLittle, N>(uint_t{0x1});
    ASSERT_EQ(expected, result);
}

TEST_F(Store1ByteOfUInt8, ConstexprToLittle)
{
    constexpr const buffer_t expected{std::byte{0x1}};
    constexpr auto result =
        store_result<buffer_t, eEndian::kLittle, N>(uint_t{0x1});
    static_assert(is_equal_arrays(expected, result));
}

TEST_F(Store1ByteOfUInt8, ToBig)
{
    const buffer_t expected{std::byte{0x1}};
    auto result = store_result<buffer_t, eEndian::kBig, N>(uint_t{0x1});
    ASSERT_EQ(expected, result);
}

TEST_F(Store1ByteOfUInt8, ConstexprToBig)
{
    constexpr const buffer_t expected{std::byte{0x1}};
    constexpr auto result =
        store_result<buffer_t, eEndian::kBig, N>(uint_t{0x1});
    static_assert(is_equal_arrays(expected, result));
}

// store std::uint16_t
using Store1BytesOfUInt16 = store_template<std::uint16_t, 1>;
TEST_F(Store1BytesOfUInt16, ToLittle)
{
    const buffer_t expected{std::byte{0x1}};
    auto result = store_result<buffer_t, eEndian::kLittle, N>(uint_t{0x1});
    ASSERT_EQ(expected, result);
}

TEST_F(Store1BytesOfUInt16, ConstexprToLittle)
{
    constexpr const buffer_t expected{std::byte{0x1}};
    constexpr auto result =
        store_result<buffer_t, eEndian::kLittle, N>(uint_t{0x1});
    static_assert(is_equal_arrays(expected, result));
}

TEST_F(Store1BytesOfUInt16, ToBig)
{
    const buffer_t expected{std::byte{0x1}};
    auto result = store_result<buffer_t, eEndian::kBig, N>(uint_t{0x1});
    ASSERT_EQ(expected, result);
}

TEST_F(Store1BytesOfUInt16, ConstexprToBig)
{
    constexpr const buffer_t expected{std::byte{0x1}};
    constexpr auto result =
        store_result<buffer_t, eEndian::kBig, N>(uint_t{0x1});
    static_assert(is_equal_arrays(expected, result));
}

using Store2BytesOfUInt16 = store_template<std::uint16_t, 2>;
TEST_F(Store2BytesOfUInt16, ToLittle)
{
    const buffer_t expected{std::byte{0x2}, std::byte{0x1}};
    auto result = store_result<buffer_t, eEndian::kLittle, N>(uint_t{0x102});
    ASSERT_EQ(expected, result);
}

TEST_F(Store2BytesOfUInt16, ConstexprToLittle)
{
    constexpr const buffer_t expected{std::byte{0x2}, std::byte{0x1}};
    constexpr auto result =
        store_result<buffer_t, eEndian::kLittle, N>(uint_t{0x102});
    static_assert(is_equal_arrays(expected, result));
}

TEST_F(Store2BytesOfUInt16, ToBig)
{
    const buffer_t expected{std::byte{0x1}, std::byte{0x2}};
    auto result = store_result<buffer_t, eEndian::kBig, N>(uint_t{0x102});
    ASSERT_EQ(expected, result);
}

TEST_F(Store2BytesOfUInt16, ConstexprToBig)
{
    constexpr const buffer_t expected{std::byte{0x1}, std::byte{0x2}};
    constexpr auto result =
        store_result<buffer_t, eEndian::kBig, N>(uint_t{0x102});
    static_assert(is_equal_arrays(expected, result));
}

// store std::uint32_t
using Store1BytesOfUInt32 = store_template<std::uint32_t, 1>;
TEST_F(Store1BytesOfUInt32, ToLittle)
{
    const buffer_t expected{std::byte{0x1}};
    auto result = store_result<buffer_t, eEndian::kLittle, N>(uint_t{0x1});
    ASSERT_EQ(expected, result);
}

TEST_F(Store1BytesOfUInt32, ConstexprToLittle)
{
    constexpr const buffer_t expected{std::byte{0x1}};
    constexpr auto result =
        store_result<buffer_t, eEndian::kLittle, N>(uint_t{0x1});
    static_assert(is_equal_arrays(expected, result));
}

TEST_F(Store1BytesOfUInt32, ToBig)
{
    const buffer_t expected{std::byte{0x1}};
    auto result = store_result<buffer_t, eEndian::kBig, N>(uint_t{0x1});
    ASSERT_EQ(expected, result);
}

TEST_F(Store1BytesOfUInt32, ConstexprToBig)
{
    constexpr const buffer_t expected{std::byte{0x1}};
    constexpr auto result =
        store_result<buffer_t, eEndian::kBig, N>(uint_t{0x1});
    static_assert(is_equal_arrays(expected, result));
}

using Store2BytesOfUInt32 = store_template<std::uint32_t, 2>;
TEST_F(Store2BytesOfUInt32, ToLittle)
{
    const buffer_t expected{std::byte{0x2}, std::byte{0x1}};
    auto result = store_result<buffer_t, eEndian::kLittle, N>(uint_t{0x102});
    ASSERT_EQ(expected, result);
}

TEST_F(Store2BytesOfUInt32, ConstexprToLittle)
{
    constexpr const buffer_t expected{std::byte{0x2}, std::byte{0x1}};
    constexpr auto result =
        store_result<buffer_t, eEndian::kLittle, N>(uint_t{0x102});
    static_assert(is_equal_arrays(expected, result));
}

TEST_F(Store2BytesOfUInt32, ToBig)
{
    const buffer_t expected{std::byte{0x1}, std::byte{0x2}};
    auto result = store_result<buffer_t, eEndian::kBig, N>(uint_t{0x102});
    ASSERT_EQ(expected, result);
}

TEST_F(Store2BytesOfUInt32, ConstexprToBig)
{
    constexpr const buffer_t expected{std::byte{0x1}, std::byte{0x2}};
    constexpr auto result =
        store_result<buffer_t, eEndian::kBig, N>(uint_t{0x102});
    static_assert(is_equal_arrays(expected, result));
}

using Store3BytesOfUInt32 = store_template<std::uint32_t, 3>;
TEST_F(Store3BytesOfUInt32, ToLittle)
{
    const buffer_t expected{std::byte{0x3}, std::byte{0x2}, std::byte{0x1}};
    auto result = store_result<buffer_t, eEndian::kLittle, N>(uint_t{0x10203});
    ASSERT_EQ(expected, result);
}

TEST_F(Store3BytesOfUInt32, ConstexprToLittle)
{
    constexpr const buffer_t expected{std::byte{0x3}, std::byte{0x2},
                                      std::byte{0x1}};
    constexpr auto result =
        store_result<buffer_t, eEndian::kLittle, N>(uint_t{0x10203});
    static_assert(is_equal_arrays(expected, result));
}

TEST_F(Store3BytesOfUInt32, ToBig)
{
    const buffer_t expected{std::byte{0x1}, std::byte{0x2}, std::byte{0x3}};
    auto result = store_result<buffer_t, eEndian::kBig, N>(uint_t{0x10203});
    ASSERT_EQ(expected, result);
}

TEST_F(Store3BytesOfUInt32, ConstexprToBig)
{
    constexpr const buffer_t expected{std::byte{0x1}, std::byte{0x2},
                                      std::byte{0x3}};
    constexpr auto result =
        store_result<buffer_t, eEndian::kBig, N>(uint_t{0x10203});
    static_assert(is_equal_arrays(expected, result));
}

using Store4BytesOfUInt32 = store_template<std::uint32_t, 4>;
TEST_F(Store4BytesOfUInt32, ToLittle)
{
    const buffer_t expected{std::byte{0x4}, std::byte{0x3}, std::byte{0x2},
                            std::byte{0x1}};
    auto result =
        store_result<buffer_t, eEndian::kLittle, N>(uint_t{0x1020304});
    ASSERT_EQ(expected, result);
}

TEST_F(Store4BytesOfUInt32, ConstexprToLittle)
{
    constexpr const buffer_t expected{std::byte{0x4}, std::byte{0x3},
                                      std::byte{0x2}, std::byte{0x1}};
    constexpr auto result =
        store_result<buffer_t, eEndian::kLittle, N>(uint_t{0x1020304});
    static_assert(is_equal_arrays(expected, result));
}

TEST_F(Store4BytesOfUInt32, ToBig)
{
    const buffer_t expected{std::byte{0x1}, std::byte{0x2}, std::byte{0x3},
                            std::byte{0x4}};
    auto result = store_result<buffer_t, eEndian::kBig, N>(uint_t{0x1020304});
    ASSERT_EQ(expected, result);
}

TEST_F(Store4BytesOfUInt32, ConstexprToBig)
{
    constexpr const buffer_t expected{std::byte{0x1}, std::byte{0x2},
                                      std::byte{0x3}, std::byte{0x4}};
    constexpr auto result =
        store_result<buffer_t, eEndian::kBig, N>(uint_t{0x1020304});
    static_assert(is_equal_arrays(expected, result));
}

// store std::uint64_t
using Store1BytesOfUInt64 = store_template<std::uint64_t, 1>;
TEST_F(Store1BytesOfUInt64, ToLittle)
{
    const buffer_t expected{std::byte{0x1}};
    auto result = store_result<buffer_t, eEndian::kLittle, N>(uint_t{0x1});
    ASSERT_EQ(expected, result);
}

TEST_F(Store1BytesOfUInt64, ConstexprToLittle)
{
    constexpr const buffer_t expected{std::byte{0x1}};
    constexpr auto result =
        store_result<buffer_t, eEndian::kLittle, N>(uint_t{0x1});
    static_assert(is_equal_arrays(expected, result));
}

TEST_F(Store1BytesOfUInt64, ToBig)
{
    const buffer_t expected{std::byte{0x1}};
    auto result = store_result<buffer_t, eEndian::kBig, N>(uint_t{0x1});
    ASSERT_EQ(expected, result);
}

TEST_F(Store1BytesOfUInt64, ConstexprToBig)
{
    constexpr const buffer_t expected{std::byte{0x1}};
    constexpr auto result =
        store_result<buffer_t, eEndian::kBig, N>(uint_t{0x1});
    static_assert(is_equal_arrays(expected, result));
}

using Store2BytesOfUInt64 = store_template<std::uint64_t, 2>;
TEST_F(Store2BytesOfUInt64, ToLittle)
{
    const buffer_t expected{std::byte{0x2}, std::byte{0x1}};
    auto result = store_result<buffer_t, eEndian::kLittle, N>(uint_t{0x102});
    ASSERT_EQ(expected, result);
}

TEST_F(Store2BytesOfUInt64, ConstexprToLittle)
{
    constexpr const buffer_t expected{std::byte{0x2}, std::byte{0x1}};
    constexpr auto result =
        store_result<buffer_t, eEndian::kLittle, N>(uint_t{0x102});
    static_assert(is_equal_arrays(expected, result));
}

TEST_F(Store2BytesOfUInt64, ToBig)
{
    const buffer_t expected{std::byte{0x1}, std::byte{0x2}};
    auto result = store_result<buffer_t, eEndian::kBig, N>(uint_t{0x102});
    ASSERT_EQ(expected, result);
}

TEST_F(Store2BytesOfUInt64, ConstexprToBig)
{
    constexpr const buffer_t expected{std::byte{0x1}, std::byte{0x2}};
    constexpr auto result =
        store_result<buffer_t, eEndian::kBig, N>(uint_t{0x102});
    static_assert(is_equal_arrays(expected, result));
}

using Store3BytesOfUInt64 = store_template<std::uint64_t, 3>;
TEST_F(Store3BytesOfUInt64, ToLittle)
{
    const buffer_t expected{std::byte{0x3}, std::byte{0x2}, std::byte{0x1}};
    auto result = store_result<buffer_t, eEndian::kLittle, N>(uint_t{0x10203});
    ASSERT_EQ(expected, result);
}

TEST_F(Store3BytesOfUInt64, ConstexprToLittle)
{
    constexpr const buffer_t expected{std::byte{0x3}, std::byte{0x2},
                                      std::byte{0x1}};
    constexpr auto result =
        store_result<buffer_t, eEndian::kLittle, N>(uint_t{0x10203});
    static_assert(is_equal_arrays(expected, result));
}

TEST_F(Store3BytesOfUInt64, ToBig)
{
    const buffer_t expected{std::byte{0x1}, std::byte{0x2}, std::byte{0x3}};
    auto result = store_result<buffer_t, eEndian::kBig, N>(uint_t{0x10203});
    ASSERT_EQ(expected, result);
}

TEST_F(Store3BytesOfUInt64, ConstexprToBig)
{
    constexpr const buffer_t expected{std::byte{0x1}, std::byte{0x2},
                                      std::byte{0x3}};
    constexpr auto result =
        store_result<buffer_t, eEndian::kBig, N>(uint_t{0x10203});
    static_assert(is_equal_arrays(expected, result));
}

using Store4BytesOfUInt64 = store_template<std::uint64_t, 4>;
TEST_F(Store4BytesOfUInt64, ToLittle)
{
    const buffer_t expected{std::byte{0x4}, std::byte{0x3}, std::byte{0x2},
                            std::byte{0x1}};
    auto result =
        store_result<buffer_t, eEndian::kLittle, N>(uint_t{0x1020304});
    ASSERT_EQ(expected, result);
}

TEST_F(Store4BytesOfUInt64, ConstexprToLittle)
{
    constexpr const buffer_t expected{std::byte{0x4}, std::byte{0x3},
                                      std::byte{0x2}, std::byte{0x1}};
    constexpr auto result =
        store_result<buffer_t, eEndian::kLittle, N>(uint_t{0x1020304});
    static_assert(is_equal_arrays(expected, result));
}

TEST_F(Store4BytesOfUInt64, ToBig)
{
    const buffer_t expected{std::byte{0x1}, std::byte{0x2}, std::byte{0x3},
                            std::byte{0x4}};
    auto result = store_result<buffer_t, eEndian::kBig, N>(uint_t{0x1020304});
    ASSERT_EQ(expected, result);
}

TEST_F(Store4BytesOfUInt64, ConstexprToBig)
{
    constexpr const buffer_t expected{std::byte{0x1}, std::byte{0x2},
                                      std::byte{0x3}, std::byte{0x4}};
    constexpr auto result =
        store_result<buffer_t, eEndian::kBig, N>(uint_t{0x1020304});
    static_assert(is_equal_arrays(expected, result));
}

using Store5BytesOfUInt64 = store_template<std::uint64_t, 5>;
TEST_F(Store5BytesOfUInt64, ToLittle)
{
    const buffer_t expected{std::byte{0x5}, std::byte{0x4}, std::byte{0x3},
                            std::byte{0x2}, std::byte{0x1}};
    auto result =
        store_result<buffer_t, eEndian::kLittle, N>(uint_t{0x102030405});
    ASSERT_EQ(expected, result);
}

TEST_F(Store5BytesOfUInt64, ConstexprToLittle)
{
    constexpr const buffer_t expected{std::byte{0x5}, std::byte{0x4},
                                      std::byte{0x3}, std::byte{0x2},
                                      std::byte{0x1}};
    constexpr auto result =
        store_result<buffer_t, eEndian::kLittle, N>(uint_t{0x102030405});
    static_assert(is_equal_arrays(expected, result));
}

TEST_F(Store5BytesOfUInt64, ToBig)
{
    const buffer_t expected{std::byte{0x1}, std::byte{0x2}, std::byte{0x3},
                            std::byte{0x4}, std::byte{0x5}};
    auto result = store_result<buffer_t, eEndian::kBig, N>(uint_t{0x102030405});
    ASSERT_EQ(expected, result);
}

TEST_F(Store5BytesOfUInt64, ConstexprToBig)
{
    constexpr const buffer_t expected{std::byte{0x1}, std::byte{0x2},
                                      std::byte{0x3}, std::byte{0x4},
                                      std::byte{0x5}};
    constexpr auto result =
        store_result<buffer_t, eEndian::kBig, N>(uint_t{0x102030405});
    static_assert(is_equal_arrays(expected, result));
}

using Store6BytesOfUInt64 = store_template<std::uint64_t, 6>;
TEST_F(Store6BytesOfUInt64, ToLittle)
{
    const buffer_t expected{std::byte{0x6}, std::byte{0x5}, std::byte{0x4},
                            std::byte{0x3}, std::byte{0x2}, std::byte{0x1}};
    auto result =
        store_result<buffer_t, eEndian::kLittle, N>(uint_t{0x10203040506});
    ASSERT_EQ(expected, result);
}

TEST_F(Store6BytesOfUInt64, ConstexprToLittle)
{
    constexpr const buffer_t expected{std::byte{0x6}, std::byte{0x5},
                                      std::byte{0x4}, std::byte{0x3},
                                      std::byte{0x2}, std::byte{0x1}};
    constexpr auto result =
        store_result<buffer_t, eEndian::kLittle, N>(uint_t{0x10203040506});
    static_assert(is_equal_arrays(expected, result));
}

TEST_F(Store6BytesOfUInt64, ToBig)
{
    const buffer_t expected{std::byte{0x1}, std::byte{0x2}, std::byte{0x3},
                            std::byte{0x4}, std::byte{0x5}, std::byte{0x6}};
    auto result =
        store_result<buffer_t, eEndian::kBig, N>(uint_t{0x10203040506});
    ASSERT_EQ(expected, result);
}

TEST_F(Store6BytesOfUInt64, ConstexprToBig)
{
    constexpr const buffer_t expected{std::byte{0x1}, std::byte{0x2},
                                      std::byte{0x3}, std::byte{0x4},
                                      std::byte{0x5}, std::byte{0x6}};
    constexpr auto result =
        store_result<buffer_t, eEndian::kBig, N>(uint_t{0x10203040506});
    static_assert(is_equal_arrays(expected, result));
}

using Store7BytesOfUInt64 = store_template<std::uint64_t, 7>;
TEST_F(Store7BytesOfUInt64, ToLittle)
{
    const buffer_t expected{std::byte{0x7}, std::byte{0x6}, std::byte{0x5},
                            std::byte{0x4}, std::byte{0x3}, std::byte{0x2},
                            std::byte{0x1}};
    auto result =
        store_result<buffer_t, eEndian::kLittle, N>(uint_t{0x1020304050607});
    ASSERT_EQ(expected, result);
}

TEST_F(Store7BytesOfUInt64, ConstexprToLittle)
{
    constexpr const buffer_t expected{
        std::byte{0x7}, std::byte{0x6}, std::byte{0x5}, std::byte{0x4},
        std::byte{0x3}, std::byte{0x2}, std::byte{0x1}};
    constexpr auto result =
        store_result<buffer_t, eEndian::kLittle, N>(uint_t{0x1020304050607});
    static_assert(is_equal_arrays(expected, result));
}

TEST_F(Store7BytesOfUInt64, ToBig)
{
    const buffer_t expected{std::byte{0x1}, std::byte{0x2}, std::byte{0x3},
                            std::byte{0x4}, std::byte{0x5}, std::byte{0x6},
                            std::byte{0x7}};
    auto result =
        store_result<buffer_t, eEndian::kBig, N>(uint_t{0x1020304050607});
    ASSERT_EQ(expected, result);
}

TEST_F(Store7BytesOfUInt64, ConstexprToBig)
{
    constexpr const buffer_t expected{
        std::byte{0x1}, std::byte{0x2}, std::byte{0x3}, std::byte{0x4},
        std::byte{0x5}, std::byte{0x6}, std::byte{0x7}};
    constexpr auto result =
        store_result<buffer_t, eEndian::kBig, N>(uint_t{0x1020304050607});
    static_assert(is_equal_arrays(expected, result));
}

using Store8BytesOfUInt64 = store_template<std::uint64_t, 8>;
TEST_F(Store8BytesOfUInt64, ToLittle)
{
    const buffer_t expected{std::byte{0x8}, std::byte{0x7}, std::byte{0x6},
                            std::byte{0x5}, std::byte{0x4}, std::byte{0x3},
                            std::byte{0x2}, std::byte{0x1}};
    auto result =
        store_result<buffer_t, eEndian::kLittle, N>(uint_t{0x102030405060708});
    ASSERT_EQ(expected, result);
}

TEST_F(Store8BytesOfUInt64, ConstexprToLittle)
{
    constexpr const buffer_t expected{
        std::byte{0x8}, std::byte{0x7}, std::byte{0x6}, std::byte{0x5},
        std::byte{0x4}, std::byte{0x3}, std::byte{0x2}, std::byte{0x1}};
    constexpr auto result =
        store_result<buffer_t, eEndian::kLittle, N>(uint_t{0x102030405060708});
    static_assert(is_equal_arrays(expected, result));
}

TEST_F(Store8BytesOfUInt64, ToBig)
{
    const buffer_t expected{std::byte{0x1}, std::byte{0x2}, std::byte{0x3},
                            std::byte{0x4}, std::byte{0x5}, std::byte{0x6},
                            std::byte{0x7}, std::byte{0x8}};
    auto result =
        store_result<buffer_t, eEndian::kBig, N>(uint_t{0x102030405060708});
    ASSERT_EQ(expected, result);
}

TEST_F(Store8BytesOfUInt64, ConstexprToBig)
{
    constexpr const buffer_t expected{
        std::byte{0x1}, std::byte{0x2}, std::byte{0x3}, std::byte{0x4},
        std::byte{0x5}, std::byte{0x6}, std::byte{0x7}, std::byte{0x8}};
    constexpr auto result =
        store_result<buffer_t, eEndian::kBig, N>(uint_t{0x102030405060708});
    static_assert(is_equal_arrays(expected, result));
}

TEST_F(Store8BytesOfUInt64, RValue)
{
    buffer_t actual{};
    store<eEndian::kLittle>(actual.data(), std::uint64_t{5}, N);

    constexpr const buffer_t expected{std::byte{0x5}, std::byte{}, std::byte{},
                                      std::byte{},    std::byte{}, std::byte{},
                                      std::byte{},    std::byte{}};
    ASSERT_EQ(actual, expected);
}

TEST_F(Store8BytesOfUInt64, LValue)
{
    buffer_t actual{};
    std::uint64_t value{5};
    store<eEndian::kLittle>(actual.data(), value, N);

    constexpr const buffer_t expected{std::byte{0x5}, std::byte{}, std::byte{},
                                      std::byte{},    std::byte{}, std::byte{},
                                      std::byte{},    std::byte{}};
    ASSERT_EQ(actual, expected);
}

using StoreUInt64WithNParam = Store8BytesOfUInt64;
TEST_F(StoreUInt64WithNParam, ToLittle)
{
    using val_array = std::array<buffer_t, sizeof(uint_t)>;
    val_array expected{
        {{{std::byte{1}}},
         {{std::byte{1}, std::byte{2}}},
         {{std::byte{1}, std::byte{2}, std::byte{3}}},
         {{std::byte{1}, std::byte{2}, std::byte{3}, std::byte{4}}},
         {{std::byte{1}, std::byte{2}, std::byte{3}, std::byte{4},
           std::byte{5}}},
         {{std::byte{1}, std::byte{2}, std::byte{3}, std::byte{4}, std::byte{5},
           std::byte{6}}},
         {{std::byte{1}, std::byte{2}, std::byte{3}, std::byte{4}, std::byte{5},
           std::byte{6}, std::byte{7}}},
         {{std::byte{1}, std::byte{2}, std::byte{3}, std::byte{4}, std::byte{5},
           std::byte{6}, std::byte{7}, std::byte{8}}}}};

    val_array result{};
    for (std::size_t i = 0; i < sizeof(uint_t); ++i)
    {
        store<eEndian::kLittle>(result[i].data(), uint_t{0x807060504030201},
                                i + 1);
    }
    ASSERT_EQ(expected, result);
}

TEST_F(StoreUInt64WithNParam, ConstexprToLittle)
{
    using val_array = std::array<buffer_t, sizeof(uint_t)>;
    constexpr val_array expected{
        {{{std::byte{1}}},
         {{std::byte{1}, std::byte{2}}},
         {{std::byte{1}, std::byte{2}, std::byte{3}}},
         {{std::byte{1}, std::byte{2}, std::byte{3}, std::byte{4}}},
         {{std::byte{1}, std::byte{2}, std::byte{3}, std::byte{4},
           std::byte{5}}},
         {{std::byte{1}, std::byte{2}, std::byte{3}, std::byte{4}, std::byte{5},
           std::byte{6}}},
         {{std::byte{1}, std::byte{2}, std::byte{3}, std::byte{4}, std::byte{5},
           std::byte{6}, std::byte{7}}},
         {{std::byte{1}, std::byte{2}, std::byte{3}, std::byte{4}, std::byte{5},
           std::byte{6}, std::byte{7}, std::byte{8}}}}};

    constexpr val_array result = []()
    {
        val_array tmp{};
        for (std::size_t i = 0; i < sizeof(uint_t); ++i)
        {
            store<eEndian::kLittle>(tmp[i].data(), uint_t{0x807060504030201},
                                    i + 1);
        }
        return tmp;
    }();

    static_assert(is_equal_arrays(expected, result));
}

TEST_F(StoreUInt64WithNParam, ToBig)
{
    using val_array = std::array<buffer_t, sizeof(uint_t)>;
    val_array expected{
        {{{std::byte{8}}},
         {{std::byte{7}, std::byte{8}}},
         {{std::byte{6}, std::byte{7}, std::byte{8}}},
         {{std::byte{5}, std::byte{6}, std::byte{7}, std::byte{8}}},
         {{std::byte{4}, std::byte{5}, std::byte{6}, std::byte{7},
           std::byte{8}}},
         {{std::byte{3}, std::byte{4}, std::byte{5}, std::byte{6}, std::byte{7},
           std::byte{8}}},
         {{std::byte{2}, std::byte{3}, std::byte{4}, std::byte{5}, std::byte{6},
           std::byte{7}, std::byte{8}}},
         {{std::byte{1}, std::byte{2}, std::byte{3}, std::byte{4}, std::byte{5},
           std::byte{6}, std::byte{7}, std::byte{8}}}}};

    val_array result{};
    for (std::size_t i = 0; i < sizeof(uint_t); ++i)
    {
        store<eEndian::kBig>(result[i].data(), uint_t{0x102030405060708},
                             i + 1);
    }
    ASSERT_EQ(expected, result);
}

TEST_F(StoreUInt64WithNParam, ConstexprToBig)
{
    using val_array = std::array<buffer_t, sizeof(uint_t)>;
    constexpr val_array expected{
        {{{std::byte{8}}},
         {{std::byte{7}, std::byte{8}}},
         {{std::byte{6}, std::byte{7}, std::byte{8}}},
         {{std::byte{5}, std::byte{6}, std::byte{7}, std::byte{8}}},
         {{std::byte{4}, std::byte{5}, std::byte{6}, std::byte{7},
           std::byte{8}}},
         {{std::byte{3}, std::byte{4}, std::byte{5}, std::byte{6}, std::byte{7},
           std::byte{8}}},
         {{std::byte{2}, std::byte{3}, std::byte{4}, std::byte{5}, std::byte{6},
           std::byte{7}, std::byte{8}}},
         {{std::byte{1}, std::byte{2}, std::byte{3}, std::byte{4}, std::byte{5},
           std::byte{6}, std::byte{7}, std::byte{8}}}}};

    constexpr val_array result = []()
    {
        val_array tmp{};
        for (std::size_t i = 0; i < sizeof(uint_t); ++i)
        {
            store<eEndian::kBig>(tmp[i].data(), uint_t{0x102030405060708},
                                 i + 1);
        }
        return tmp;
    }();

    static_assert(is_equal_arrays(expected, result));
}

using StoreUInt32WithNParam = Store4BytesOfUInt32;
TEST_F(StoreUInt32WithNParam, ToLittle)
{
    using val_array = std::array<buffer_t, sizeof(uint_t)>;
    val_array expected{
        {{{std::byte{1}}},
         {{std::byte{1}, std::byte{2}}},
         {{std::byte{1}, std::byte{2}, std::byte{3}}},
         {{std::byte{1}, std::byte{2}, std::byte{3}, std::byte{4}}}}};

    val_array result{};
    for (std::size_t i = 0; i < sizeof(uint_t); ++i)
    {
        store<eEndian::kLittle>(result[i].data(), uint_t{0x4030201}, i + 1);
    }
    ASSERT_EQ(expected, result);
}

TEST_F(StoreUInt32WithNParam, ConstexprToLittle)
{
    using val_array = std::array<buffer_t, sizeof(uint_t)>;
    constexpr val_array expected{
        {{{std::byte{1}}},
         {{std::byte{1}, std::byte{2}}},
         {{std::byte{1}, std::byte{2}, std::byte{3}}},
         {{std::byte{1}, std::byte{2}, std::byte{3}, std::byte{4}}}}};

    constexpr val_array result = []()
    {
        val_array tmp{};
        for (std::size_t i = 0; i < sizeof(uint_t); ++i)
        {
            store<eEndian::kLittle>(tmp[i].data(), uint_t{0x4030201}, i + 1);
        }
        return tmp;
    }();

    static_assert(is_equal_arrays(expected, result));
}

TEST_F(StoreUInt32WithNParam, ToBig)
{
    using val_array = std::array<buffer_t, sizeof(uint_t)>;
    val_array expected{
        {{{std::byte{8}}},
         {{std::byte{7}, std::byte{8}}},
         {{std::byte{6}, std::byte{7}, std::byte{8}}},
         {{std::byte{5}, std::byte{6}, std::byte{7}, std::byte{8}}}}};

    val_array result{};
    for (std::size_t i = 0; i < sizeof(uint_t); ++i)
    {
        store<eEndian::kBig>(result[i].data(), uint_t{0x5060708}, i + 1);
    }
    ASSERT_EQ(expected, result);
}

TEST_F(StoreUInt32WithNParam, ConstexprToBig)
{
    using val_array = std::array<buffer_t, sizeof(uint_t)>;
    constexpr val_array expected{
        {{{std::byte{8}}},
         {{std::byte{7}, std::byte{8}}},
         {{std::byte{6}, std::byte{7}, std::byte{8}}},
         {{std::byte{5}, std::byte{6}, std::byte{7}, std::byte{8}}}}};

    constexpr val_array result = []()
    {
        val_array tmp{};
        for (std::size_t i = 0; i < sizeof(uint_t); ++i)
        {
            store<eEndian::kBig>(tmp[i].data(), uint_t{0x5060708}, i + 1);
        }
        return tmp;
    }();

    static_assert(is_equal_arrays(expected, result));
}

using StoreUInt16WithNParam = Store2BytesOfUInt16;
TEST_F(StoreUInt16WithNParam, ToLittle)
{
    using val_array = std::array<buffer_t, sizeof(uint_t)>;
    val_array expected{{{{std::byte{1}}}, {{std::byte{1}, std::byte{2}}}}};

    val_array result{};
    for (std::size_t i = 0; i < sizeof(uint_t); ++i)
    {
        store<eEndian::kLittle>(result[i].data(), uint_t{0x201}, i + 1);
    }
    ASSERT_EQ(expected, result);
}

TEST_F(StoreUInt16WithNParam, ConstexprToLittle)
{
    using val_array = std::array<buffer_t, sizeof(uint_t)>;
    constexpr val_array expected{
        {{{std::byte{1}}}, {{std::byte{1}, std::byte{2}}}}};

    constexpr val_array result = []()
    {
        val_array tmp{};
        for (std::size_t i = 0; i < sizeof(uint_t); ++i)
        {
            store<eEndian::kLittle>(tmp[i].data(), uint_t{0x201}, i + 1);
        }
        return tmp;
    }();

    static_assert(is_equal_arrays(expected, result));
}

TEST_F(StoreUInt16WithNParam, ToBig)
{
    using val_array = std::array<buffer_t, sizeof(uint_t)>;
    val_array expected{{{{std::byte{8}}}, {{std::byte{7}, std::byte{8}}}}};

    val_array result{};
    for (std::size_t i = 0; i < sizeof(uint_t); ++i)
    {
        store<eEndian::kBig>(result[i].data(), uint_t{0x708}, i + 1);
    }
    ASSERT_EQ(expected, result);
}

TEST_F(StoreUInt16WithNParam, ConstexprToBig)
{
    using val_array = std::array<buffer_t, sizeof(uint_t)>;
    constexpr val_array expected{
        {{{std::byte{8}}}, {{std::byte{7}, std::byte{8}}}}};

    constexpr val_array result = []()
    {
        val_array tmp{};
        for (std::size_t i = 0; i < sizeof(uint_t); ++i)
        {
            store<eEndian::kBig>(tmp[i].data(), uint_t{0x708}, i + 1);
        }
        return tmp;
    }();

    static_assert(is_equal_arrays(expected, result));
}

using StoreUInt8WithNParam = Store1ByteOfUInt8;
TEST_F(StoreUInt8WithNParam, ToLittle)
{
    using val_array = std::array<buffer_t, sizeof(uint_t)>;
    val_array expected{{{{std::byte{1}}}}};

    val_array result{};
    for (std::size_t i = 0; i < sizeof(uint_t); ++i)
    {
        store<eEndian::kLittle>(result[i].data(), uint_t{0x1}, i + 1);
    }
    ASSERT_EQ(expected, result);
}

TEST_F(StoreUInt8WithNParam, ConstexprToLittle)
{
    using val_array = std::array<buffer_t, sizeof(uint_t)>;
    constexpr val_array expected{{{{std::byte{1}}}}};

    constexpr val_array result = []()
    {
        val_array tmp{};
        for (std::size_t i = 0; i < sizeof(uint_t); ++i)
        {
            store<eEndian::kLittle>(tmp[i].data(), uint_t{0x1}, i + 1);
        }
        return tmp;
    }();

    static_assert(is_equal_arrays(expected, result));
}

TEST_F(StoreUInt8WithNParam, ToBig)
{
    using val_array = std::array<buffer_t, sizeof(uint_t)>;
    val_array expected{{{{std::byte{8}}}}};

    val_array result{};
    for (std::size_t i = 0; i < sizeof(uint_t); ++i)
    {
        store<eEndian::kBig>(result[i].data(), uint_t{0x8}, i + 1);
    }
    ASSERT_EQ(expected, result);
}

TEST_F(StoreUInt8WithNParam, ConstexprToBig)
{
    using val_array = std::array<buffer_t, sizeof(uint_t)>;
    constexpr val_array expected{{{{std::byte{8}}}}};

    constexpr val_array result = []()
    {
        val_array tmp{};
        for (std::size_t i = 0; i < sizeof(uint_t); ++i)
        {
            store<eEndian::kBig>(tmp[i].data(), uint_t{0x8}, i + 1);
        }
        return tmp;
    }();

    static_assert(is_equal_arrays(expected, result));
}
