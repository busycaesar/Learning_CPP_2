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

		// MEMBER FUNCTIONS.
		void setEmpty();
		bool isEmpty()const;
		std::ostream& display(std::ostream& os)const;

	};

	class TennisLog
	{

		// DATA MEMBERS.
		TennisMatch* m_matche;
		int m_matcheCount;

		// CONSTRUCTORS AND DESTRUCTORS.
		TennisLog();
		TennisLog(std::string file);

		// MEMBER FUNCTIONS.
		void addMatch(TennisMatch& source);
		TennisLog& findMatches(std::string player);
		TennisMatch operator[](size_t);
		int countLines(std::string file);

		// OPERATORS.
		operator size_t();

	};

	// FUNCTIONS.
	std::ostream& operator<<(std::ostream& os, TennisMatch& source);

}

#endif // !SDDS_TENNISLOG_H
