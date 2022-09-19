//******************************************************************//
//                                                                  //
// NAME       : DEV JIGISHKUMAR SHAH                                // 
// STUDENT ID : 131623217                                           //
// MAIL ID    : djshah11@myseneca.ca                                //
// COURSE     : OOP 345 NFF                                         //
// SUBMISSION : WORKSHOP - 1 (PART 2)                               //
//                                                                  //
//******************************************************************// 
//                                                                  //
// AUTHENTICITY DECLARATION :                                       //
// I HAVE DONE ALL THE CODING BY MYSELF AND ONLY COPIED THE CODE    //
// THAT MY PROFESSOR PROVIDED TO COMPLETE MY WORKSHOPS AND			//
// ASSIGNMENTS.													    //
//                                                                  //
//******************************************************************//

#define _CRT_SECURE_NO_WARNINGS

#include"carads.h"

namespace sdds
{

	void listArgs(int argc, char* argv[])
	{

		std::cout << "Command Line:" << std::endl << "--------------------------" << std::endl;

		for (int i = 0; i < argc; i++)std::cout << "  " << i + 1 << ": " << argv[i] << std::endl;

		std::cout << "--------------------------" << std::endl << std::endl;

	}

	Cars::Cars()
	{

		setEmpty();

	}

	Cars::Cars(const Cars& car)
	{

		setEmpty();
		*this = car;

	}

	Cars::~Cars()
	{

		delete[] m_brand;

	}

	void Cars::setEmpty()
	{

		m_brand = nullptr;
		m_model[0] = '\0';
		m_carStatus = '\0';
		m_manuYear = 0000;
		m_price = 0.0;
		m_isDiscount = false;

	}

	void Cars::read(std::istream& is)
	{

		if (is)
		{

			// VARIABLE DECLARATION.
			char f_discount = '\0';
			char f_temp[30];

			is >> m_carStatus;
			is.ignore();
			is.getline(f_temp, 29, ',');
			delete[] m_brand;
			m_brand = new char[strlen(f_temp) + 1];
			strcpy(m_brand, f_temp);
			is.getline(m_model, 15, ',');
			is >> m_manuYear;
			is.ignore();
			is >> m_price;
			is.ignore();
			is >> f_discount;
			is.ignore();

			if (f_discount == 'Y')
			{

				m_isDiscount = true;

			}
			else
			{

				m_isDiscount = false;

			}

		}

	}

	void Cars::display(bool reset)const
	{

		static int f_counter = 0;

		if (reset)f_counter = 0;

		if (m_brand[0] != '\0')
		{

			std::cout << std::setw(2) << std::left << ++f_counter << ". " << std::setw(10) << std::left << m_brand << "| " << std::setw(15) << std::left << m_model << "| " << std::setw(4) << std::right << m_manuYear << " |";
			std::cout << std::setw(12) << std::fixed << std::setprecision(2) << std::right << m_price * (g_taxrate + 1) << "|";

			if (m_isDiscount)
			{

				std::cout << std::setw(12) << std::fixed << std::setprecision(2) << std::right << m_price * (1 + g_taxrate) * (1 - g_discount);

			}

			std::cout << std::endl;

		}
		else
		{

			std::cout << "No Car" << std::endl;

		}


	}

	char Cars::getStatus()const
	{

		return m_carStatus;

	}

	Cars::operator bool()const
	{

		return m_carStatus == 'N';

	}

	Cars& Cars::operator=(const Cars& car)
	{

		if (this != &car)
		{

			delete[] m_brand;
			m_brand = new char[strlen(car.m_brand) + 1];
			strcpy(m_brand, car.m_brand);
			strcpy(m_model, car.m_model);
			m_carStatus = car.m_carStatus;
			m_manuYear = car.m_manuYear;
			m_isDiscount = car.m_isDiscount;
			m_price = car.m_price;

		}

		return *this;

	}

	void operator>>(const Cars& LO, Cars& RO)
	{

		RO = LO;

	}

	std::istream& operator>>(std::istream& in, Cars& car)
	{

		car.read(in);
		return in;

	}

}