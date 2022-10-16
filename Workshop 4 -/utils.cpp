#define _CRT_SECURE_NO_WARNINGS

#include"utils.h"

namespace sdds
{

	size_t getLength(std::string f_word)
	{

		// VARIALBE DECLARATION.
		size_t t_count = 0;

		for (size_t i = 0; f_word[i] != '\0'; i++)t_count++;

		return t_count;

	}

	std::string trimWord(size_t f_length, std::string f_word)
	{

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

	std::string getData(std::string& f_data, const char f_delim)
	{

		// VARIABLE DECLARATION.
		size_t t_position = 0;
		std::string t_temp = "";

		// THIS WILL FIND THE INDEX OF DELIM FROM THE STRING.
		t_position = f_data.find(f_delim);

		// THIS WILL STORE THE COMMA SEPERATED DATA IN THE VARIABLE.
		t_temp = f_data.substr(0, t_position);

		// THIS WILL TRIM THE DATA.
		t_temp = trimWord(t_position - 1, t_temp);

		// THIS WILL ERASE THE COMMA SEPERATED DATA FROM THE MAIN DATA.
		f_data.erase(0, t_position + 1);

		return t_temp;

	}

	bool replaceWord(std::string& f_data, const std::string f_bad, const std::string f_good)
	{

		std::string t_data = f_data;
		size_t t_length = getLength(t_data), t_start = t_data.find(f_bad);
		bool replaced = false;

		// IF THE STRING HAD THE BAD WORD, ITS POSITION WILL BE BETWEEN 0 AND THE LENGTH OF THE STRING.
		if ((t_start > 0) && (t_start < t_length))
		{

			// THIS WILL ERASE THE STRING TILL THE BAD WORD SO THAT WE CAN FIND THE END POSITION OF THE BAD WORD.
			t_data.erase(0, t_start);
			// THIS WILL REPLACE THE BAD WORD WITH GOOD WORD BY PASSING THE POSITION OF STARTING AND ENDING.
			f_data.replace(t_start, t_data.find(' '), f_good);
			replaced = true;

		}

		return replaced;

	}

}