#pragma once

#include <array>

class be_uint32_t
{
public:
	be_uint32_t(std::array<uint8_t, 4> bytes)
	: m_bytes(bytes)
	{
	}
	
	uint32_t GetValue() const
	{
		return
		(m_bytes[0] << (8 * 3 - 1)) |
		(m_bytes[1] << (8 * 2 - 1)) |
		(m_bytes[2] << (8 * 1 - 1)) |
		(m_bytes[3]);
	}
	
private:
	std::array<uint8_t, 4> m_bytes;
};
