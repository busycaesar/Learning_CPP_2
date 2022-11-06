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

#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H

// REQUIRED HEADER FILES.
#include<vector>
#include"Vehicle.h"
#include<list>	

namespace sdds
{

	// CLASS.
	class Autoshop
	{

		// CLASS NAME AND PURPOSE.
		// NAME: AUTOSHOP
		// PURPOSE: TO STORE THE ARRAY OF VEHICLES.

		// DATA MEMBERS.
		std::vector<Vehicle*> data_vehicles;

	public:

		// METHODS.

		// CONSTRUCTORS AND DESTRUCTOR.
		~Autoshop();

		// OPERATORS.
		Autoshop& operator+=(Vehicle* arg_new_vehicle);

		// QUERIES.
		// VOID.

		// METHODS.
		void display(std::ostream& arg_out)const;
		template<typename T>
		void select(T test, std::list<const Vehicle*>& vehicles)
		{

			for (auto& i : data_vehicles)
			{

				if (test(i)) vehicles.push_back(i);

			}

		}

		// HELPER FUNCTIONS.
		// VOID.

	};

}

#endif // !SDDS_AUTOSHOP_H
