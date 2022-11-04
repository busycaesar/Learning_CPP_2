#ifndef SDDS_CAR_H
#define SDDS_CAR_H

// REQUIRED HEADER FILES.
#include"Vehicle.h"
#include<string>
#include<iomanip>
#include"Utilities.h"

namespace sdds
{

	// CLASS.
	class Car : public Vehicle
	{

		// CLASS NAME AND PURPOSE.
		// NAME: CAR
		// PURPOSE: THIS CLASS HOLDS THE INFORMATION OF A SINGLE CAR.

		// DATA MEMBER.
		std::string data_maker, data_condition;
		double data_top_speed;

		// METHODS.
		void mthd_set_empty();

	public:

		// CONSTRUCTOR AND DESTRUCTOR.
		Car() { mthd_set_empty(); }
		Car(std::istream& arg_data);

		// OPERATOR.
		// VOID.

		// QUERIES.
		std::string condition() const;
		double topSpeed()const { return data_top_speed; }

		// METHODS.
		void display(std::ostream& arg_out) const;

		// HELPER FUNCTIONS.
		// VOID.

	};

}

#endif // !SDDS_CAR_H
