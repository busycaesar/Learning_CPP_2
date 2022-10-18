//******************************************************************//
//                                                                  //
// NAME       : DEV JIGISHKUMAR SHAH                                // 
// STUDENT ID : 131623217                                           //
// MAIL ID    : djshah11@myseneca.ca                                //
// COURSE     : OOP 345 NFF                                         //
// SUBMISSION : WORKSHOP 5 (PART 2)                                 //
//                                                                  //
//******************************************************************// 
//                                                                  //
// AUTHENTICITY DECLARATION :                                       //
// I HAVE DONE ALL THE CODING BY MYSELF AND ONLY COPIED THE CODE    //
// THAT MY PROFESSOR PROVIDED TO COMPLETE MY WORKSHOPS AND          //
// ASSIGNMENTS.                                                     //
//                                                                  //
//******************************************************************//

#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

#include<iostream>
#include<string>

namespace sdds
{

	// CLASS TEMPLATE.
	template<typename T>
	class Collection
	{

		// CLASS NAME.
		// Collection.

		// CLASS PURPOSE.
		// FOR THE COLLECTION OF OBJECTS OF TYPE T.

		// DATA MEMBER.
		std::string m_name;
		T* m_array;
		size_t m_size;
		void(*m_observer)(const Collection<T>& f_source, const T& f_element);

		// METHOD.
		void setEmpty()
		{

			m_name = "";
			m_array = nullptr;
			m_size = 0;
			m_observer = nullptr;

		}

	public:

		// CONSTRUCTOR AND DESTRUCTOR.

		Collection()
		{

			setEmpty();

		}

		Collection(const std::string& name)
		{

			setEmpty();
			m_name = name;

		}

		Collection(const Collection& source) = delete;

		~Collection()
		{

			delete[] m_array;

		}

		// OPERATOR.

		Collection& operator=(const Collection& source) = delete;

		// METHODS.
		const std::string& name() const { return m_name; }

		size_t size() const { return m_size; }

		void setObserver(void (*observer)(const Collection<T>&, const T&)) { m_observer = observer; }

		Collection<T>& operator+=(const T& item)
		{

			// VARIABLE DECLARATION.
			bool isNotPresent = true;

			for (size_t i = 0; i < m_size; i++)
			{

				if (m_array[i].title() == item.title())isNotPresent = false;

			}

			if (isNotPresent)
			{

				// VARIABLE DECLARATION.
				T* t_temp = new T[m_size + 1];

				for (size_t i = 0; i < m_size; i++) t_temp[i] = m_array[i];

				t_temp[m_size] = item;
				m_size++;

				delete[] m_array;
				m_array = new T[m_size];

				for (size_t i = 0; i < m_size; i++) m_array[i] = t_temp[i];

				delete[] t_temp;

				if (m_observer != nullptr) m_observer(*this, item);

			}

			return *this;

		}

		T& operator[](size_t idx) const
		{

			if ((idx >= 0) && (idx < m_size)) return m_array[idx];
			else throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(m_size) + "] items.");

		}

		T* operator[](const std::string& title) const
		{

			for (size_t i = 0; i < m_size; i++)
			{

				if (m_array[i].title() == title)return &m_array[i];

			}

			return nullptr;

		}

		// HELPER FUNCTIONS.
		// '<<' : INSERTION OPERATOR.

	};

	// HELPER FUNCTION.
	template<typename T>
	std::ostream& operator<<(std::ostream& out, const Collection<T>& source)
	{

		for (size_t i = 0; i < source.size(); i++) out << source[i];

		return out;

	}

}

#endif // !SDDS_COLLECTION_H
