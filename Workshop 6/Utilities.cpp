//******************************************************************//
//                                                                  //
// NAME       : DEV JIGISHKUMAR SHAH                                // 
// STUDENT ID : 131623217                                           //
// MAIL ID    : djshah11@myseneca.ca                                //
// COURSE     : OOP 345 NFF                                         //
// SUBMISSION : WORKSHOP 5 (PART 2)                                 //
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

namespace sdds
{

	size_t get_length_of(std::string f_word)
	{

		// VARIALBE DECLARATION.
		size_t t_count = 0;

		for (size_t i = 0; f_word[i] != '\0'; i++)t_count++;

		return t_count;

	}

	std::string trim_word(std::string f_word, size_t f_length = 0)
	{

		if (!f_length) f_length = get_length_of(f_word);

		// THIS WILL TRIM ALL THE SPACES AFTER THE WORD.
		while (f_word[f_length] == ' ')
		{

			f_word = f_word.substr(0, f_length);
			f_length--;

		}

		// THIS WILL TRIM ALL THE SPACES BEFORE THE WORD.
		while (f_word[0] == ' ')f_word.erase(0, 1);

		return f_word;

	}

	std::string get_data_till(std::string& f_data, const char f_delim = '\n')
	{

		// VARIABLE DECLARATION.
		size_t t_position = 0;
		std::string t_temp = "";

		// THIS WILL FIND THE INDEX OF DELIM FROM THE STRING.
		t_position = f_data.find(f_delim);

		// THIS WILL STORE THE COMMA SEPERATED DATA IN THE VARIABLE.
		t_temp = f_data.substr(0, t_position);

		// THIS WILL TRIM THE DATA.
		t_temp = trim_word(t_temp, t_position - 1);

		// THIS WILL ERASE THE COMMA SEPERATED DATA FROM THE MAIN DATA.
		f_data.erase(0, t_position + 1);

		return t_temp;

	}

	bool replace_word(std::string& f_data, const std::string f_bad, const std::string f_good)
	{

		std::string t_data = f_data, t_badWord = "";
		size_t t_length = get_length_of(t_data), t_start = t_data.find(f_bad);
		bool replaced = false;

		// IF THE STRING HAD THE BAD WORD, ITS POSITION WILL BE BETWEEN 0 AND THE LENGTH OF THE STRING.
		if ((t_start >= 0) && (t_start < t_length))
		{

			// THIS WILL ERASE THE STRING TILL THE BAD WORD SO THAT WE CAN FIND THE END POSITION OF THE BAD WORD.
			t_data.erase(0, t_start);

			t_badWord = t_data.substr(0, t_data.find(' '));

			// THIS WILL REPLACE THE BAD WORD WITH GOOD WORD BY PASSING THE POSITION OF STARTING AND ENDING.
			if (get_length_of(t_badWord) == get_length_of(f_bad))f_data.replace(t_start, get_length_of(t_badWord), f_good);
			else f_data.replace(t_start, get_length_of(f_good), f_good);

			replaced = true;

		}

		return replaced;

	}

	Vehicle* createInstance(std::istream& arg_in)
	{

		// VARIABLE DECLARATION.
		std::string temp = "";
		Vehicle* temp_vehicle = nullptr;

		if (arg_in)
		{

			std::getline(arg_in, temp);

			// VARIABLE DECLARATION.
			std::stringstream temp_stream(temp);

			if (temp[0] == 'c' || temp[0] == 'C')
				temp_vehicle = new Car(temp_stream);
			else if (temp[0] == 'v' || temp[0] == 'V')temp_vehicle = new Van(temp_stream);

		}

		return temp_vehicle;

	}

	void garbage_data_till(std::string& data, size_t total_waste_data, const char delim)
	{

		for (size_t i = 0; i < total_waste_data; i++) get_data_till(data, delim);

	}

}