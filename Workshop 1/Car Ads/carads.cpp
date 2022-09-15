#include"carads.h"

namespace sdds
{

	void listArgs(int argc, char* argv[])
	{

		cout << "Command Line" << endl << "--------------------------";

		for (int i = 0; i < argc; i++)cout << i << ": " << argv[i] << endl;

	}

	Cars::Cars()
	{

		setEmpty();

	}

	void Cars::setEmpty()
	{

		m_brand[0] = '\0';
		m_model[0] = '\0';
		m_carStatus = '\0';
		m_manuYear = 0000;
		m_price = 0.0;
		m_isDiscount = false;
		m_counter = 0;

	}

	void Cars::read(istream& is)
	{

		if (is)
		{

			// VARIABLE DECLARATION.
			char* f_discount='\0';

			is.getline(m_carStatus, 1, ',');
			is.getline(m_brand, 9, ',');
			is.getline(m_model, 14, ',');
			is >> m_manuYear;
			is >> m_price;
			is.getline(f_discount, 1, '\n');

			switch (*f_discount)
			{

			case 'Y':
				m_isDiscount = true;
				break;
			case 'N':
				m_isDiscount = false;
				break;
			}

		}

	}

	void Cars::display(bool reset)
	{

		if (m_brand[0] = '\0')
		{

			cout << left << setw(2) << m_counter++ << left << setw(10) << m_brand << " | " << left << setw(15) << m_model << " | " << setw(7) << m_manuYear << " | " << left << setw(7);
			setprecision(2);
			cout << m_price + g_taxrate;

			if (m_isDiscount)cout << right << setw(12) << (m_price + g_taxrate) - g_discount;

			cout << endl;

		}
		else
		{

			cout << m_counter++ << " No Car" << endl;

		}

		if (reset)m_counter = 0;

	}

	char Cars::getStatus()
	{

		return *m_carStatus;

	}

}