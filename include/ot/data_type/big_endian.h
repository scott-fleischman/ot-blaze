#pragma once

#include <array>
#include <numeric>

#include "twos_complement.h"

namespace ot
{
namespace data_type
{
	
template<typename T, size_t S>
T GetBigEndianValue(std::array<uint8_t, S> bytes)
{
	static_assert(sizeof(T) >= S, "sizeof(T) must be >= S");
	
	return std::accumulate(bytes.begin(), bytes.end(), 0, [](const T accumulator, const uint8_t byte) { return (accumulator << 8) | byte; });
}

template<typename TUnsigned, size_t byteCount>
class big_endian
{
	static_assert(sizeof(TUnsigned) >= byteCount, "sizeof(TUnsigned) must be >= byteCount");
	static_assert(std::is_arithmetic<TUnsigned>::value, "TUnsigned must be arithmetic");
	static_assert(std::is_unsigned<TUnsigned>::value, "TUnsigned must be unsigned");

public:
	big_endian(std::array<uint8_t, byteCount> bytes)
		: m_bytes(bytes)
	{
	}
	
	TUnsigned GetValue() const
	{
		return GetBigEndianValue<TUnsigned, byteCount>(m_bytes);
	}

private:
	std::array<uint8_t, byteCount> m_bytes;
};

template<typename TSigned, size_t byteCount>
class signed_big_endian
{
	static_assert(sizeof(TSigned) >= byteCount, "sizeof(TSigned) must be >= byteCount");
	static_assert(std::is_arithmetic<TSigned>::value, "TSigned must be arithmetic");
	static_assert(std::is_signed<TSigned>::value, "TSigned must be signed");
	
	using TUnsigned = typename std::make_unsigned<TSigned>::type;

public:
	signed_big_endian(std::array<uint8_t, byteCount> bytes)
		: m_bytes(bytes)
	{
	}

	TSigned GetValue() const
	{
		TUnsigned unsignedValue = GetBigEndianValue<TUnsigned>(m_bytes);
		return GetTwosComplementSignedValue<TUnsigned, byteCount * 8>(unsignedValue);
	}

private:
	std::array<uint8_t, byteCount> m_bytes;
};
	
}
}
