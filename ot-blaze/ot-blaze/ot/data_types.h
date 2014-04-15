#pragma once

#include "big_endian.h"

namespace ot
{
	
class big_endian_uint24
{
public:
	big_endian_uint24(std::array<uint8_t, 3> bytes) : m_bytes(bytes) { }
	
	uint32_t GetValue() { return GetBigEndianValue<uint32_t, sizeof(m_bytes)>(m_bytes); }
	
private:
	std::array<uint8_t, 3> m_bytes;
};
	
}
