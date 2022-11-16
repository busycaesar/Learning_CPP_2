//******************************************************************//
//                                                                  //
// NAME       : DEV JIGISHKUMAR SHAH                                // 
// STUDENT ID : 131623217                                           //
// MAIL ID    : djshah11@myseneca.ca                                //
// COURSE     : OOP 345 NFF                                         //
// SUBMISSION : WORKSHOP 7 (PART 2)                                 //
//                                                                  //
//******************************************************************// 
//                                                                  //
// AUTHENTICITY DECLARATION :                                       //
// I HAVE DONE ALL THE CODING BY MYSELF AND ONLY COPIED THE CODE    //
// THAT MY PROFESSOR PROVIDED TO COMPLETE MY WORKSHOPS AND          //
// ASSIGNMENTS.                                                     //
//                                                                  //
//******************************************************************//

#ifndef SDDS_CRIMESTATISTICS_H
#define SDDS_CRIMESTATISTICS_H

// REQUIRED HEADER FILES.
#include<string>
#include<iomanip>
#include<fstream>
#include<vector>
#include"utils.h"
#include<algorithm>
#include<numeric>
#include <list>

namespace sdds
{

	// STRUCTURE.
	struct Crime
	{

		std::string d_provice = "";
		std::string d_district = "";
		std::string d_crime = "";
		size_t d_number_of_cases = 0;
		size_t d_year = 0;
		size_t m_resolved = 0;

	};

	// CLASS.
	class CrimeStatistics
	{

		// CLASS NAME AND PURPOSE.
		// NAME: CRIME STATISTICS
		// PURPOSE: TO MANAGE THE COLLECTION OF CRIMES.

		// DATA MEMBERS.

		// INSTANCE VARIABLES.
		std::vector<Crime> d_crime;

		// CLASS VARAIBLES.

	public:

		// METHODS.

		// CONSTRUCTORS AND DESTRUCTOR.

		CrimeStatistics(std::string file_name);

		// OPERATORS.

		// CLASS FUNCTIONS.

		// QUERIES.

		// METHODS.
		void display(std::ostream& out) const;
		void sort(std::string term);
		void cleanList();
		bool inCollection(std::string crime) const;
		std::list<Crime> getListForProvince(std::string province) const;

		// HELPER FUNCTIONS.
		// std::ostream& operator<<(std::ostream& out, const Crime& theCrime);

	};

	// HELPER FUNCTION.
	std::ostream& operator<<(std::ostream& out, const Crime& theCrime);

}

#endif // !SDDS_CRIMESTATISTICS_H