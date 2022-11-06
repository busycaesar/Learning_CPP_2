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

#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H

// REQUIRED HEADER FILES.
#include"Car.h"

namespace sdds
{

	// CLASS.
	class Racecar : public Car
	{

		// CLASS NAME AND PURPOSE.
		// NAME: RACECAR
		// PURPOSE: RACECAR IS A CAR WHICH CAN BOOST ITS SPEED MORE THAN TOP SPEED.

		// DATA MEMBERS.

		// INSTANCE VARIABLES.
		double data_booster;

		// CLASS VARAIBLES.

		// METHODS.
		void set_empty() { data_booster = 0; }

	public:

		// METHODS.

		// CONSTRUCTORS AND DESTRUCTOR.
		Racecar() { set_empty(); }
		Racecar(std::istream& in);

		// OPERATORS.
		// VOID.

		// CLASS FUNCTIONS.
		// VOID.

		// QUERIES.
		double topSpeed()const { return Car::topSpeed() * (1 + data_booster); }

		// METHODS.
		void display(std::ostream& arg_out) const;

		// HELPER FUNCTIONS.
		// VOID.

	};

}

#endif // !SDDS_RACECAR_H
