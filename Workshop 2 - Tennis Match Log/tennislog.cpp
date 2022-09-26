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

#include"TennisLog.h"

namespace sdds
{

	TennisMatch::TennisMatch()
	{

		setEmpty();

	}

	TennisMatch::TennisMatch(std::string tourId, std::string tourName, int matchID, std::string tourWinner, std::string tourLoser)
	{

		setEmpty();

		m_tournamentId = tourId;
		m_tournamentName = tourName;
		m_matchId = matchID;
		m_winner = tourWinner;
		m_loser = tourLoser;

	}

	void TennisMatch::setEmpty()
	{

		m_tournamentId = "\0";
		m_tournamentName = "\0";
		m_matchId = 0;
		m_winner = "\0";
		m_loser = "\0";

	}

	TennisLog::TennisLog()
	{

		setEmptyData();

	}

	TennisLog::TennisLog(std::string file)
	{

		// VARIABLE DECALRATION.
		std::ifstream f_data(file);
		std::string f_matchId;

		setEmptyData();

		m_matcheCount = countLines(file) - 1;

		if (f_data)
		{

			m_matche = new TennisMatch[m_matcheCount];

			f_data.ignore(1000, '\n');
			// THIS WILL IGNORE THE FIRST LINE WHICH INCLUDES TITLE.

			for (size_t i = 0; i < m_matcheCount; i++)
			{

				std::getline(f_data, m_matche[i].m_tournamentId, ',');

				std::getline(f_data, m_matche[i].m_tournamentName, ',');

				std::getline(f_data, f_matchId, ',');
				m_matche[i].m_matchId = std::stoi(f_matchId);

				std::getline(f_data, m_matche[i].m_winner, ',');

				std::getline(f_data, m_matche[i].m_loser, '\n');

			}

		}
		else
		{

			std::cout << "Cant open the file." << std::endl;

		}

	}

	TennisLog::TennisLog(const TennisLog& source)
	{

		setEmptyData();
		*this = source;

	}

	TennisLog::TennisLog(TennisLog&& source)
	{

		setEmptyData();
		*this = std::move(source);
		source.m_matche = nullptr;
		source.m_matcheCount = 0;

	}

	TennisLog::~TennisLog()
	{

		delete[] m_matche;

	}

	void TennisLog::addMatch(const TennisMatch& source)
	{

		// VARAIBLE DECLARATION.
		TennisMatch* temp = new TennisMatch[m_matcheCount + 1];

		for (size_t i = 0; i < m_matcheCount; i++)
		{

			temp[i] = m_matche[i];

		}

		temp[m_matcheCount] = source;

		m_matcheCount++;

		delete[] m_matche;

		m_matche = temp;

	}

	TennisLog TennisLog::findMatches(std::string player)const
	{

		// VARIABLE DECLARATION
		TennisLog f_matched;

		for (size_t i = 0; i < m_matcheCount; i++)
		{

			if (!(m_matche[i].m_winner.compare(player)) || !(m_matche[i].m_loser.compare(player))) {
				TennisMatch f_match(m_matche[i].m_tournamentId, m_matche[i].m_tournamentName, m_matche[i].m_matchId, m_matche[i].m_winner, m_matche[i].m_loser);
				f_matched.addMatch(f_match);

			}

		}

		return f_matched;

	}

	TennisMatch TennisLog::operator[](size_t index)
	{

		// VARIABLE DECLARATION.
		TennisMatch temp;

		if (index < m_matcheCount)
		{

			temp = m_matche[index];

		}

		return temp;

	}

	size_t TennisLog::countLines(std::string filename)const
	{

		// VARIABLE DECLARATION.
		std::ifstream f_fin(filename);
		size_t f_count = 0;

		if (f_fin)
		{

			while (!f_fin.eof())
			{

				if (f_fin.get() == '\n')f_count++;

			}

			f_fin.close();

		}
		else
		{

			std::cout << "Can't open the file." << std::endl;

		}

		return f_count;

	}

	TennisLog::operator size_t()const
	{

		return m_matcheCount;

	}

	void TennisLog::setEmptyData()
	{

		m_matche = nullptr;
		m_matcheCount = 0;

	}

	TennisLog& TennisLog::operator=(const TennisLog& source)
	{

		if (this != &source)
		{

			delete[] m_matche;

			m_matche = new TennisMatch[source.m_matcheCount];

			m_matcheCount = source.m_matcheCount;

			for (size_t i = 0; i < m_matcheCount; i++)
			{

				m_matche[i] = source.m_matche[i];

			}

		}

		return *this;

	}

	TennisLog& TennisLog::operator=(TennisLog&& source)
	{

		if (this != &source)
		{

			delete[] m_matche;

			m_matche = source.m_matche;
			m_matcheCount = source.m_matcheCount;
			source.m_matche = nullptr;
			source.m_matcheCount = 0;

		}

		return *this;

	}

	std::ostream& operator<<(std::ostream& os, const TennisMatch& source)
	{

		if (source.m_tournamentId == "\0")
		{

			os << "Empty Match";

		}
		else
		{

			os << std::setw(20) << std::setfill('.') << std::right << "Tourney ID" << " : " << std::setw(30) << std::setfill('.') << std::left << source.m_tournamentId << std::endl;
			os << std::setw(20) << std::setfill('.') << std::right << "Match ID" << " : " << std::setw(30) << std::setfill('.') << std::left << source.m_matchId << std::endl;
			os << std::setw(20) << std::setfill('.') << std::right << "Tourney" << " : " << std::setw(30) << std::setfill('.') << std::left << source.m_tournamentName << std::endl;
			os << std::setw(20) << std::setfill('.') << std::right << "Winner" << " : " << std::setw(30) << std::left << source.m_winner << std::endl;
			os << std::setw(20) << std::setfill('.') << std::right << "Loser" << " : " << std::setw(30) << std::left << source.m_loser << std::endl;

		}

		return os;

	}

}