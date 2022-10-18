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

#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H

#include<iostream>
#include"Utils.h"
#include<string>
#include<iomanip>

namespace sdds
{

	class Movie
	{

		// CLASS NAME.
		// Movie

		// CLASS PURPOSE.
		// TO STORE THE INFORMATION OF A MOVIE.

		// DATA MEMBER.
		std::string m_title, m_description;
		size_t m_year;

		// METHOD.
		void setEmpty();

	public:

		// CONSTRUCTOR AND DESTRUCTOR.
		Movie();
		Movie(const std::string& f_strMovie);

		// OPERATOR.
		Movie& operator=(const Movie& source);

		// METHODS.
		const std::string& title() const;
		std::ostream& display(std::ostream& out)const;
		
		template<typename T>
		void fixSpelling(T& spellChecker)
		{

			spellChecker(m_title);
			spellChecker(m_description);

		}

		// HELPER FUNCTIONS.
		// '<<' : INSERTION OPERATOR.

	};

	// HELPER FUNCTION.
	std::ostream& operator<<(std::ostream& out, const Movie& source);

}

#endif // !SDDS_MOVIE_H