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