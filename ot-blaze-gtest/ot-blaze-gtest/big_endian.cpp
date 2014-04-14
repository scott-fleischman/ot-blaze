#include <big_endian.h>
#include <gtest/gtest.h>

TEST(BigEndian, Uint32)
{
	auto bytes = std::array<uint8_t, 4> { 0x04, 0x03, 0x02, 0x01 };
	auto big_endian = ot::big_endian<uint32_t> { bytes };
	EXPECT_EQ(0x01020304, big_endian.GetValue());
}
