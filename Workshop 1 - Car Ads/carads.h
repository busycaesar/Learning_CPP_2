//******************************************************************//
//                                                                  //
// NAME       : DEV JIGISHKUMAR SHAH                                // 
// STUDENT ID : 131623217                                           //
// MAIL ID    : djshah11@myseneca.ca                                //
// COURSE     : OOP 345 NFF                                         //
// SUBMISSION : WORKSHOP - 1 (PART 1)                               //
//                                                                  //
//******************************************************************// 
//                                                                  //
// AUTHENTICITY DECLARATION :                                       //
// I HAVE DONE ALL THE CODING BY MYSELF AND ONLY COPIED THE CODE    //
// THAT MY PROFESSOR PROVIDED TO COMPLETE MY WORKSHOPS AND			//
// ASSIGNMENTS.													    //
//                                                                  //
//******************************************************************//

#ifndef SDDS_CARADS_H
#define SDDS_CARADS_H

#include<iostream>
#include<cstring>
#include<iomanip>

// VARIABLE DECLARATION.
extern double g_taxrate;
extern double g_discount;

namespace sdds
{


	void listArgs(int argc, char* argv[]);

	// CLASS.
	class Cars
	{

		// DATA MEMBERS.
		char m_brand[10], m_model[15];
		char* m_carStatus;
		int m_manuYear;
		double m_price;
		bool m_isDiscount;

	public:

		// CONSTRUCTOR.
		Cars();

		// MEMBER FUNCTION.
		void setEmpty();
		void read(std::istream& is);
		void display(bool reset);
		char getStatus()const;

	};

}

#endif // !SDDS_CARADS_H

