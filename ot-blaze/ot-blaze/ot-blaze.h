#pragma once

// The classes below are exported
#pragma GCC visibility push(default)

#include <cstdint>
#include <be_uint32_t.h>

namespace ot
{

uint32_t BigEndianToLittleEndian(uint32_t bigEndian);
	
class fixed16d16_t
{
public:
	explicit fixed16d16_t(int32_t littleEndian) : m_value { littleEndian } { };
	
	int16_t integer() const;
	uint16_t decimal() const;
	
private:
	int32_t m_value;
};
	
class HorizontalMetric
{
public:
private:
	uint16_t m_advanceWidth;
	int16_t m_leftSideBearing;
};

}

#pragma GCC visibility pop
