#include "ot-blaze.h"
#include "ot-blazePriv.h"

namespace ot
{

int16_t fixed16d16_t::integer() const
{
	int32_t shifted = m_value >> 15;
	return static_cast<int16_t>(shifted);
}
	
uint16_t fixed16d16_t::decimal() const
{
	return static_cast<uint16_t>(static_cast<uint32_t>(m_value) & 0xffff);
}

}
