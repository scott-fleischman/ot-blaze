#include <gtest/gtest.h>

#include <ot/data_type/fixed_point.h>

void TestF2DOT14(int_fast8_t expectedInteger, uint16_t expectedFraction, float expectedFloat, std::array<uint8_t, 2> bytes)
{
	ot::data_type::F2DOT14 value { bytes };
	EXPECT_EQ(expectedInteger, value.GetInteger());
	EXPECT_EQ(expectedFraction, value.GetFraction());
	
	const float error = 0.0000001f;
	EXPECT_GE(value.GetValue(), expectedFloat - error);
	EXPECT_LE(value.GetValue(), expectedFloat + error);
}

TEST(F2DOT14, 1pt999939)
{
	TestF2DOT14(1, 16383, 1.999939f, { 0x7f, 0xff });
}

TEST(F2DOT14, 1pt75)
{
	TestF2DOT14(1, 12288, 1.75f, { 0x70, 0x0 });
}

TEST(F2DOT14, 0pt000061)
{
	TestF2DOT14(0, 1, 0.000061f, { 0x00, 0x01 });
}

TEST(F2DOT14, 0pt0)
{
	TestF2DOT14(0, 0, 0.0f, { 0x00, 0x00 });
}

TEST(F2DOT14, neg0pt000061)
{
	TestF2DOT14(-1, 16383, -0.000061f, { 0xff, 0xff });
}

TEST(F2DOT14, neg2pt0)
{
	TestF2DOT14(-2, 0, -2.0f, { 0x80, 0x00 });
}
