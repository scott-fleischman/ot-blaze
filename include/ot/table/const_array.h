#pragma once


namespace ot
{
namespace table
{

// a read-only array with run-time length
template<typename T>
class const_array
{
public:
	explicit const_array(const T * begin, size_t length)
		: m_begin { begin }
		, m_end { begin + length }
	{
	}

	const T * begin() const
	{
		return m_begin;
	}
	
	const T * end() const
	{
		return m_end;
	}

private:
	const T * m_begin;
	const T * m_end;
};

}
}
