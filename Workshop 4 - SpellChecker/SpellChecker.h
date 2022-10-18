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

#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H

// HEADER FILES.
#include<iostream>
#include<fstream>
#include <string>
#include"Utils.h"
#include<iomanip>

namespace sdds
{

	// CLASS.
	class SpellChecker
	{

		// CLASS NAME
		// SpellChecker

		// CLASS PURPOSE.
		// TO CHECK THE SPELLINGS IN THE NAME AND/OR DESCRIPTION OF BOOK OR MOVIE.

		// DATA MEMBER.
		std::string m_badWords[6], m_goodWords[6];
		int m_repeat[6];

		// METHOD.
		void setEmpty();

	public:

		// CONSTRUCTOR AND DESTRUCTOR.
		SpellChecker();
		SpellChecker(const char* f_filename);

		// OPERATOR.
		void operator()(std::string& text);

		// METHODS.
		void showStatistics(std::ostream& out) const;

		// HELPER FUNCTIONS.
		// VOID.

	};

}

#endif // !SDDS_SPELLCHECKER_H