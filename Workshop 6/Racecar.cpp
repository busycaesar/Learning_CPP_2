#include"Racecar.h"

namespace sdds
{

	Racecar::Racecar(std::istream& in) :Car(in)
	{

		// VARIABLE DECLARATION.
		std::string data = "";

		mthd_set_empty();

		if (in)
		{

			std::getline(in, data);

			garbage_data_till(data, 4, ',');

			data = trim_word(data);
			data_booster = stod(data);

		}

	}

	void Racecar::display(std::ostream& out)const
	{

		Car::display(out);

		out << "*";

	}

}