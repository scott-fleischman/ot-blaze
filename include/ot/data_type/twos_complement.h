#pragma once

#include <type_traits>

namespace ot
{
namespace data_type
{

template<typename T>
constexpr T IntegralPower(T value, T power)
{
	static_assert(std::is_arithmetic<T>::value, "T is not arithmetic");
	
	return power == 0 ? 1 : IntegralPower<T>(value, power - 1) * value;
}

template<typename TUnsigned, size_t bits>
constexpr typename std::make_signed<TUnsigned>::type GetTwosComplementSignedValue(TUnsigned unsignedValue)
{
	using TSigned = typename std::make_signed<TUnsigned>::type;
	
	static_assert(std::is_unsigned<TUnsigned>::value, "TUnsigned is not unsigned");
	static_assert(std::is_arithmetic<TUnsigned>::value, "TUnsigned is not arithmetic");
	
	return unsignedValue < IntegralPower<TUnsigned>(2, bits - 1) ?
		static_cast<TSigned>(unsignedValue) :
		static_cast<TSigned>(0) - static_cast<TSigned>(IntegralPower<TUnsigned>(2, bits) - unsignedValue);
}

}
}
