#pragma once

#include <ot/data_types.h>

namespace ot
{
namespace table
{

class head
{
public:
	/// 0x00010000 for version 1.0.
	float GetTableVersionNumber() const { return tableVersionNumber.GetValue(); }
	int_fast16_t GetTableVersionNumberInteger() const { return tableVersionNumber.GetInteger(); }
	uint_fast16_t GetTableVersionNumberFraction() const { return tableVersionNumber.GetFraction(); }
	
	float GetFontRevision() const { return fontRevision.GetValue(); }
	int_fast16_t GetFontRevisionInteger() const { return fontRevision.GetInteger(); }
	uint_fast16_t GetFontRevisionFraction() const { return fontRevision.GetFraction(); }
	
	uint_fast32_t GetCheckSumAdjustment() const { return checkSumAdjustment.GetValue(); }
	uint_fast32_t GetMagicNumber() const { return magicNumber.GetValue(); }
	uint_fast16_t GetFlags() const { return flags.GetValue(); }
	uint_fast16_t GetUnitsPerEm() const { return unitsPerEm.GetValue(); }
	uint_fast64_t GetCreated() const { return created.GetValue(); }
	uint_fast64_t GetModified() const { return modified.GetValue(); }
	int_fast16_t GetXMin() const { return xMin.GetValue(); }
	int_fast16_t GetYMin() const { return yMin.GetValue(); }
	int_fast16_t GetXMax() const { return xMax.GetValue(); }
	int_fast16_t GetYMax() const { return yMax.GetValue(); }
	uint_fast16_t GetMacStyle() const { return macStyle.GetValue(); }
	uint_fast16_t GetLowestRecPPEM() const { return lowestRecPPEM.GetValue(); }
	int_fast16_t GetFontDirectionHint() const { return fontDirectionHint.GetValue(); }
	int_fast16_t GetIndexToLocFormat() const { return indexToLocFormat.GetValue(); }
	int_fast16_t GetGlyphDataFormat() const { return glyphDataFormat.GetValue(); }

private:
	ot::data_type::Fixed tableVersionNumber;
	ot::data_type::Fixed fontRevision; // Set by font manufacturer.
	ot::data_type::ULONG checkSumAdjustment; // To compute: set it to 0, sum the entire font as ULONG, then store 0xB1B0AFBA - sum.
	ot::data_type::ULONG magicNumber; // Set to 0x5F0F3CF5.
	
	// Bit 0: Baseline for font at y=0;
	// Bit 1: Left sidebearing point at x=0;
	// Bit 2: Instructions may depend on point size;
	// Bit 3: Force ppem to integer values for all internal scaler math; may use fractional ppem sizes if this bit is clear;
	// Bit 4: Instructions may alter advance width (the advance widths might not scale linearly);
	// Bits 5-10: These should be set according to Apple's specification . However, they are not implemented in OpenType.
	// Bit 11: Font data is 'lossless,' as a result of having been compressed and decompressed with the Agfa MicroType Express engine.
	// Bit 12: Font converted (produce compatible metrics)
	// Bit 13: Font optimized for ClearType™. Note, fonts that rely on embedded bitmaps (EBDT) for rendering should not be considered optimized for ClearType, and therefore should keep this bit cleared.
	// Bit 14: Last Resort font. If set, indicates that the glyphs encoded in the cmap subtables are simply generic symbolic representations of code point ranges and don’t truly represent support for those code points. If unset, indicates that the glyphs encoded in the cmap subtables represent proper support for those code points.
	// Bit 15: Reserved, set to 0
	ot::data_type::USHORT flags;
	
	ot::data_type::USHORT unitsPerEm; // Valid range is from 16 to 16384. This value should be a power of 2 for fonts that have TrueType outlines.
	ot::data_type::LONGDATETIME created; // Number of seconds since 12:00 midnight, January 1, 1904. 64-bit integer
	ot::data_type::LONGDATETIME modified; // Number of seconds since 12:00 midnight, January 1, 1904. 64-bit integer
	ot::data_type::SHORT xMin; // For all glyph bounding boxes.
	ot::data_type::SHORT yMin; // For all glyph bounding boxes.
	ot::data_type::SHORT xMax; // For all glyph bounding boxes.
	ot::data_type::SHORT yMax; // For all glyph bounding boxes.
	
	// Bit 0: Bold (if set to 1);
	// Bit 1: Italic (if set to 1)
	// Bit 2: Underline (if set to 1)
	// Bit 3: Outline (if set to 1)
	// Bit 4: Shadow (if set to 1)
	// Bit 5: Condensed (if set to 1)
	// Bit 6: Extended (if set to 1)
	// Bits 7-15: Reserved (set to 0).
	ot::data_type::USHORT macStyle;
	
	ot::data_type::USHORT lowestRecPPEM; // Smallest readable size in pixels.
	
	// Deprecated (Set to 2).
	// 0: Fully mixed directional glyphs;
	// 1: Only strongly left to right;
	// 2: Like 1 but also contains neutrals;
	// -1: Only strongly right to left;
	// -2: Like -1 but also contains neutrals.
	ot::data_type::SHORT fontDirectionHint;
	
	ot::data_type::SHORT indexToLocFormat; // 0 for short offsets, 1 for long.
	ot::data_type::SHORT glyphDataFormat; // 0 for current format.
};

}
}
