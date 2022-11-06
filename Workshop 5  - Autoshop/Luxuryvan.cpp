//******************************************************************//
//                                                                  //
// NAME       : DEV JIGISHKUMAR SHAH                                // 
// STUDENT ID : 131623217                                           //
// MAIL ID    : djshah11@myseneca.ca                                //
// COURSE     : OOP 345 NFF                                         //
// SUBMISSION : WORKSHOP 6 (PART 2)                                 //
//                                                                  //
//******************************************************************// 
//                                                                  //
// AUTHENTICITY DECLARATION :                                       //
// I HAVE DONE ALL THE CODING BY MYSELF AND ONLY COPIED THE CODE    //
// THAT MY PROFESSOR PROVIDED TO COMPLETE MY WORKSHOPS AND          //
// ASSIGNMENTS.                                                     //
//                                                                  //
//******************************************************************//

#include "Luxuryvan.h"

namespace sdds
{

	sdds::Luxuryvan::Luxuryvan(std::istream& in) : Van(in)
	{

		// VARAIBLE DECLARATION.
		std::string data = "";

		mthd_set_empty();

		if (in)
		{

			std::getline(in, data);

			garbage_data_till(data, 6, ',');
			trim_word(data);
			data_consumption = data;

		}

	}

	void sdds::Luxuryvan::display(std::ostream& out) const
	{

		Van::display(out);
		out << " electric van  *";

	}

}