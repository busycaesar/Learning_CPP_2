#ifndef SDDS_QUEUE_H
#define SDDS_QUEUE_H

#include"Dictionary.h"

namespace sdds
{

	// CLASS.
	template<typename type, unsigned int N>
	class Queue
	{

		// DATA MEMBER
		type m_queue[N];
		int m_capacity, m_actual;

		// MEMBER FUNCTION.
		void setEmpty()
		{

			m_capacity = N;
			m_actual = 0;

		}

	public:

		// CONSTRUCTORS.
		Queue() { setEmpty(); }

		// MEMBER FUNCTIONS.
		bool push(const type& newEle)
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

			type temp = m_queue[0];

			for (int i = 0; i < (m_actual - 1); i++)
			{

				m_queue[i] = m_queue[i + 1];

			}

			m_queue[m_actual - 1] = 0;

			return temp;

		}

		int size() const { return m_actual; }

		std::ostream& display(std::ostream& out = std::cout)
		{

			out << "----------------------" << std::endl << "| Dictionary Content |" << std::endl << "----------------------" << std::endl;

			for (int i = 0; i < m_actual; i++)
			{

				out << m_queue[i] << std::endl;

			}

			out << "----------------------" << std::endl;

			return out;

		}

		type operator[](int index)
		{

			type temp{};

			if (index < m_actual) temp = m_queue[index];

			return temp;

		}

	};

	template<>
	Queue<Dictionary, 100>::Queue()
	{

		Dictionary dic("Empty Term", "Empty Substitute");

	}

}

#endif // !SDDS_QUEUE_H