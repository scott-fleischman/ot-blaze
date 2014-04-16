#pragma once

#include <ot/data_types.h>

namespace ot
{
namespace table
{

class head
{
public:
	ot::data_type::Fixed tableVersionNumber;
	ot::data_type::Fixed fontRevision;
	ot::data_type::ULONG checkSumAdjustment;
	ot::data_type::ULONG magicNumber;
	ot::data_type::USHORT flags;
	ot::data_type::USHORT unitsPerEm;
	ot::data_type::LONGDATETIME created;
	ot::data_type::LONGDATETIME modified;
	ot::data_type::SHORT xMin;
	ot::data_type::SHORT yMin;
	ot::data_type::SHORT xMax;
	ot::data_type::SHORT yMax;
	ot::data_type::USHORT macStyle;
	ot::data_type::USHORT lowestRecPPEM;
	ot::data_type::SHORT fontDirectionHint;
	ot::data_type::SHORT indexToLocFormat;
	ot::data_type::SHORT glyphDataFormat;
};

}
}
