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

			os << "Empty Match" << std::endl;

		}
		else
		{

			os << std::right << std::setw(20) << std::setfill(".") << "Tournament ID : " << m_tournamentId << std::left << std::setw(30) << std::setfill(".") << std::endl
				<< std::right << std::setw(20) << std::setfill(".") << "Match ID : " << std::left << std::setw(30) << std::setfill(".") << m_matchId << std::endl
				<< std::right << std::setw(20) << std::setfill(".") << "Tourney : " << m_tournamentName << std::left << std::setw(30) << std::setfill(".") << std::endl
				<< std::right << std::setw(20) << std::setfill(".") << "Winner" << m_winner << std::left << std::setw(30) << std::setfill(".") << std::endl
				<< std::right << std::setw(20) << std::setfill(".") << "Loser : " << m_loser << std::left << std::setw(30) << std::setfill(".") << std::endl;

		}

	}

	TennisLog::TennisLog()
	{



	}

	TennisLog::TennisLog(std::string file)
	{

		m_matcheCount = countLines(file) - 1;
		m_matche = new TennisMatch[m_matcheCount];

		std::ifstream f_data(file);
		std::cin.ignore(1000, '\n');

		for (int i = 0; i < m_matcheCount; i++)
		{

			std::cin >> m_matche[i].m_tournamentId;


		}

	}

	void TennisLog::addMatch(TennisMatch& source)
	{



	}

	TennisLog& TennisLog::findMatches(std::string player)
	{



	}

	TennisMatch TennisLog::operator[](size_t)
	{



	}

	int TennisLog::countLines(std::string filename)
	{

		// VARIABLE DECLARATION.
		std::ifstream f_fin(filename);
		int f_count = 0;

		while (f_fin)
		{

			if (f_fin.get() == '\n')f_count++;

		}

		f_fin.close();

		return f_count;

	}

	TennisLog::operator size_t()
	{



	}

	std::ostream& operator<<(std::ostream& os, TennisMatch& source)
	{

		return source.display(os);

	}

}