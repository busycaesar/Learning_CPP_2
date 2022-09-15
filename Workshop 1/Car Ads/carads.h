#ifndef SDDS_CARADS_H
#define SDDS_CARADS_H

#include<iostream>
#include<cstring>
#include<iomanip>

using namespace std;

// VARIABLE DECLARATION.
extern double g_taxrate;
extern double g_discount;

namespace sdds
{

	void listArgs(int argc, char* argv[]);

	// CLASS.
	class Cars
	{

		// DATA MEMBERS.
		char m_brand[10], m_model[15];
		int m_manuYear, m_counter;
		double m_price;
		char* m_carStatus;
		bool m_isDiscount;

	public:

		// CONSTRUCTOR.
		Cars();

		// MEMBER FUNCTION.
		void setEmpty();
		void read(istream& is);
		void display(bool reset);
		char getStatus();

	};

}

#endif // !SDDS_CARADS_H

