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

	// FUNCTION : THIS WILL RETURN TRUE IF THE STRING IS EMPTY AND VISE-VERSA. 
	bool is_string_empty(std::string string);

	// WORKSHOP 6

	Vehicle* createInstance(std::istream& arg_in);

	bool is_data_perfect(std::string data);

	bool is_a_recognized_character(std::string data, const std::string* list_of_characters, const size_t total_characters);

}

#endif // !SDDS_UTILS_H