#pragma once

#include <ot/data_type/big_endian.h>
#include <ot/data_type/fixed_point.h>

#include <climits>

static_assert(CHAR_BIT == 8, "Bytes must be 8 bits");

namespace ot
{
namespace data_type
{

using BYTE = uint8_t;
static_assert(sizeof(BYTE) == 1, "BYTE must be 1 byte");

using CHAR = int8_t;
static_assert(sizeof(BYTE) == 1, "CHAR must be 1 byte");

using USHORT = big_endian<uint_fast16_t, 2>;
static_assert(sizeof(USHORT) == 2, "USHORT must be 2 bytes");

using SHORT = big_endian<int_fast16_t, 2>;
static_assert(sizeof(SHORT) == 2, "SHORT must be 2 bytes");

using UINT24 = big_endian<uint_fast32_t, 3>;
static_assert(sizeof(UINT24) == 3, "UINT24 must be 3 bytes");

using ULONG = big_endian<uint_fast32_t, 4>;
static_assert(sizeof(ULONG) == 4, "ULONG must be 4 bytes");

using LONG = big_endian<int_fast32_t, 4>;
static_assert(sizeof(LONG) == 4, "LONG must be 4 bytes");

using FWORD = big_endian<int_fast16_t, 2>;
static_assert(sizeof(FWORD) == 2, "FWORD must be 2 bytes");
	
using UFWORD = big_endian<uint_fast16_t, 2>;
static_assert(sizeof(UFWORD) == 2, "UFWORD must be 2 bytes");
	
using LONGDATETIME = big_endian<int_fast64_t, 8>;
static_assert(sizeof(LONGDATETIME) == 8, "LONGDATETIME must be 8 bytes");

using Tag = big_endian<uint_fast32_t, 4>;
static_assert(sizeof(Tag) == 4, "Tag must be 4 bytes");

using GlyphId = big_endian<uint_fast16_t, 2>;
static_assert(sizeof(GlyphId) == 2, "GlyphId must be 2 bytes");

using Offset = big_endian<uint_fast16_t, 2>;
static_assert(sizeof(Offset) == 2, "Offset must be 2 bytes");

}
}
