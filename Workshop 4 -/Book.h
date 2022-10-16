#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include<iostream>
#include<iomanip>
#include<string>
#include"utils.h"
#include"SpellChecker.h"

namespace sdds
{

	// CLASS.
	class Book
	{

		// DATA MEMBERS.
		std::string m_author, m_title, m_country, m_description;
		size_t m_year;
		double m_price;

		// METHODS.
		void setEmpty();

	public:

		// CONSTRUCTORS AND DESTRUCTORS.
		Book();
		Book(const std::string& f_data);

		// OPERATORS.
		Book& operator=(const Book& source);

		// METHODS.
		const std::string& title() const;
		const std::string& country()const;
		const size_t& year() const;
		double& price();
		std::ostream& display(std::ostream& out)const;
		template<typename T>
		void fixSpelling(T& spellChecker)
		{

			spellChecker(m_description);

		}

		// HELPER FUNCTIONS.
		// '<<' : INSERTION OPERATOR FOR OSTREAM.

	};

	// HELPER FUNCTION.
	std::ostream& operator<<(std::ostream& out, const Book& source);

}

#endif // !SDDS_BOOK_H
