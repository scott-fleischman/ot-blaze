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

const cmap_encoding_record * begin(const cmap_header & header)
{
	const uint8_t * pData = reinterpret_cast<const uint8_t *>(&header);
	pData += sizeof(cmap_header);
	return reinterpret_cast<const cmap_encoding_record *>(pData);
}

const cmap_encoding_record * end(const cmap_header & header)
{
	return begin(header) + header.GetNumTables();
}

}
}
