//******************************************************************//
//                                                                  //
// NAME       : DEV JIGISHKUMAR SHAH                                // 
// STUDENT ID : 131623217                                           //
// MAIL ID    : djshah11@myseneca.ca                                //
// COURSE     : OOP 345 NFF                                         //
// SUBMISSION : WORKSHOP 2 (PART 2)                                 //
//                                                                  //
//******************************************************************// 
//                                                                  //
// AUTHENTICITY DECLARATION :                                       //
// I HAVE DONE ALL THE CODING BY MYSELF AND ONLY COPIED THE CODE    //
// THAT MY PROFESSOR PROVIDED TO COMPLETE MY WORKSHOPS AND			//
// ASSIGNMENTS.													    //
//                                                                  //
//******************************************************************//

#ifndef SDDS_TENNISLOG_H
#define SDDS_TENNISLOG_H

#include <string>
#include<iostream>
#include<iomanip>
#include<fstream>

namespace sdds
{

	// STRUCTS // CLASSES.
	struct TennisMatch
	{

		// DATA MEMBERS.
		std::string m_tournamentId, m_tournamentName, m_winner, m_loser;
		unsigned int m_matchId;

		// CONSTRUCTORS AND DESTRUCTOR.
		TennisMatch();
		TennisMatch(std::string tourId, std::string tourName, int matchID, std::string tourWinner, std::string tourLoser);

		// MEMBER FUNCTIONS.
		void setEmpty();

		friend std::ostream& operator<<(std::ostream& os, const TennisMatch& match);

	};

	// HELPER FUNCTIONS.
	std::ostream& operator<<(std::ostream& os, const TennisMatch& match);

	class TennisLog
	{

		// DATA MEMBERS.
		TennisMatch* m_matche;
		size_t m_matcheCount;

		// MEMBER FUNCTIONS.
		size_t countLines(std::string file)const;
		void setEmptyData();

	public:

		// CONSTRUCTORS AND DESTRUCTORS.
		TennisLog();
		TennisLog(std::string file);
		TennisLog(const TennisLog& source);
		TennisLog(TennisLog&& source);
		~TennisLog();

		// MEMBER FUNCTIONS.
		void addMatch(const TennisMatch& source);
		TennisLog findMatches(std::string player)const;

		// OPERATORS.
		TennisMatch operator[](size_t index);
		operator size_t()const;
		TennisLog& operator=(const TennisLog& source);
		TennisLog& operator=(TennisLog&& source);

	};

}

#endif // !SDDS_TENNISLOG_H
