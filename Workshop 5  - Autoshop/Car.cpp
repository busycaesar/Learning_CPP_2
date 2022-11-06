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

#define _CRT_SECURE_NO_WARNINGS

// REQUIRED HEADER FILES.
#include"Car.h"

namespace sdds
{

	void Car::mthd_set_empty()
	{

		data_maker = "";
		data_condition = "";
		data_top_speed = 0;

	}

	Car::Car(std::istream& arg_data)
	{

		// VARIABLE DECLARATION.
		std::string data = "";

		mthd_set_empty();

		if (arg_data)
		{

			std::getline(arg_data, data);

			data += ",garbage";
			garbage_data_till(data, 1, ',');
			data_maker = get_data_till(data, ',');
			data_condition = get_data_till(data, ',');
			if (data_condition == "") data_condition = "n";
			data = get_data_till(data, ',');
			data_top_speed = std::stod(data);

		}

	}

	std::string Car::condition() const
	{

		if (data_condition == "n")return "new";
		else if (data_condition == "u")return "used";
		else if (data_condition == "b")return "broken";
		else return "";

	}

	void Car::display(std::ostream& arg_out) const
	{

		arg_out << "| " << std::right << std::setw(10) << data_maker << " | "
			<< std::setw(6) << std::left << condition() << " | "
			<< std::setw(6) << std::right << std::fixed << std::setprecision(2) << topSpeed() << " |";

	}

}