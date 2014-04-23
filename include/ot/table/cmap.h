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
	ot::data_type::USHORT version;
	ot::data_type::USHORT numTables;
};

class cmap_encoding_record
{
public:
	ot::data_type::USHORT platformID; // Platform ID.
	ot::data_type::USHORT encodingID; // Platform-specific encoding ID.
	ot::data_type::ULONG offset; // Byte offset from beginning of table to the subtable for this encoding.
};

}
}
