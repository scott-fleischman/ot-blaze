#pragma once

#include <array>

namespace
{
	
template<typename T, std::size_t N>
T GetValueFromBigEndianBytes(std::array<uint8_t, N> bytes)
{
	T value = 0;
	for (std::size_t index = 0; index < N; index++)
	{
		value <<= 8;
		value |= bytes[index];
	}
	return value;
}

}

namespace ot
{
	
class be_uint32_t
{
public:
	be_uint32_t(std::array<uint8_t, 4> bytes)
		: m_bytes(bytes)
	{
	}
	
	uint32_t GetValue() const
	{
		return GetValueFromBigEndianBytes<uint32_t>(m_bytes);
	}
	
private:
	std::array<uint8_t, 4> m_bytes;
};
	
class be_int32_t
{
public:
	be_int32_t(std::array<uint8_t, 4> bytes)
	: m_bytes(bytes)
	{
	}
	
	int32_t GetValue() const
	{
		return GetValueFromBigEndianBytes<int32_t>(m_bytes);
	}
	
private:
	std::array<uint8_t, 4> m_bytes;
};

}
