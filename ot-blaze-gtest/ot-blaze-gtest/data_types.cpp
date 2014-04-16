#include <gtest/gtest.h>

#include "ot/data_types.h"

void TestF2DOT14(int_fast8_t expectedMantissa, uint16_t expectedFraction, std::array<uint8_t, 2> bytes)
{
	ot::data_type::F2DOT14 value { bytes };
	EXPECT_EQ(expectedMantissa, value.GetMantissa());
	EXPECT_EQ(expectedFraction, value.GetFraction());
}

TEST(F2DOT14, 1pt999939)
{
	TestF2DOT14(1, 16383, { 0x7f, 0xff });
}

TEST(F2DOT14, 1pt75)
{
	TestF2DOT14(1, 12288, { 0x70, 0x0 });
}

TEST(F2DOT14, 0pt000061)
{
	TestF2DOT14(0, 1, { 0x00, 0x01 });
}

TEST(F2DOT14, 0pt0)
{
	TestF2DOT14(0, 0, { 0x00, 0x00 });
}

TEST(F2DOT14, neg0pt000061)
{
	TestF2DOT14(-1, 16383, { 0xff, 0xff });
}

TEST(F2DOT14, neg2pt0)
{
	TestF2DOT14(-2, 0, { 0x80, 0x00 });
}
