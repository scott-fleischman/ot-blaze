#pragma once

#include "big_endian.h"

#include <climits>

static_assert(CHAR_BIT == 8, "Bytes must be 8 bits");

namespace ot
{
namespace data_type
{

using BYTE = uint8_t;
static_assert(sizeof(BYTE) == 1, "BYTE must be 1 byte");

using CHAR = int8_t;
static_assert(sizeof(BYTE) == 1, "CHAR must be 1 byte");

using USHORT = big_endian<uint_fast16_t, 2>;
static_assert(sizeof(USHORT) == 2, "USHORT must be 2 bytes");

using SHORT = big_endian<int_fast16_t, 2>;
static_assert(sizeof(SHORT) == 2, "SHORT must be 2 bytes");

using UINT24 = big_endian<uint_fast32_t, 3>;
static_assert(sizeof(UINT24) == 3, "UINT24 must be 3 bytes");

using ULONG = big_endian<uint_fast32_t, 4>;
static_assert(sizeof(ULONG) == 4, "ULONG must be 4 bytes");

using LONG = big_endian<int_fast32_t, 4>;
static_assert(sizeof(LONG) == 4, "LONG must be 4 bytes");

class Fixed
{
public:
	Fixed(std::array<uint8_t, 2> integer, std::array<uint8_t, 2> fraction)
		: m_integer(integer)
		, m_fraction(fraction)
	{
	}
	
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
	
	int_fast8_t GetMantissa() const
	{
		uint_fast16_t value = m_bytes.GetValue() >> 14;
		switch (value)
		{
			case 1:
				return 1;
			case 2:
				return -2;
			case 3:
				return -1;
			default:
				return 0;
		}
	}
	
	uint_fast16_t GetFraction() const { return m_bytes.GetValue() & 0b0011111111111111; }
	
private:
	big_endian<uint_fast16_t, 2> m_bytes;
};
static_assert(sizeof(F2DOT14) == 2, "F2DOT14 must be 2 bytes");

using LONGDATETIME = int64_t;
static_assert(sizeof(LONGDATETIME) == 8, "LONGDATETIME must be 8 bytes");

class Tag
{
private:
	std::array<uint8_t, 4> m_bytes;
};
static_assert(sizeof(Tag) == 4, "Tag must be 4 bytes");

using GlyphId = uint16_t;
static_assert(sizeof(GlyphId) == 2, "GlyphId must be 2 bytes");

using Offset = uint16_t;
static_assert(sizeof(Offset) == 2, "Offset must be 2 bytes");

}
}
