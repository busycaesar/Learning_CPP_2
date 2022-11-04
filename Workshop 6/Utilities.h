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

#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H

#include<iostream>
#include"Vehicle.h"
#include"Car.h"
#include"Van.h"
#include <sstream>

namespace sdds
{

	// ARGUMENT : STRING.
	// RETURNS  : LENGTH OF THE STRING.
	size_t get_length_of(std::string f_word);

	// ARGUMENT : LENGTH OF THE STRING, STRING.
	// RETURNS  : TRIMMED STRING.
	// FUNCTION : TRIMS THE SPACE FROM THE FRONT AND BACK OF THE STRING.
	std::string trim_word(std::string f_word, size_t f_length = 0);

	// ARGUMENT : STRING, DELIM CHARACER
	// RETURNS  : TRIMMED STRING TILL THE FIRST DELIM CHARACTER.
	// FUNCTION : ERASE THE DATA TILL THE FIRST DELIM CHARACTER FROM THE STRING.
	std::string get_data_till(std::string& f_data, const char f_delim = '\n');

	// ARGUMENT : DATA STRING, BAD WORD, GOOD WORD
	// RETURNS  : IF THE REPLACEMENT IS DONE IT WILL SEND BOOL OTHERWISE IT WILL SEND FALSE.
	// FUNCION  : THIS WILL FIND THE BAD WORD IN THE DATA STRING, IF IT IS PRESENT, IT WILL REPLACE IT FROM THE DATA STRING.
	bool replace_word(std::string& f_data, const std::string f_bad, const std::string f_good);

	// ARGUMENT : DATA STRING, TOTAL DATA TO BE GARBAGED, DELIMITING CHARACTER.
	// RETURNS  : IT WILL DIRECTLY SUBTRACT THE DATA FROM THE STRING DUE TO THE REFERANCE PARAMETER.
	// FUNCION  : THIS WILL GARBAGE THE DATA UNTILL THE NUMBERS SPECIFIED AND GIVE THE REMAINING DATA BACK.
	void garbage_data_till(std::string& data, size_t total_waste_data, const char delim);

	// WORKSHOP 6

	Vehicle* createInstance(std::istream& arg_in);

}

#endif // !SDDS_UTILS_H