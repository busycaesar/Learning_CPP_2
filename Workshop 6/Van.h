#ifndef SDDS_VAN_H
#define SDDS_VAN_H

// REQUIRED HEADER FILES.
#include"Vehicle.h"
#include"Utilities.h"
#include<iomanip>

namespace sdds
{

	// CLASS.
	class Van :public Vehicle
	{

		// CLASS NAME AND PURPOSE.
		// NAME: VAN
		// PURPOSE: TO STORE THE INFORMATION OF A SINGLE VAN.

		// DATA MEMBERS.
		std::string data_maker, data_type, data_condition, data_purpose;
		double data_top_speed;

		// METHODS.
		void mthd_set_empty();

	public:

		// METHODS.

		// CONSTRUCTORS AND DESTRUCTOR.
		Van() { mthd_set_empty(); }
		Van(std::istream& arg_data);

		// OPERATORS.
		// VOID.

		// QUERIES.
		std::string condition()const;
		double topSpeed()const { return data_top_speed; }
		std::string mthd_type() const;
		std::string mthd_usage()const;

		// METHODS.
		void display(std::ostream& arg_out)const;

		// HELPER FUNCTIONS.
		// VOID.

	};

}

#endif // !SDDS_VAN_H
