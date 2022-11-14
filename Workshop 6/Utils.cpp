//******************************************************************//
//                                                                  //
// NAME       : DEV JIGISHKUMAR SHAH                                // 
// STUDENT ID : 131623217                                           //
// MAIL ID    : djshah11@myseneca.ca                                //
// COURSE     : OOP 345 NFF                                         //
// SUBMISSION : WORKSHOP 7 (PART 2)                                 //
//                                                                  //
//******************************************************************// 
//                                                                  //
// AUTHENTICITY DECLARATION :                                       //
// I HAVE DONE ALL THE CODING BY MYSELF AND ONLY COPIED THE CODE    //
// THAT MY PROFESSOR PROVIDED TO COMPLETE MY WORKSHOPS AND          //
// ASSIGNMENTS.                                                     //
//                                                                  //
//******************************************************************//

#include"utils.h"

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

		trim_word(f_data);

		return t_temp;

	}

}