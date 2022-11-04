#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H

// REQUIRED HEADER FILES.
#include<vector>
#include"Vehicle.h"

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

		// HELPER FUNCTIONS.
		// VOID.

	};

}

#endif // !SDDS_AUTOSHOP_H
