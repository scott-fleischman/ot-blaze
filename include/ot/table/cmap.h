#pragma once

#include <ot/data_types.h>

#include "const_array.h"
#include "cmap_header.h"
#include "cmap_encoding_record.h"

namespace ot
{
namespace table
{

class cmap
{
public:
	explicit cmap(const void * data)
		: m_data { static_cast<const uint8_t *>(data) }
	{
	}
	
	uint_fast16_t GetVersion() const { return GetHeader()->GetVersion(); }
	
	uint_fast16_t GetNumTables() const { return GetHeader()->GetNumTables(); }
	
	const cmap_header * GetHeader() const
	{
		return reinterpret_cast<const cmap_header *>(m_data);
	}
	
	const const_array<cmap_encoding_record> GetRecords() const
	{
		const uint8_t * pRecordData = m_data + sizeof(cmap_header);
		size_t length = GetHeader()->GetNumTables();
		return const_array<cmap_encoding_record> { reinterpret_cast<const cmap_encoding_record *>(pRecordData), length };
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
