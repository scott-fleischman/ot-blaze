#include <big_endian.h>
#include <gtest/gtest.h>

TEST(BigEndian, Uint32)
{
	auto bytes = std::array<uint8_t, 4> { 0x04, 0x03, 0x02, 0x01 };
	auto big_endian = ot::big_endian<uint32_t> { bytes };
	uint32_t expected = 0x04030201;
	EXPECT_EQ(expected, big_endian.GetValue());
}

TEST(BigEndian, Int32)
{
	auto bytes = std::array<uint8_t, 4> { 0x04, 0x03, 0x02, 0x01 };
	auto big_endian = ot::big_endian<int32_t> { bytes };
	int32_t expected = 0x04030201;
	EXPECT_EQ(expected, big_endian.GetValue());
}

TEST(BigEndian, NegativeInt32)
{
	auto bytes = std::array<uint8_t, 4> { 0xff, 0xff, 0xff, 0xfe };
	auto big_endian = ot::big_endian<int32_t> { bytes };
	int32_t expected = -2;
	EXPECT_EQ(expected, big_endian.GetValue());
}

TEST(BigEndian, Uint16)
{
	auto bytes = std::array<uint8_t, 2> { 0x02, 0x01 };
	auto big_endian = ot::big_endian<uint16_t> { bytes };
	uint16_t expected = 0x0201;
	EXPECT_EQ(expected, big_endian.GetValue());
}

TEST(BigEndian, Int16)
{
	auto bytes = std::array<uint8_t, 2> { 0x02, 0x01 };
	auto big_endian = ot::big_endian<int16_t> { bytes };
	int16_t expected = 0x0201;
	EXPECT_EQ(expected, big_endian.GetValue());
}

TEST(BigEndian, NegativeInt16)
{
	auto bytes = std::array<uint8_t, 2> { 0xff, 0xfe };
	auto big_endian = ot::big_endian<int16_t> { bytes };
	int16_t expected = -2;
	EXPECT_EQ(expected, big_endian.GetValue());
}

