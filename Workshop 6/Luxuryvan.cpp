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

			data_consumption = trim_word(data);
			
		}

	}

	std::string sdds::Luxuryvan::consumption() const
	{



	}

	void sdds::Luxuryvan::display(std::ostream& out) const
	{



	}

}