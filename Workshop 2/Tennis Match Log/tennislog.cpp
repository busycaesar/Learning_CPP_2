#include"tennislog.h"

namespace sdds
{

	TennisMatch::TennisMatch()
	{

		setEmpty();

	}

	void TennisMatch::setEmpty()
	{

		m_tournamentId = "\0";
		m_tournamentName = "\0";
		m_matchId = 0;
		m_winner = "\0";
		m_loser = "\0";

	}

	bool TennisMatch::isEmpty()const
	{

		return m_tournamentId == "\0";

	}

	std::ostream& TennisMatch::display(std::ostream& os)const
	{

		if (isEmpty())
		{

			// TO BE COMPLETED // TO BE COMPLETED // TO BE COMPLETED // TO BE COMPLETED // TO BE COMPLETED // TO BE COMPLETED // TO BE COMPLETED // TO BE COMPLETED // TO BE COMPLETED // TO BE COMPLETED // TO BE COMPLETED // TO BE COMPLETED // TO BE COMPLETED // TO BE COMPLETED // TO BE COMPLETED

		}
		else
		{

			// TO BE COMPLETED // TO BE COMPLETED // TO BE COMPLETED // TO BE COMPLETED // TO BE COMPLETED // TO BE COMPLETED // TO BE COMPLETED // TO BE COMPLETED // TO BE COMPLETED // TO BE COMPLETED // TO BE COMPLETED // TO BE COMPLETED // TO BE COMPLETED // TO BE COMPLETED // TO BE COMPLETED

		}

	}

	TennisLog::TennisLog()
	{



	}

	TennisLog::TennisLog(std::string file)
	{



	}

	void TennisLog::addMatch(TennisMatch& match)
	{



	}

	TennisLog& TennisLog::findMatches(std::string player)
	{



	}

	TennisMatch TennisLog::operator[](size_t)
	{



	}

	TennisLog::operator size_t()
	{



	}

	std::ostream& operator<<(std::ostream& os, TennisMatch& match)
	{

		return match.display(os);
	
	}

}