#ifndef SDDS_DICTIONARY_H
#define SDDS_DICTIONARY_H

#include<string>

namespace sdds
{

	// CLASS.
	class Dictionary
	{

		// DATA MEMBER.
		std::string m_term{};
		std::string m_definition{};

	public:

		// CONSTRUCTOR.
		Dictionary(const std::string& term, const std::string& definition) : m_term{ term }, m_definition{ definition } {}
		
		// MEMBER FUNCTIONS.
		const std::string& getTerm() const { return m_term; }
		const std::string& getDefinition() const { return m_definition; }

		// TODO: Code the missing prototype functions and operators
		//       that the class needs in order to work with the Queue class.
		//       Implement them in the Dictionary.cpp file.
	
	};

}

#endif // !SDDS_DICTIONARY_H
