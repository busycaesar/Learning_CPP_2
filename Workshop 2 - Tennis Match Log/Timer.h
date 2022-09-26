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

#ifndef SDDS_TIMER_H
#define SDDS_TIMER_H

#include<chrono>

namespace sdds
{

	class Timer
	{

		// DATA MEMBER
		std::chrono::time_point<std::chrono::steady_clock, std::chrono::duration<double, std::ratio<1, 1000000000>>> m_startTime;
		std::chrono::time_point<std::chrono::steady_clock, std::chrono::duration<double, std::ratio<1, 1000000000>>> m_stopTime;

	public:

		void start();
		long long stop();

	};

}

#endif // !SDDS_TIMER_H
