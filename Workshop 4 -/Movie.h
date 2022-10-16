#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H

#include<iostream>
#include"utils.h"
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
		// VOID.

		// METHODS.
		const std::string& title() const;
		std::ostream& display(std::ostream& out)const;
		template<typename T>
		void fixSpelling(T& spellChecker)
		{

			spellChecker(m_description);

		}

		// HELPER FUNCTIONS.
		// '<<' : INSERTION OPERATOR.

	};

	// HELPER FUNCTION.
	std::ostream& operator<<(std::ostream& out, const Movie& source);

}

#endif // !SDDS_MOVIE_H
