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

#include"CrimeStatistics.h"

namespace sdds
{

	CrimeStatistics::CrimeStatistics(std::string file_name)
	{

		// VARIABLE DECLARATION.
		std::fstream file(file_name);
		std::string data = "";

		if (file)
		{

			while (file)
			{

				// VARIABLE DECLARATION.
				Crime new_data;

				if (std::getline(file, data))
				{

					new_data.d_provice = get_data_till(data, ' ');
					new_data.d_district = get_data_till(data, ' ');
					new_data.d_crime = get_data_till(data, ' ');
					new_data.d_year = std::stoi(get_data_till(data, ' '));
					new_data.d_number_of_cases = std::stoi(get_data_till(data, ' '));
					new_data.m_resolved = std::stoi(data);

					d_crime.push_back(new_data);

				}

			}

		}
		else throw std::invalid_argument("Incorrect filename!");

	}

	void CrimeStatistics::display(std::ostream& out) const
	{

		std::for_each(d_crime.begin(), d_crime.end(), [&out](Crime temp) { out << temp << std::endl; });

		size_t total_crimes = std::accumulate(d_crime.begin(), d_crime.end(), (size_t)0, [](size_t x, Crime y) {return x + y.d_number_of_cases; }), total_resolved_cases = std::accumulate(d_crime.begin(), d_crime.end(), (size_t)0, [](size_t x, Crime y) {return x + y.m_resolved; });

		out << "----------------------------------------------------------------------------------------" << std::endl << "|                                                                 Total Crimes:  " << total_crimes << " |" << std::endl << "|                                                         Total Resolved Cases:  " << total_resolved_cases << " |" << std::endl;

	}

	void CrimeStatistics::sort(std::string term)
	{

		std::sort(d_crime.begin(), d_crime.end(), [=](const Crime& lo, const Crime& ro)
			{

				if (term == "Province") return lo.d_provice < ro.d_provice;
				else if (term == "Crime") return lo.d_crime < ro.d_crime;
				else if (term == "Cases") return lo.d_number_of_cases < ro.d_number_of_cases;
				else if (term == "Resolved") return lo.m_resolved < ro.m_resolved;

			});

	}

	void CrimeStatistics::cleanList()
	{

		std::transform(d_crime.begin(), d_crime.end(), d_crime.begin(), [](Crime& temp)
			{if (temp.d_crime == "[None]") { temp.d_crime = ""; return temp; }return temp; });

	}

	bool CrimeStatistics::inCollection(std::string crime) const
	{

		return std::any_of(d_crime.begin(), d_crime.end(), [=](Crime temp) {return temp.d_crime == crime; });

	}

	std::list<Crime> CrimeStatistics::getListForProvince(std::string province) const
	{

		// VARIABLE DECLARATION.
		std::list<Crime> province_crimes;

		std::copy_if(d_crime.begin(), d_crime.end(), std::back_inserter(province_crimes), [=](const Crime& temp) {return temp.d_provice == province; });

		return province_crimes;

	}

	std::ostream& operator<<(std::ostream& out, const Crime& theCrime)
	{

		out << "| " << std::setw(21) << std::left << theCrime.d_provice << " | " << std::setw(15) << std::left << theCrime.d_district << " | " << std::setw(20) << std::left << theCrime.d_crime << " | " << std::setw(6) << std::right << theCrime.d_year << " | " << std::setw(4) << std::right << theCrime.d_number_of_cases << " | " << std::setw(3) << std::right << theCrime.m_resolved << " |";

		return out;

	}

}