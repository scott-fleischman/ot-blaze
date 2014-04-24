#pragma once

namespace ot
{
namespace table
{

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

}
}
