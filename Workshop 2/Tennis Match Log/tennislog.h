#ifndef SDDS_TENNISLOG_H
#define SDDS_TENNISLOG_H

#include <string>

namespace sdds
{

	// STRUCTS // CLASSES.
	struct TennisMatch
	{

		// DATA MEMBERS.
		std::string m_tournamentId;
		std::string m_tournamentName;
		unsigned int m_matchId;
		std::string m_winner;
		std::string m_loser;

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

		// CONSTRUCTORS AND DESTRUCTORS.
		TennisLog();
		TennisLog(std::string file);

		// MEMBER FUNCTIONS.
		void addMatch(TennisMatch& match);
		TennisLog& findMatches(std::string player);
		TennisMatch operator[](size_t);
		operator size_t();

	};

	// FUNCTIONS.
	std::ostream& operator<<(std::ostream& os, TennisMatch& match);

}

#endif // !SDDS_TENNISLOG_H
