#include <gtest/gtest.h>

#include <ot/data_type/twos_complement.h>

template<typename TUnsigned, typename TSigned, size_t bits>
void TestTwosComplement(TSigned expected, TUnsigned value)
{
	auto twosComplement = ot::data_type::twos_complement<TUnsigned, TSigned, bits> { value };
	EXPECT_EQ(expected, twosComplement.GetSignedValue());
}

TEST(TwosComplement, 4bit_minus1)
{
	TestTwosComplement<uint_fast8_t, int_fast8_t, 4>(-1, 0b1111);
}

TEST(TwosComplement, 4bit_minus8)
{
	TestTwosComplement<uint_fast8_t, int_fast8_t, 4>(-8, 0b1000);
}

TEST(TwosComplement, 4bit_zero)
{
	TestTwosComplement<uint_fast8_t, int_fast8_t, 4>(0, 0);
}

TEST(TwosComplement, 4bit_plus7)
{
	TestTwosComplement<uint_fast8_t, int_fast8_t, 4>(7, 0b0111);
}

TEST(TwosComplement, 8bit_minus1)
{
	TestTwosComplement<uint_fast8_t, int_fast8_t, 8>(-1, 0b11111111);
}

TEST(TwosComplement, 8bit_minus128)
{
	TestTwosComplement<uint_fast8_t, int_fast8_t, 8>(-128, 0b10000000);
}

TEST(TwosComplement, 8bit_zero)
{
	TestTwosComplement<uint_fast8_t, int_fast8_t, 8>(0, 0);
}

TEST(TwosComplement, 8bit_plus127)
{
	TestTwosComplement<uint_fast8_t, int_fast8_t, 8>(127, 0b01111111);
}
