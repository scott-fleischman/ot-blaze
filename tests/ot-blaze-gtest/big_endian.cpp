#include <gtest/gtest.h>

#include <ot/data_type/big_endian.h>

template<typename T, size_t S>
void TestBigEndian(T expected, std::array<uint8_t, S> bytes)
{
	auto big_endian = ot::data_type::big_endian<T, S> { bytes };
	EXPECT_EQ(expected, big_endian.GetValue());
}

TEST(BigEndian, 4Byte_uint_fast32_t)
{
	TestBigEndian<uint_fast32_t, 4>(0x04030201, { 0x04, 0x03, 0x02, 0x01 });
}

TEST(BigEndian, 4Byte_int_fast32_t)
{
	TestBigEndian<int_fast32_t, 4>(0x04030201, { 0x04, 0x03, 0x02, 0x01 });
}

TEST(BigEndian, 4Byte_Negative_int_fast32_t)
{
	TestBigEndian<int_fast32_t, 4>(-2, { 0xff, 0xff, 0xff, 0xfe });
}

TEST(BigEndian, 3Byte_uint_fast32_t)
{
	TestBigEndian<uint_fast32_t, 3>(0x00030201, { 0x03, 0x02, 0x01 });
}
