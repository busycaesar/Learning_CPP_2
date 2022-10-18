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

#include"Book.h"

namespace sdds
{

	std::ostream& Book::display(std::ostream& out)const
	{

		out
			<< std::setw(20) << m_author << " | "
			<< std::setw(22) << m_title << " | "
			<< std::setw(5) << m_country << " | "
			<< std::setw(4) << m_year << " | "
			<< std::setw(6) << std::fixed << std::setprecision(2)
			<< m_price << " | "
			<< m_description << std::endl;

		return out;

	}

	void Book::setEmpty()
	{

		m_author = "";
		m_title = "";
		m_country = "";
		m_description = "";
		m_year = 0;
		m_price = 0;

	}

	Book::Book()
	{

		setEmpty();

	}

	Book::Book(const std::string& f_data)
	{

		// VARIABLE DECLARATION.
		std::string t_data = f_data, t_temp = "";

		setEmpty();

		if (t_data != "")
		{

			m_author = getData(t_data, ',');
			m_title = getData(t_data, ',');
			m_country = getData(t_data, ',');
			t_temp = getData(t_data, ',');
			m_price = stod(t_temp);
			t_temp = getData(t_data, ',');
			m_year = stoi(t_temp);
			m_description = trimWord(getLength(t_data), t_data);

		}

	}

	Book& Book::operator=(const Book& source)
	{

		if (this != &source)
		{

			m_author = source.m_author;
			m_title = source.m_title;
			m_country = source.m_country;
			m_description = source.m_description;
			m_year = source.m_year;
			m_price = source.m_price;

		}

		return *this;

	}

	const std::string& Book::title() const
	{

		return m_title;

	}

	const std::string& Book::country()const
	{

		return m_country;

	}

	const size_t& Book::year() const
	{

		return m_year;

	}

	double& Book::price()
	{

		return m_price;

	}

	std::ostream& operator<<(std::ostream& out, const Book& source)
	{

		return source.display(out);

	}

}