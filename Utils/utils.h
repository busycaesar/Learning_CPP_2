#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H

#include<iostream>
#include <sstream>
#include"Vehicle.h"

namespace sdds
{

	// ARGUMENT : STRING.
	// RETURNS  : TRIMMED STRING.
	// FUNCTION : TRIMS THE SPACE FROM THE FRONT AND BACK OF THE STRING.
	void trim_word(std::string& f_word);

	// ARGUMENT : STRING, DELIM CHARACER
	// RETURNS  : TRIMMED STRING TILL THE FIRST DELIM CHARACTER.
	// FUNCTION : ERASE THE DATA TILL THE FIRST DELIM CHARACTER FROM THE STRING.
	std::string get_data_till(std::string& f_data, const char f_delim = '\n');

	// ARGUMENT : DATA STRING, TOTAL DATA TO BE GARBAGED, DELIMITING CHARACTER.
	// RETURNS  : IT WILL DIRECTLY SUBTRACT THE DATA FROM THE STRING DUE TO THE REFERANCE PARAMETER.
	// FUNCION  : THIS WILL GARBAGE THE DATA UNTILL THE NUMBERS SPECIFIED AND GIVE THE REMAINING DATA BACK.
	void garbage_data_till(std::string& data, size_t total_waste_data, const char delim);

	// ARGUMENT : DATA STRING
	// RETURNS  : BOOL
	// FUNCION  : CHECKS IF THE STRING CONTAINS NUMBERS OR NOT.
	bool is_this_number(std::string string);

	// ARGUMENT : DATA STRING, BAD WORD, GOOD WORD
	// RETURNS  : BOOL
	// FUNCION  : THIS FUNCTION WILL REPLACE THE BAD WORD WITH THE GOOD WORD FROM THE DATA STRING AND RETURNS TRUE IF THE WORD IS CORRECTED AND VISE-VERSA.
	bool auto_correct_data(std::string& f_data, const std::string f_bad, const std::string f_good);

	// FUNCTION : THIS WILL RETURN TRUE IF THE STRING IS EMPTY AND VISE-VERSA. 
	bool is_string_empty(std::string string);

}

#endif // !SDDS_UTILS_H