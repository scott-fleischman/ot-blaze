#include <data_types.h>
#include <gtest/gtest.h>

TEST(DataTypes, BigEndianUint24)
{
	auto bytes = std::array<uint8_t, 3> { 0x03, 0x02, 0x01 };
	auto big_endian = ot::big_endian_uint24 { bytes };
	uint32_t expected = 0x030201;
	EXPECT_EQ(expected, big_endian.GetValue());
}
