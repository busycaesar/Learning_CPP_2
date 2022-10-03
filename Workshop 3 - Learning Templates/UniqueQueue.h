//******************************************************************//
//                                                                  //
// NAME       : DEV JIGISHKUMAR SHAH                                // 
// STUDENT ID : 131623217                                           //
// MAIL ID    : djshah11@myseneca.ca                                //
// COURSE     : OOP 345 NFF                                         //
// SUBMISSION : WORKSHOP 3 (PART 2)                                 //
//                                                                  //
//******************************************************************// 
//                                                                  //
// AUTHENTICITY DECLARATION :                                       //
// I HAVE DONE ALL THE CODING BY MYSELF AND ONLY COPIED THE CODE    //
// THAT MY PROFESSOR PROVIDED TO COMPLETE MY WORKSHOPS AND          //
// ASSIGNMENTS.                                                     //
//                                                                  //
//******************************************************************//

#ifndef SDDS_UNIQUEQUEUE_H
#define SDDS_UNIQUEQUEUE_H

#include"Queue.h"
#include <cmath>

namespace sdds
{

	// CLASS
	template<typename type>
	class UniqueQueue : public Queue<type, 100>
	{

	public:

		bool push(const type& newEle)
		{

			// VARIABLE DECLARATION.
			bool success = false, isPresent = false;

			for (int i = 0; i < Queue<type, 100>::m_actual; i++)
				if (newEle == Queue<type, 100>::m_queue[i])isPresent = true;

			if (!isPresent)success = Queue<type, 100>::push(newEle);

			return success;

		}

	};

	template<>
	bool UniqueQueue<double>::push(const double& newEle)
	{

		// VARIABLE DECLARATION.
		bool success = false, isPresent = false;

		for (int i = 0; i < Queue<double, 100>::m_actual; i++)
			if (std::fabs(newEle - Queue<double, 100>::m_queue[i]) <= 0.005)isPresent = true;

		if (!isPresent)success = Queue<double, 100>::push(newEle);

		return success;

	}

}

#endif // !SDDS_UNIQUEQUEUE_H
