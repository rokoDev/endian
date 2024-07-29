#include <endian/endian.h>
#include <gtest/gtest.h>

TEST(EndianTest, AssumedEndianValueEqualToNative)
{
    ASSERT_EQ(endian::eEndian::kNative /*assumed endian value*/,
              endian::native_endian() /*actual endian value*/);
}
