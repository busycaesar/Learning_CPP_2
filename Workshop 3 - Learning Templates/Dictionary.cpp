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

#define _CRT_SECURE_NO_WARNINGS

#include"Dictionary.h"

namespace sdds
{

	bool Dictionary::operator==(const Dictionary& RO)const
	{

		return (m_term == RO.m_term);

	}

	std::ostream& Dictionary::display(std::ostream& out)const
	{

		out << std::setw(20) << std::right << m_term << ": " << m_definition;

		return out;

	}

	std::ostream& operator<<(std::ostream& out, const Dictionary source)
	{

		return source.display(out);

	}

}