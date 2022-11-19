//******************************************************************//
//                                                                  //
// NAME       : DEV JIGISHKUMAR SHAH                                // 
// STUDENT ID : 131623217                                           //
// MAIL ID    : djshah11@myseneca.ca                                //
// COURSE     : OOP 345 NFF                                         //
// SUBMISSION : WORKSHOP 8 (PART 1)                                 //
//                                                                  //
//******************************************************************// 
//                                                                  //
// AUTHENTICITY DECLARATION :                                       //
// I HAVE DONE ALL THE CODING BY MYSELF AND ONLY COPIED THE CODE    //
// THAT MY PROFESSOR PROVIDED TO COMPLETE MY WORKSHOPS AND          //
// ASSIGNMENTS.                                                     //
//                                                                  //
//******************************************************************//

// REQUIRED HEADER FILES.
#include "GeneratingList.h"
#include "EmpProfile.h"
#include "WritingRecord.h"

using namespace std;

namespace sdds
{

	GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {

		// VARIABLE DECLARATION.
		GeneratingList<EmployeeWage> active_employees;

		for (size_t i = 0; i < emp.size(); i++)
		{

			for (size_t j = 0; j < sal.size(); j++)
			{

				if (emp[i].id == sal[j].id)
				{

					// VARIABLE DECLARATION.
					EmployeeWage new_employee(emp[i].name, sal[j].salary);

					new_employee.rangeValidator();

					if (!active_employees.checkLuhn(emp[i].id)) throw std::string("*** Wrong Salaries with SIN No's");

					active_employees += &new_employee;

				}

			}

		}

		return active_employees;

	}

	GeneratingList<EmployeeWage> writeSmart(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {

		// VARIABLE DECLARATION.
		GeneratingList<EmployeeWage> active_employees;

		for (size_t i = 0; i < emp.size(); i++)
		{

			for (size_t j = 0; j < sal.size(); j++)
			{

				if (emp[i].id == sal[j].id)
				{

					// VARIABLE DECLARATION.
					std::unique_ptr<EmployeeWage> new_employee(new EmployeeWage(emp[i].name, sal[j].salary));

					new_employee->rangeValidator();

					if (!active_employees.checkLuhn(emp[i].id)) throw std::string("Error");

					active_employees += *new_employee;

				}

			}

		}

		return active_employees;
	}

}