#ifndef SDDS_DICTIONARY_H
#define SDDS_DICTIONARY_H

#include<string>
#include<iomanip>

namespace sdds
{

	// CLASS.
	class Dictionary
	{

		// DATA MEMBER.
		std::string m_term{}, m_definition{};

	public:

		// CONSTRUCTOR.
		Dictionary() {};
		Dictionary(const std::string& term, const std::string& definition) : m_term{ term }, m_definition{ definition } {}

		// MEMBER FUNCTIONS.
		const std::string& getTerm() const { return m_term; }
		const std::string& getDefinition() const { return m_definition; }
		std::ostream& display(std::ostream& out) const;

	};

	std::ostream& operator <<(std::ostream& out, Dictionary source);

}

#endif // !SDDS_DICTIONARY_H