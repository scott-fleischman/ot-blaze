#pragma once

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

}
}
