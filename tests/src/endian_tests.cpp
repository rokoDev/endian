#include <gtest/gtest.h>

#include "endian/endian.h"

TEST(EndianTest, AssumedEndianValueEqualActual)
{
    ASSERT_EQ(endian::kValue /*assumed endian value*/,
              endian::value() /*actual endian value*/);
}

TEST(EndianTest, AssumedEndianNameEqualActual)
{
    ASSERT_EQ(endian::kName /*assumed endian name*/,
              endian::name() /*actual endian name*/);
}
