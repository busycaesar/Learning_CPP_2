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

#include"Timer.h"

namespace sdds
{

	void Timer::start()
	{

		m_startTime = std::chrono::steady_clock::now();

	}

	long long Timer::stop()
	{

		m_stopTime = std::chrono::steady_clock::now();

		return std::chrono::duration_cast<std::chrono::nanoseconds>(m_stopTime - m_startTime).count();

	}

}