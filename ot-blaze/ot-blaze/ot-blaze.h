#pragma once

// The classes below are exported
#pragma GCC visibility push(default)

#include <cstdint>

#include "ot/big_endian.h"
#include "ot/data_types.h"

namespace ot
{

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
