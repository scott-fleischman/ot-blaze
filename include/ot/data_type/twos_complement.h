#pragma once

namespace ot
{
namespace data_type
{

template<typename T>
constexpr T IntegralPower(T value, T power)
{
	return power == 0 ? 1 : IntegralPower<T>(value, power - 1) * value;
}

template<typename TUnsigned, typename TSigned, size_t bits>
class twos_complement
{
public:
	explicit twos_complement(TUnsigned unsignedValue)
		: m_unsignedValue { unsignedValue }
	{
	}
	
	TSigned GetSignedValue()
	{
		if (m_unsignedValue < IntegralPower<TUnsigned>(2, bits - 1))
			return m_unsignedValue;
		
		TSigned signedValue = 0;
		return signedValue - (IntegralPower<TUnsigned>(2, bits) - m_unsignedValue);
	}

private:
	TUnsigned m_unsignedValue;
};

}
}
