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

#define _CRT_SECURE_NO_WARNINGS

// REQUIRED HEADER FILES.
#include"Autoshop.h"

namespace sdds
{

	Autoshop::~Autoshop()
	{

		for (auto i = data_vehicles.begin(); i != data_vehicles.end(); i++) delete* i;

	}

	Autoshop& Autoshop::operator+=(Vehicle* arg_new_vehicle)
	{

		data_vehicles.push_back(arg_new_vehicle);

		return *this;

	}

	void Autoshop::display(std::ostream& arg_out)const
	{

		for (auto i = data_vehicles.begin(); i != data_vehicles.end(); i++)
		{

			(*i)->display(arg_out);
			arg_out << std::endl;

		}

	}

}