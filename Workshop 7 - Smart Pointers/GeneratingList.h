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

namespace sdds
{

	// CLASSES.
	template<typename T>
	class GeneratingList
	{

		// VARIABLE DECLARATON
		std::vector<T> list;

	public:

		GeneratingList() {}

		GeneratingList(const char* f)
		{

			// VARIABLE DECLARATON
			std::ifstream file(f);

			if (!file) throw std::string("*** Failed to open file ") + std::string(f) + std::string(" ***");

			while (file)
			{

				// VARIABLE DECLARATON
				T t;

				if (t.load(file)) list.push_back(T(t));

			}

		}

		size_t size() const { return list.size(); }

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

		}

	};

	// HELPER FUNCTIONS.
	template<typename T>
	std::ostream& operator<<(std::ostream& os, const GeneratingList<T>& rd)
	{

		rd.print(os);

		return os;

	}

}

#endif // !SDDS_GENERATINGLIST_H