#ifndef SDDS_LUXURYVAN_H
#define SDDS_LUXURYVAN_H

#include"Van.h"

namespace sdds
{

	// CLASS
	class Luxuryvan : public Van
	{

	// CLASS NAME AND PURPOSE.
	// NAME: LUXURYVAN
	// PURPOSE: THIS IS A VAN WHICH HAS MORE FUEL CONSUMPTION BECAUSE IT IS LUXURY.

	// DATA MEMBERS.
	
	// INSTANCE VARIABLES.
		std::string data_consumption;

	// CLASS VARAIBLES.

		// METHODS.
		void mthd_set_empty() { data_consumption = ""; }

	public:

	// METHODS.
	
	// CONSTRUCTORS AND DESTRUCTOR.
		Luxuryvan() { mthd_set_empty(); }
		Luxuryvan(std::istream& in);
	
	// OPERATORS.
	
	// CLASS FUNCTIONS.
	
	// QUERIES.
		std::string consumption()const;
	
	// METHODS.
		void display(std::ostream& out)const;
	
	// HELPER FUNCTIONS.
	
	};

}

#endif // !SDDS_LUXURYVAN_H
