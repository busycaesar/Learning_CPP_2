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

#include"Utilities.h"
#include"Car.h"
#include"Van.h"
#include"Racecar.h"
#include"Luxuryvan.h"

namespace sdds
{

	void trim_word(std::string& f_word)
	{

		// VARAIBLE DECLARATION.
		size_t length = f_word.size() - 1;

		if (is_string_empty(f_word)) f_word = "";
		else
		{

			// THIS WILL TRIM ALL THE SPACES AFTER THE WORD.
			while ((f_word[length] == ' ') && length < f_word.size())
			{

				f_word = f_word.substr(0, length);
				length--;

			}

			// THIS WILL TRIM ALL THE SPACES BEFORE THE WORD.
			while (f_word[0] == ' ')f_word.erase(0, 1);

		}

	}

	std::string get_data_till(std::string& f_data, const char f_delim)
	{

		// VARIABLE DECLARATION.
		size_t t_position = 0;
		std::string t_temp = "";

		// THIS WILL FIND THE INDEX OF DELIM FROM THE STRING.
		t_position = f_data.find(f_delim);

		if (t_position)
		{

			// THIS WILL STORE THE COMMA SEPERATED DATA IN THE VARIABLE.
			t_temp = f_data.substr(0, t_position);

			// THIS WILL TRIM THE DATA.
			trim_word(t_temp);

			// THIS WILL ERASE THE COMMA SEPERATED DATA FROM THE MAIN DATA.
			f_data.erase(0, t_position + 1);

		}
		else
		{

			f_data.erase(0, 1);

		}

		return t_temp;

	}

	void garbage_data_till(std::string& data, size_t total_waste_data, const char delim)
	{

		for (size_t i = 0; i < total_waste_data; i++) get_data_till(data, delim);

	}

	Vehicle* createInstance(std::istream& arg_in)
	{

		// VARIABLE DECLARATION.
		std::string temp = "";
		Vehicle* temp_vehicle = nullptr;

		if (arg_in)
		{

			if (!std::getline(arg_in, temp)) return temp_vehicle;
			trim_word(temp);

			try
			{

				is_data_perfect(temp);

				// VARIABLE DECLARATION.
				std::stringstream temp_stream(temp);

				if (temp[0] == 'c' || temp[0] == 'C')
					temp_vehicle = new Car(temp_stream);
				else if (temp[0] == 'v' || temp[0] == 'V')temp_vehicle = new Van(temp_stream);
				else if (temp[0] == 'r' || temp[0] == 'R') temp_vehicle = new Racecar(temp_stream);
				else if (temp[0] == 'l' || temp[0] == 'L') temp_vehicle = new Luxuryvan(temp_stream);

			}
			catch (const std::invalid_argument& error)
			{

				std::cerr << error.what() << std::endl;

			}

		}

		return temp_vehicle;

	}

	bool is_this_number(std::string string)
	{

		for (size_t i = 0; i < string.length(); i++)
		{

			if (!isdigit(string[i])) return false;

		}

		return true;

	}

	bool is_string_empty(std::string string)
	{

		// VARIABLE DECLARATION.
		size_t empty_places = 0;

		for (size_t i = 0; i < string.size(); i++)
		{

			if (string[i] == ' ') empty_places++;

		}

		return empty_places == string.size();

	}

	bool is_data_perfect(std::string data)
	{

		// VARIABLE DECLARATION.
		std::string type = "", condition = "", speed = "", category = "", purpose = "", fuel = "";
		const std::string type_of_vehicle[] = { "c","v","l","r","C","V","L","R" }, type_of_conditions[] = { "n","u","b","" },
			vans[] = { "v","V","l","L" }, cars[] = { "c","C","r","R" }, type_of_category[] = { "p","m","c" }, type_of_purpose[] = { "d","p","c" };

		data += ",garbage";

		type = get_data_till(data, ',');
		garbage_data_till(data, 1, ',');

		if (is_a_recognized_character(type, vans, 4))
		{

			category = get_data_till(data, ',');
			purpose = get_data_till(data, ',');

			if ((!is_a_recognized_character(category, type_of_category, 3)) || (!is_a_recognized_character(purpose, type_of_purpose, 3))) throw std::invalid_argument("Invalid record!");

		}

		condition = get_data_till(data, ',');

		speed = get_data_till(data, ',');

		if ((!is_a_recognized_character(type, type_of_vehicle, 8)))
		{
		
			// VARIABLE DECLARATION.
			std::string throw_message = "Unrecognized record type: [" + type + "]";

			throw std::invalid_argument(throw_message);
		
		}

		if ((!is_a_recognized_character(condition, type_of_conditions, 4)) || (!is_this_number(speed))) throw std::invalid_argument("Invalid record!");

		if (type == "l" || type == "L")
		{

			fuel = get_data_till(data, ',');

			if (fuel == "g")throw std::invalid_argument("Invalid record!");

		}

		return true;

	}

	bool is_a_recognized_character(std::string data, const std::string* list_of_characters, const size_t total_characters)
	{

		for (size_t i = 0; i < total_characters; i++)
		{

			if (data == list_of_characters[i]) return true;

		}

		return false;

	}

}