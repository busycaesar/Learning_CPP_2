//******************************************************************//
//                                                                  //
// NAME       : DEV JIGISHKUMAR SHAH                                // 
// STUDENT ID : 131623217                                           //
// MAIL ID    : djshah11@myseneca.ca                                //
// COURSE     : OOP 345 NFF                                         //
// SUBMISSION :                                    //
//                                                                  //
//******************************************************************// 
//                                                                  //
// AUTHENTICITY DECLARATION :                                       //
// I HAVE DONE ALL THE CODING BY MYSELF AND ONLY COPIED THE CODE    //
// THAT MY PROFESSOR PROVIDED TO COMPLETE MY WORKSHOPS AND			//
// ASSIGNMENTS.													    //
//                                                                  //
//******************************************************************//

#include"carads.h"

namespace sdds
{

	void listArgs(int argc, char* argv[])
	{

		std::cout << "Command Line" << std::endl << "--------------------------";

		for (int i = 0; i < argc; i++)std::cout << i << ": " << argv[i] << std::endl;

	}

	Cars::Cars()
	{

		setEmpty();

	}

	void Cars::setEmpty()
	{

		m_brand[0] = '\0';
		m_model[0] = '\0';
		m_carStatus = nullptr;
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

			is.getline(m_carStatus, 1, ',');
			is.getline(m_brand, 9, ',');
			is.getline(m_model, 14, ',');
			is >> m_manuYear;
			is >> m_price;
			is.getline(&f_discount, 1, '\n');

			switch (f_discount)
			{

			case 'Y':
				m_isDiscount = true;
				break;
			case 'N':
				m_isDiscount = false;
				break;
			}

		}

	}

	void Cars::display(bool reset)
	{

		static int f_counter = 0;

		if (m_brand[0] = '\0')
		{

			std::cout << std::left << std::setw(2) << f_counter++ << std::left << std::setw(10) << m_brand << " | " << std::left << std::setw(15) << m_model << " | " << std::setw(7) << m_manuYear << " | " << std::left << std::setw(7);
			std::cout << std::setprecision(2) << m_price + g_taxrate;

			if (m_isDiscount)std::cout << std::right << std::setw(12) << (m_price + g_taxrate) - g_discount;

			std::cout << std::endl;

		}
		else
		{

			std::cout << f_counter++ << " No Car" << std::endl;

		}

		if (reset)f_counter = 0;

	}

	char Cars::getStatus()
	{

		return *m_carStatus;

	}

}