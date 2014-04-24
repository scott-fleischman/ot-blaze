#pragma once

#pragma once

#include <ot/data_types.h>

namespace ot
{
namespace table
{

class cmap_header
{
public:
	uint_fast16_t GetVersion() const { return version.GetValue(); }
	uint_fast16_t GetNumTables() const { return numTables.GetValue(); }

private:
	ot::data_type::USHORT version;
	ot::data_type::USHORT numTables;
};

class cmap_encoding_record
{
public:
	uint_fast16_t GetPlatformID() const { return platformID.GetValue(); }
	uint_fast16_t GetEncodingID() const { return encodingID.GetValue(); }
	uint_fast32_t GetOffset() const { return offset.GetValue(); }

private:
	ot::data_type::USHORT platformID; // Platform ID.
	ot::data_type::USHORT encodingID; // Platform-specific encoding ID.
	ot::data_type::ULONG offset; // Byte offset from beginning of table to the subtable for this encoding.
};

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

template<typename T>
class pointer_array
{
public:
	explicit pointer_array(T * item, size_t length)
		: m_item { item }
		, m_length { length }
	{
	}

	T * begin() const
	{
		return m_item;
	}
	
	T * end() const
	{
		return m_item + m_length;
	}

private:
	T * m_item;
	size_t m_length;
};

class cmap_navigator
{
public:
	explicit cmap_navigator(const void * data)
		: m_data { static_cast<const uint8_t *>(data) }
	{
	}
	
	const cmap_header * GetHeader() const
	{
		return reinterpret_cast<const cmap_header *>(m_data);
	}
	
	const pointer_array<const cmap_encoding_record> GetRecords() const
	{
		const uint8_t * pRecordData = m_data + sizeof(cmap_header);
		size_t length = GetHeader()->GetNumTables();
		return pointer_array<const cmap_encoding_record> { reinterpret_cast<const cmap_encoding_record *>(pRecordData), length };
	}
	
	const uint_fast16_t GetFormat(const cmap_encoding_record & record) const
	{
		const uint8_t * pFormatData = m_data + record.GetOffset();
		return reinterpret_cast<const ot::data_type::USHORT *>(pFormatData)->GetValue();
	}

private:
	const uint8_t * m_data;
};

}
}
