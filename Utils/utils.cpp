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
		else {f_data.erase(0, 1);}

		return t_temp;

	}

    void garbage_data_till(std::string& data, size_t total_waste_data, const char delim)
	{

		for (size_t i = 0; i < total_waste_data; i++) get_data_till(data, delim);

	}

    bool is_this_number(std::string string)
	{

		for (size_t i = 0; i < string.length(); i++)
		{

			if (!isdigit(string[i])) return false;

		}

		return true;

	}

	bool auto_correct_data(std::string& f_data, const std::string f_bad, const std::string f_good)
	{

		// VARIABLE DECLARATION.
		std::string t_data = f_data, t_badWord = "";
		size_t t_length = t_data.size(), t_start = t_data.find(f_bad);

		// IF THE STRING HAD THE BAD WORD, ITS POSITION WILL BE BETWEEN 0 AND THE LENGTH OF THE STRING.
		if ((t_start >= 0) && (t_start < t_length))
		{

			// THIS WILL ERASE THE STRING TILL THE BAD WORD SO THAT WE CAN FIND THE END POSITION OF THE BAD WORD.
			t_data.erase(0, t_start);

			t_badWord = t_data.substr(0, t_data.find(' '));

			// THIS WILL REPLACE THE BAD WORD WITH GOOD WORD BY PASSING THE POSITION OF STARTING AND ENDING.
			if (t_badWord.size() == f_bad.size())f_data.replace(t_start, t_badWord.size(), f_good);
			else f_data.replace(t_start, f_good.size(), f_good);

			return true;

		}

		return false;

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

}