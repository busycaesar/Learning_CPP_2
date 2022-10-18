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

#include"Movie.h"

namespace sdds
{

	void Movie::setEmpty()
	{

		m_title = "";
		m_description = "";
		m_year = 0;

	}

	Movie::Movie()
	{

		setEmpty();

	}

	Movie::Movie(const std::string& f_strMovie)
	{

		// VARIABLE DESCRIPTION.
		std::string t_data = f_strMovie, t_temp = "";

		setEmpty();

		if (t_data != "")
		{

			m_title = getData(t_data, ',');
			t_temp = getData(t_data, ',');
			m_year = std::stoi(t_temp);
			m_description = trimWord(getLength(t_data), t_data);

		}

	}

	Movie& Movie::operator=(const Movie& source)
	{
	
		if (this!=&source)
		{

			m_title = source.m_title;
			m_year = source.m_year;
			m_description = source.m_description;

		}
	
		return *this;

	}

	const std::string& Movie::title() const
	{

		return m_title;

	}

	std::ostream& Movie::display(std::ostream& out)const
	{

		out << std::setw(40) << m_title << " | "
			<< std::setw(4) << m_year << " | "
			<< m_description << std::endl;

		return out;

	}

	std::ostream& operator<<(std::ostream& out, const Movie& source)
	{

		return source.display(out);

	}

}