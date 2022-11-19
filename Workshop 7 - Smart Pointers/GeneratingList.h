<<<<<<< HEAD
=======
//******************************************************************//
//                                                                  //
// NAME       : DEV JIGISHKUMAR SHAH                                // 
// STUDENT ID : 131623217                                           //
// MAIL ID    : djshah11@myseneca.ca                                //
// COURSE     : OOP 345 NFF                                         //
// SUBMISSION : WORKSHOP 8 (PART 1)                                 //
//                                                                  //
//******************************************************************// 
//                                                                  //
// AUTHENTICITY DECLARATION :                                       //
// I HAVE DONE ALL THE CODING BY MYSELF AND ONLY COPIED THE CODE    //
// THAT MY PROFESSOR PROVIDED TO COMPLETE MY WORKSHOPS AND          //
// ASSIGNMENTS.                                                     //
//                                                                  //
//******************************************************************//

>>>>>>> 9934ea45eecb7ef970bd4df204f0d9a6eb8eb785
#ifndef SDDS_GENERATINGLIST_H
#define SDDS_GENERATINGLIST_H

// REQUIRED HEADER FILES.
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <fstream>

<<<<<<< HEAD
namespace sdds 
=======
namespace sdds
>>>>>>> 9934ea45eecb7ef970bd4df204f0d9a6eb8eb785
{

	// CLASSES.
	template<typename T>
<<<<<<< HEAD
	class GeneratingList 
=======
	class GeneratingList
>>>>>>> 9934ea45eecb7ef970bd4df204f0d9a6eb8eb785
	{

		// VARIABLE DECLARATON
		std::vector<T> list;
<<<<<<< HEAD
	
=======

>>>>>>> 9934ea45eecb7ef970bd4df204f0d9a6eb8eb785
	public:

		GeneratingList() {}

<<<<<<< HEAD
		GeneratingList(const char* f) 
=======
		GeneratingList(const char* f)
>>>>>>> 9934ea45eecb7ef970bd4df204f0d9a6eb8eb785
		{

			// VARIABLE DECLARATON
			std::ifstream file(f);

<<<<<<< HEAD
			if (!file)
				throw std::string("*** Failed to open file ") + std::string(f) + std::string(" ***");

			while (file) 
=======
			if (!file) throw std::string("*** Failed to open file ") + std::string(f) + std::string(" ***");

			while (file)
>>>>>>> 9934ea45eecb7ef970bd4df204f0d9a6eb8eb785
			{

				// VARIABLE DECLARATON
				T t;

<<<<<<< HEAD
				if (t.load(file))
					list.push_back(T(t));
			
=======
				if (t.load(file)) list.push_back(T(t));

>>>>>>> 9934ea45eecb7ef970bd4df204f0d9a6eb8eb785
			}

		}

		size_t size() const { return list.size(); }
<<<<<<< HEAD
		const T& operator[](size_t i) const { return list[i]; }

		//TODO: Implement the Luhn Algorithm to check the 
		//      valadity of SIN No's

		//TODO: Overload the += operator with a raw pointer
		// as a second operand.

		void print(std::ostream& os) const 
		{

			os << std::fixed << std::setprecision(2);
			
			for (auto& e : list)
				e.print(os);
		
=======

		const T& operator[](size_t i) const { return list[i]; }

		bool checkLuhn(std::string sin_number)
		{

			// VARIABLE DECLARATION.
			size_t temp = 0, total = 0;

			for (size_t i = 0; i < sin_number.length(); i++)
			{

				temp = sin_number[i] - '0';

				if (i % 2)
				{

					temp *= 2;
					
					if (temp > 9) temp -= 9;

				}

				total += temp;

			}

			return total % 10 == 0;

		}

		void operator+=(const T* new_object) { list.push_back(*new_object); }

		void operator+=(const T& new_object) { list.push_back(new_object); }

		void print(std::ostream& os) const
		{

			os << std::fixed << std::setprecision(2);

			for (auto& e : list) e.print(os);

>>>>>>> 9934ea45eecb7ef970bd4df204f0d9a6eb8eb785
		}

	};

	// HELPER FUNCTIONS.
	template<typename T>
<<<<<<< HEAD
	std::ostream& operator<<(std::ostream& os, const GeneratingList<T>& rd) 
	{

		rd.print(os);
		return os;
	
=======
	std::ostream& operator<<(std::ostream& os, const GeneratingList<T>& rd)
	{

		rd.print(os);

		return os;

>>>>>>> 9934ea45eecb7ef970bd4df204f0d9a6eb8eb785
	}

}

#endif // !SDDS_GENERATINGLIST_H