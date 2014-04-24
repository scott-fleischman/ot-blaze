#pragma once

namespace ot
{
namespace table
{

class cmap_format4_header
{
public:
	uint_fast16_t GetFormat() const { return format.GetValue(); }
	uint_fast16_t GetLength() const { return length.GetValue(); }
	uint_fast16_t GetLanguage() const { return language.GetValue(); }
	uint_fast16_t GetSegCountX2() const { return segCountX2.GetValue(); }
	uint_fast16_t GetSearchRange() const { return searchRange.GetValue(); }
	uint_fast16_t GetEntrySelector() const { return entrySelector.GetValue(); }
	uint_fast16_t GetRangeShift() const { return rangeShift.GetValue(); }

private:
	ot::data_type::USHORT format; // Format number is set to 4.
	ot::data_type::USHORT length; // This is the length in bytes of the subtable.
	ot::data_type::USHORT language; // Please see “Note on the language field in 'cmap' subtables“ in this document.
	ot::data_type::USHORT segCountX2; // 2 x segCount.
	ot::data_type::USHORT searchRange; // 2 x (2**floor(log2(segCount)))
	ot::data_type::USHORT entrySelector; // log2(searchRange/2)
	ot::data_type::USHORT rangeShift; // 2 x segCount - searchRange
//	ot::data_type::USHORT endCount[segCount]; // End characterCode for each segment, last=0xFFFF.
//	ot::data_type::USHORT reservedPad; // Set to 0.
//	ot::data_type::USHORT startCount[segCount]; // Start character code for each segment.
//	ot::data_type::SHORT idDelta[segCount]; // Delta for all character codes in segment.
//	ot::data_type::USHORT idRangeOffset[segCount]; // Offsets into glyphIdArray or 0
//	ot::data_type::USHORT glyphIdArray[ ]; // Glyph index array (arbitrary length)
};

}
}
