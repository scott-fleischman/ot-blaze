#pragma once

#include <ot/data_types.h>

namespace ot
{
namespace table
{

class hhea
{
public:
	ot::data_type::Fixed tableVersionNumber;
	ot::data_type::FWORD ascender;
	ot::data_type::FWORD descender;
	ot::data_type::FWORD lineGap;
	ot::data_type::UFWORD advanceWidthMax;
	ot::data_type::FWORD minLeftSideBearing;
	ot::data_type::FWORD minRightSideBearing;
	ot::data_type::FWORD xMaxExtent;
	ot::data_type::SHORT caretSlopeRise;
	ot::data_type::SHORT caretSlopeRun;
	ot::data_type::SHORT caretOffset;
	ot::data_type::SHORT reserved1;
	ot::data_type::SHORT reserved2;
	ot::data_type::SHORT reserved3;
	ot::data_type::SHORT reserved4;
	ot::data_type::SHORT metricDataFormat;
	ot::data_type::USHORT numberOfHMetrics;
};
static_assert(sizeof(hhea) == 4 + 2*3 + 2 + 2*3 + 2*8 + 2, "sizeof(hhea) is not exact");

}
}
