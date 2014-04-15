#pragma once

#include <array>
#include <numeric>

namespace ot
{
	
template<typename T>
T GetBigEndianValue(std::array<uint8_t, sizeof(T)> bytes)
{
	return std::accumulate(bytes.begin(), bytes.end(), 0,
		[](const T accumulator, const uint8_t byte) { return (accumulator << 8) | byte; });
}

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
		return GetBigEndianValue<T>(m_bytes);
	};

private:
	std::array<uint8_t, sizeof(T)> m_bytes;
};

}
