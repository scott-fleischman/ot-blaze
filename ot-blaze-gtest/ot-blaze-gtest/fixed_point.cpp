#include <gtest/gtest.h>

#include <ot/data_type/fixed_point.h>

template<typename TRaw, typename TInteger, typename TFraction, size_t SFraction>
void TestFixedPoint(TInteger expectedInteger, TFraction expectedFraction, TRaw value)
{
	auto fixedPoint = ot::data_type::CreateFixedPoint<TRaw, TInteger, TFraction, SFraction>(value);
	EXPECT_EQ(expectedInteger, fixedPoint.GetInteger());
	EXPECT_EQ(expectedFraction, fixedPoint.GetFraction());
}

void TestFixed2pt14(int_fast8_t expectedInteger, uint_fast16_t expectedFraction, int_fast16_t raw)
{
	TestFixedPoint<int_fast16_t, int_fast8_t, uint_fast16_t, 14>(expectedInteger, expectedFraction, raw);
}

TEST(Fixed2pt14, 1pt999939)
{
	TestFixed2pt14(1, 16383, 0x7fff);
}

TEST(Fixed2pt14, 1pt75)
{
	TestFixed2pt14(1, 12288, 0x7000);
}

TEST(Fixed2pt14, 0pt000061)
{
	TestFixed2pt14(0, 1, 0001);
}

TEST(Fixed2pt14, 0pt0)
{
	TestFixed2pt14(0, 0, 0000);
}

TEST(Fixed2pt14, neg0pt000061)
{
	TestFixed2pt14(-1, 16383, 0xffff);
}

TEST(Fixed2pt14, neg2pt0)
{
	TestFixed2pt14(-2, 0, 0x8000);
}
