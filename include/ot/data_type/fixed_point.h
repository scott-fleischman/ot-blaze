#pragma once

#include <ot/data_type/big_endian.h>

#include "twos_complement.h"

namespace ot
{
namespace data_type
{

template<typename T>
constexpr T GetAndMask(size_t bits)
{
	return bits == 0 ? 0 : (GetAndMask<T>(bits - 1) << 1) | 1;
}

class Fixed
{
public:
	Fixed(std::array<uint8_t, 2> integer, std::array<uint8_t, 2> fraction)
		: m_integer(integer)
		, m_fraction(fraction)
	{
	}
	
	float GetValue() const { return m_integer.GetValue() + m_fraction.GetValue() / static_cast<float>(2 << 15); }
	int_fast16_t GetInteger() const { return m_integer.GetValue(); }
	uint_fast16_t GetFraction() const { return m_fraction.GetValue(); }
	
private:
	big_endian<int_fast16_t, 2> m_integer;
	big_endian<uint_fast16_t, 2> m_fraction;
};
static_assert(sizeof(Fixed) == 4, "Fixed must be 4 bytes");

class F2DOT14
{
public:
	F2DOT14(big_endian<uint_fast16_t, 2> bytes)
		: m_bytes(bytes)
	{
	}
	
	float GetValue() const { return GetInteger() + (GetFraction() / static_cast<float>(2 << 13)); }
	
	int_fast8_t GetInteger() const
	{
		return GetTwosComplementSignedValue<uint_least16_t, 2>(m_bytes.GetValue() >> 14);
	}
	
	uint_fast16_t GetFraction() const { return m_bytes.GetValue() & 0b0011111111111111; }
	
private:
	big_endian<uint_fast16_t, 2> m_bytes;
};
static_assert(sizeof(F2DOT14) == 2, "F2DOT14 must be 2 bytes");

	
}
}
