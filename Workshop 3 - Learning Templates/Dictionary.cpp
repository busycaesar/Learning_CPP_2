#define _CRT_SECURE_NO_WARNINGS

#include"Dictionary.h"

namespace sdds
{

	std::ostream& Dictionary::display(std::ostream& out)const
	{

		out << std::setw(20) << std::right << m_term << ": " << m_definition;

		return out;

	}

	std::ostream& operator<<(std::ostream& out, const Dictionary source)
	{

		return source.display(out);

	}

}