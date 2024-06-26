//******************************************************************//
//                                                                  //
// NAME       : DEV JIGISHKUMAR SHAH                                // 
// STUDENT ID : 131623217                                           //
// MAIL ID    : djshah11@myseneca.ca                                //
// COURSE     : OOP 345 NFF                                         //
// SUBMISSION : WORKSHOP 5 (PART 2)                                 //
//                                                                  //
//******************************************************************// 
//                                                                  //
// AUTHENTICITY DECLARATION :                                       //
// I HAVE DONE ALL THE CODING BY MYSELF AND ONLY COPIED THE CODE    //
// THAT MY PROFESSOR PROVIDED TO COMPLETE MY WORKSHOPS AND          //
// ASSIGNMENTS.                                                     //
//                                                                  //
//******************************************************************//

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

		setEmpty();

		if (f_filename != nullptr)
		{

			// VARIABLE DECLARATION.
			std::ifstream t_file(f_filename);
			std::string t_temp = "";
			size_t i = 0;

			if (t_file)
			{

				while (std::getline(t_file, t_temp))
				{

					m_badWords[i] = getData(t_temp, ' ');
					m_goodWords[i++] = trimWord(getLength(t_temp), t_temp);

				}

			}
			else std::cerr << "** EXCEPTION: Bad file name!" << std::endl;

		}

	}

	void SpellChecker::operator()(std::string& text)
	{

		// VARIABLE DECLARATION.
		std::string t_data = text;
		bool t_error = true;

		// THIS WILL ITERATE ALL THE BAD WORDS AND REPLACE THEM FROM THE TEXT IF IT IS FOUND.
		if (m_badWords[0] != "")
		{
		
			for (size_t i = 0; i < 6; i++)
			{

				while (replaceWord(text, m_badWords[i], m_goodWords[i]))
				{

					m_repeat[i]++;

				}

			}
		
		}

	}

	void SpellChecker::showStatistics(std::ostream& out) const
	{

		if (m_badWords[0] != "")
		{

			out << "Spellchecker Statistics" << std::endl;

			for (size_t i = 0; i < 6; i++)
				out << std::setw(15) << std::right
				<< m_badWords[i] << ": "
				<< m_repeat[i] << " replacements"
				<< std::endl;

		}

	}

}