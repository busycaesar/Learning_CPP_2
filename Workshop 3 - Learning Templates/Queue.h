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

#ifndef SDDS_QUEUE_H
#define SDDS_QUEUE_H

#include"Dictionary.h"

namespace sdds
{

	// CLASS.
	template<typename type, unsigned int N>
	class Queue
	{

	protected:

		// DATA MEMBER
		type m_queue[N], m_dummy;
		int m_capacity, m_actual;

		// MEMBER FUNCTION.
		void setEmpty()
		{

			m_dummy = {};
			m_capacity = N;
			m_actual = 0;

		}

	public:

		// CONSTRUCTORS AND DESTRUCTORS.
		Queue() { setEmpty(); }
		virtual ~Queue() {}

		// MEMBER FUNCTIONS.
		virtual bool push(const type& newEle)
		{

			// VARIABLE DECLARATION.
			bool success = false;

			if (m_actual < m_capacity)
			{

				m_queue[m_actual++] = newEle;
				success = true;

			}

			return success;

		}

		type pop()
		{

			m_dummy = m_queue[0];

			m_actual--;

			for (int i = 0; i < m_actual; i++)m_queue[i] = m_queue[i + 1];

			return m_dummy;

		}

		int size() const { return m_actual; }

		std::ostream& display(std::ostream& out = std::cout)
		{

			out << "----------------------" << std::endl << "| Dictionary Content |" << std::endl << "----------------------" << std::endl;

			for (int i = 0; i < m_actual; i++) out << m_queue[i] << std::endl;

			out << "----------------------" << std::endl;

			return out;

		}

		type operator[](int index)
		{

			type temp = m_dummy;

			if (index < m_actual)temp = m_queue[index];

			return temp;

		}

	};

	template<>
	Queue<Dictionary, 100>::Queue()
	{

		m_dummy = { "Empty Term","Empty Substitute"};
		m_capacity = 100;

	}

}

#endif // !SDDS_QUEUE_H