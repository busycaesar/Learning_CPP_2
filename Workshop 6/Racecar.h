#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H

#include"Car.h"

namespace sdds
{

	// CLASS.
	class Racecar :public Car
	{

		// CLASS NAME AND PURPOSE.
		// NAME: RACECAR
		// PURPOSE: RACECAR IS A CAR WHICH CAN BOOST ITS SPEED MORE THAN TOP SPEED.

		// DATA MEMBERS.

		// INSTANCE VARIABLES.
		double data_booster;

		// CLASS VARAIBLES.

		// METHODS.
		void mthd_set_empty() { data_booster = 0; }

	public:

		// METHODS.

		// CONSTRUCTORS AND DESTRUCTOR.
		Racecar() { mthd_set_empty(); }
		Racecar(std::istream& in);

		// OPERATORS.
		// VOID.

		// CLASS FUNCTIONS.
		// VOID.

		// QUERIES.
		double topSpeed()const { return Car::topSpeed() * (1 + Car::topSpeed()); }

		// METHODS.
		void display(std::ostream& out)const;

		// HELPER FUNCTIONS.
		// VOID.

	};

}

#endif // !SDDS_RACECAR_H
