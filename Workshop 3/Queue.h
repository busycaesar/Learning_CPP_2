#ifndef SDDS_QUEUE_H
#ifndef SDDS_QUEUE_H
#define SDDS_QUEUE_H

namespace sdds
{

	template<typename T, int N>
	class Queue
	{

		T m_queue[N];
		int m_capacity, m_actual;

	};

}

#endif // !SDDS_QUEUE_H