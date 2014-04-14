#pragma once

#include <array>
#include <numeric>
#include <iostream>

namespace ot
{

template<typename T>
class big_endian
{
public:
	big_endian(std::array<uint8_t, sizeof(T)> bytes)
		: m_bytes(bytes)
	{
	}
	
	T GetValue() const
	{
		return std::accumulate(m_bytes.begin(), m_bytes.end(), 0,
			[](const T accumulator, const uint8_t byte) { return (accumulator << 8) | byte; });
	};

private:
	std::array<uint8_t, sizeof(T)> m_bytes;
};

}
