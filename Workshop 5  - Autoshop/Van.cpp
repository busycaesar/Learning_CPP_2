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
#include"Van.h"

namespace sdds
{

	void Van::mthd_set_empty()
	{

		data_maker = "";
		data_type = "";
		data_condition = "";
		data_purpose = "";
		data_top_speed = 0;

	}

	Van::Van(std::istream& arg_data)
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
			data_type = get_data_till(data, ',');
			data_purpose = get_data_till(data, ',');
			data_condition = get_data_till(data, ',');
			if (data_condition == "") data_condition = "n";
			data = get_data_till(data, ',');
			data_top_speed = stod(data);

		}

	}

	std::string Van::condition()const
	{

		if (data_condition == "n")return "new";
		else if (data_condition == "u")return "used";
		else if (data_condition == "b")return "broken";
		else return "";

	}

	std::string Van::mthd_type() const
	{

		if (data_type == "p")return "pickup";
		else if (data_type == "m")return "mini-bus";
		else if (data_type == "c")return "camper";
		else return "";

	}

	std::string Van::mthd_usage()const
	{

		if (data_purpose == "d")return "delivery";
		else if (data_purpose == "p")return "passenger";
		else if (data_purpose == "c")return "camping";
		else return "";

	}

	void Van::display(std::ostream& arg_out)const
	{

		arg_out << "| "
			<< std::setw(8) << data_maker << " | "
			<< std::left << std::setw(12) << mthd_type() << " | "
			<< std::left << std::setw(12) << mthd_usage() << " | "
			<< std::left << std::setw(6) << condition() << " | "
			<< std::setw(6) << std::right << std::fixed << data_top_speed << " |";

	}

}