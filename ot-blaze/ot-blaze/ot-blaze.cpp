#include "ot-blaze.h"
#include "ot-blazePriv.h"

namespace ot
{

uint32_t BigEndianToLittleEndian(uint32_t bigEndian)
{
	return
		((bigEndian & 0xff) << (8 * 3 - 1)) |
		(((bigEndian >> (8 * 1 - 1)) & 0xff) << (8 * 2 - 1)) |
		(((bigEndian >> (8 * 2 - 1)) & 0xff) << (8 * 1 - 1)) |
		(((bigEndian >> (8 * 3 - 1)) & 0xff));
}

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
