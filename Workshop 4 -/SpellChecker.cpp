#define _CRT_SECURE_NO_WARNINGS

#include"SpellChecker.h"

namespace sdds
{

	void SpellChecker::setEmpty()
	{

		for (size_t i = 0; i < 6; i++)
		{

			m_badWords[i] = "";
			m_goodWords[i] = "";
			m_repeat[i] = 0;

		}

	}

	SpellChecker::SpellChecker()
	{

		setEmpty();

	}

	SpellChecker::SpellChecker(const char* f_filename)
	{

		if (f_filename != nullptr)
		{

			// VARIABLE DECLARATION.
			std::ifstream t_file(f_filename);
			std::string t_temp = "";
			size_t i = 0;

			setEmpty();

			if (t_file)
			{

				while (std::getline(t_file, t_temp))
				{

					m_badWords[i] = getData(t_temp, ' ');
					m_goodWords[i++] = trimWord(getLength(t_temp), t_temp);

				}

			}
			else std::cerr << "Bad file name!";

		}

	}

	void SpellChecker::operator()(std::string& text)
	{

		// VARIABLE DECLARATION.
		std::string t_data = text;
		size_t t_length = getLength(t_data), t_start = 0;

		// THIS WILL ITERATE ALL THE BAD WORDS AND REPLACE THEM FROM THE TEXT IF IT IS FOUND..
		for (size_t i = 0; i < 6; i++)
		{

			if (replaceWord(text, m_badWords[i], m_goodWords[i]))m_repeat[i] = +1;

		}

	}

	void SpellChecker::showStatistics(std::ostream& out) const
	{

		for (size_t i = 0; i < 6; i++) out << std::setw(15) << std::right << m_badWords[i] << ": " << m_repeat[i] << " replacements" << std::endl;

	}

}