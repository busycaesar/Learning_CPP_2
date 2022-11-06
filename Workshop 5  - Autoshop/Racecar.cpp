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

#include"Racecar.h"

namespace sdds
{

	Racecar::Racecar(std::istream& in) : Car(in)
	{

		// VARIABLE DECLARATION.
		std::string data = "";

		set_empty();

		if (in)
		{

			in.seekg(std::ios_base::beg);
			std::getline(in, data);

			garbage_data_till(data, 4, ',');
			trim_word(data);
			data_booster = stod(data);

		}

	}

	void Racecar::display(std::ostream& arg_out)const
	{

			Car::display(arg_out);
			arg_out << "*";

	}

}