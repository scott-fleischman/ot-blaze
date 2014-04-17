#pragma once

namespace ot
{
namespace data_type
{

template<typename TInteger, typename TFraction, size_t SFraction>
class FixedPoint
{
public:
	FixedPoint()
		: m_integer { 0 }
		, m_fraction { 0 }
	{
	}

	FixedPoint(TInteger integer, TFraction fraction)
		: m_integer { integer }
		, m_fraction { fraction }
	{
	}
	
	TInteger GetInteger() { return m_integer; }
	TFraction GetFraction() { return m_fraction; }

private:
	TInteger m_integer;
	TFraction m_fraction;
};

template<typename T>
constexpr T GetAndMask(size_t bits)
{
	T result = 0;
	for (; bits != 0; --bits)
	{
		result <<= 1;
		result |= 1;
	}
	return result;
}

template<typename TRaw, typename TInteger, typename TFraction, size_t SFraction>
FixedPoint<TInteger, TFraction, SFraction> CreateFixedPoint(TRaw raw)
{
	return FixedPoint<TInteger, TFraction, SFraction>(
		static_cast<TInteger>(raw >> SFraction),
		static_cast<TFraction>(raw & GetAndMask<TRaw>(SFraction)));
}
	
}
}
