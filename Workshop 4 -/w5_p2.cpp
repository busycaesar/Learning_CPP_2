// Workshop 5 - Functions and Error Handling
// 2020/02 - Cornel
// 2021/01/19 - Chris
// 2021/02/12 - Cornel

#define _CRT_SECURE_NO_WARNINGS

// HEADER FILES.
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Collection.h"
#include "Collection.h"
#include "Book.h"
#include "Book.h"
#include "Movie.h"
#include "Movie.h"
#include "SpellChecker.h"
#include "SpellChecker.h"

using namespace sdds;

enum AppErrors
{

	CannotOpenFile = 1, // An input file cannot be opened
	BadArgumentCount = 2, // The application didn't receive anough parameters

};

// The observer function for adding books to the collection:
//   should be called every time a new book is added to the collection
void bookAddedObserver(const Collection<Book>& theCollection,
	const Book& theBook)
{

	std::cout << "Book \"" << theBook.title() << "\" added!\n";

}

// The observer function for adding movies to the collection:
//   should be called every time a new movie is added to the collection
void movieAddedObserver(const Collection<Movie>& theCollection,
	const Movie& theMovie)
{

	std::cout << "Movie \"" << theMovie.title()
		<< "\" added to collection \"" << theCollection.name()
		<< "\" (" << theCollection.size() << " items).\n";

}

// ws books.txt movies.txt file_missing.txt file_words.txt
int main(int argc, char** argv)
{

	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";

	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';

	std::cout << "--------------------------\n\n";

	// get the books
	// VARIABLE DECLARATION.
	sdds::Collection<sdds::Book> library("Bestsellers");

	if (argc == 5)
	{

		// VARIABLE DECLARATION.
		std::ifstream mn_file(argv[1]);
		std::string mn_temp = "";
		int i = 4;

		if (mn_file)
		{

			while ((std::getline(mn_file, mn_temp)) && i)
			{

				if (mn_temp[i] != '#')
				{

					library += Book(mn_temp);
					i--;

				}

			}

		}
		else
		{

			std::cerr << "Cannot open the file." << std::endl;
			exit(AppErrors::CannotOpenFile);

		}

		/*
		 ♪ Hey, I just met you,      ♪
		 ♪ And this is crazy,        ♪
		 ♪ But here's my number.     ♪    (register the observer)
		 ♪ So, if something happens, ♪    (event)
		 ♪ Call me, maybe?           ♪    (callback)
		 */

		library.setObserver(bookAddedObserver);

		if (mn_file)
		{

			while (std::getline(mn_file, mn_temp))
			{

				if (mn_temp[0] != '#')library += Book(mn_temp);

			}

			mn_file.close();

		}

	}
	else
	{

		std::cerr << "ERROR: Incorrect number of arguments.\n";
		exit(AppErrors::BadArgumentCount);

	}

	// VARIABLE DECLARATION.
	double usdToCadRate = 1.3;
	double gbpToCadRate = 1.5;

	auto updatePrice = [&](Book& exp_book)
	{

		if (exp_book.country() == "US")
		{

			exp_book.price() *= usdToCadRate;

		}
		else if ((exp_book.country() == "UK") && (exp_book.year() >= 1990) && (exp_book.year() <= 1999))
		{

			exp_book.price() *= gbpToCadRate;

		}

	};

	std::cout << "-----------------------------------------\n";
	std::cout << "The library content\n";
	std::cout << "-----------------------------------------\n";
	std::cout << library;
	std::cout << "-----------------------------------------\n\n";

	for (size_t i = 0; i < library.size(); i++) updatePrice(library[i]);

	std::cout << "-----------------------------------------\n";
	std::cout << "The library content (updated prices)\n";
	std::cout << "-----------------------------------------\n";
	std::cout << library;
	std::cout << "-----------------------------------------\n\n";

	// VARIABLE DECLARATION.
	Collection<Movie> theCollection("Action Movies");

	// Process the file
	Movie movies[5];
	if (argc > 2)
	{

		// VARIABLE DECLARATION.
		std::ifstream mn_file(argv[2]);
		std::string mn_temp = "";
		int i = 0;
		bool remaining = true;

		if (mn_file)
		{

			while ((std::getline(mn_file, mn_temp)) && remaining)
			{

				if (mn_temp[i] != '#')
				{

					movies[i] = Movie(mn_temp);
					i++;
					if (i == 5)remaining = false;

				}

			}

		}
		else
		{

			std::cerr << "Cannot open the file." << std::endl;
			exit(AppErrors::CannotOpenFile);

		}

	}

	std::cout << "-----------------------------------------\n";
	std::cout << "Testing addition and callback function\n";
	std::cout << "-----------------------------------------\n";

	if (argc > 2)
	{

		// Add a few movies to collection; no observer is set
		((theCollection += movies[0]) += movies[1]) += movies[2];
		theCollection += movies[1];
		// add more movies; now we get a callback from the collection
		theCollection.setObserver(movieAddedObserver);
		theCollection += movies[3];
		theCollection += movies[3];
		theCollection += movies[4];

	}
	else
	{

		std::cout << "** No movies in the Collection\n";

	}

	std::cout << "-----------------------------------------\n\n";

	std::cout << "-----------------------------------------\n";
	std::cout << "Testing exceptions and operator[]\n";
	std::cout << "-----------------------------------------\n";

	try
	{

		for (auto i = 0u; i < 10; ++i) std::cout << theCollection[i];

	}
	catch (const std::exception& f_err)
	{

		std::cout << "** EXCEPTION: " << f_err.what() << std::endl;

	}

	std::cout << "-----------------------------------------\n\n";

	std::cout << "-----------------------------------------\n";
	std::cout << "Testing the functor\n";
	std::cout << "-----------------------------------------\n";

	for (auto i = 3; i < argc; ++i)
	{

		// TODO: The following statement can generate generate an exception
		//         write code to handle the exception
		//       If an exception occurs print a message in the following format
		//** EXCEPTION: ERROR_MESSAGE<endl>
		//         where ERROR_MESSAGE is extracted from the exception object.

		try
		{

			SpellChecker sp(argv[i]);
			for (auto j = 0u; j < library.size(); ++j)
				library[j].fixSpelling(sp);
			sp.showStatistics(std::cout);

			for (auto j = 0u; j < theCollection.size(); ++j)
				theCollection[j].fixSpelling(sp);
			sp.showStatistics(std::cout);

		}
		catch (const char* f_message)
		{

			std::cout << "** Exception: " << f_message << std::endl;

		}


	}
	if (argc < 3)
	{

		std::cout << "** Spellchecker is empty\n";
		std::cout << "-----------------------------------------\n";

	}

	std::cout << "\n";

	std::cout << "=========================================\n";
	std::cout << "Wrapping up this workshop\n";

	std::cout << "--------------- Movies ------------------\n";
	std::cout << theCollection;

	std::cout << "--------------- Books -------------------\n";
	std::cout << library;

	std::cout << "-----------------------------------------\n";
	std::cout << "Testing operator[] (the other overload)\n";
	std::cout << "-----------------------------------------\n";

	// VARIABLE DECLARATION.
	const Movie* aMovie = theCollection["Terminator 2"];

	if (aMovie == nullptr)
		std::cout << "** Movie Terminator 2 not in collection.\n";

	aMovie = theCollection["Dark Phoenix"];

	if (aMovie != nullptr)
		std::cout << "In this collection:\n" << *aMovie;

	std::cout << "-----------------------------------------\n\n";

	return 0;

}