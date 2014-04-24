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
