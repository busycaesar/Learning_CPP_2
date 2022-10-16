#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H

#include<iostream>

namespace sdds
{

	// ARGUMENT : STRING.
	// RETURNS  : LENGTH OF THE STRING.
	size_t getLength(std::string f_word);

	// ARGUMENT : LENGTH OF THE STRING, STRING.
	// RETURNS  : TRIMMED STRING.
	// FUNCTION : TRIMS THE SPACE FROM THE FRONT AND BACK OF THE STRING.
	std::string trimWord(size_t f_length, std::string f_word);
	
	// ARGUMENT : STRING, DELIM CHARACER
	// RETURNS  : TRIMMED STRING TILL THE FIRST DELIM CHARACTER.
	// FUNCTION : ERASE THE DATA TILL THE FIRST DELIM CHARACTER FROM THE STRING.
	std::string getData(std::string& f_data, const char f_delim);

	// ARGUMENT : DATA STRING, BAD WORD, GOOD WORD
	// RETURNS  : IF THE REPLACEMENT IS DONE IT WILL SEND BOOL OTHERWISE IT WILL SEND FALSE.
	// FUNCION  : THIS WILL FIND THE BAD WORD IN THE DATA STRING, IF IT IS PRESENT, IT WILL REPLACE IT FROM THE DATA STRING.
	bool replaceWord(std::string& f_data, const std::string f_bad, const std::string f_good);

}

#endif // !SDDS_UTILS_H
