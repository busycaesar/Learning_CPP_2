//******************************************************************//
//                                                                  //
// NAME       : DEV JIGISHKUMAR SHAH                                // 
// STUDENT ID : 131623217                                           //
// MAIL ID    : djshah11@myseneca.ca                                //
// COURSE     : OOP 345 NFF                                         //
// SUBMISSION : WORKSHOP 9 (PART 2)                                  //
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
#include <iostream>
#include <fstream>
#include <string>
#include "TreasureMap.h"

namespace sdds {

	size_t digForTreasure(const std::string& str, char mark)
	{

		// VARIABLE DECLARATION.
		size_t cnt = 0;

		for (auto& x : str) { if (x == mark) cnt++; }

		return cnt;

	}

	TreasureMap::TreasureMap(const char* filename)
	{

		// VARIABLE DECLARATION.
		std::fstream fin(filename);

		if (fin)
		{

			fin >> rows;
			fin.ignore();
			map = new std::string[rows];
			size_t idx = 0;

			while (fin)
			{

				getline(fin, map[idx]);
				idx++;

			}

			colSize = map[0].length();

		}
		else { throw std::string(filename) + " cannot be opened"; }

	}

	TreasureMap::~TreasureMap() { delete[] map; }

	std::ostream& TreasureMap::display(std::ostream& os) const
	{

		if (map) { for (size_t i = 0; i < rows; ++i) os << map[i] << std::endl; }
		else os << "The map is empty!" << std::endl;

		return os;

	}

	void TreasureMap::enscribe(const char* filename)
	{

		// Binary write
		if (map)
		{

			// VARIABLE DECLARATION.
			std::fstream data_file(filename, std::ios::binary | std::ios::out);

			if (data_file)
			{

				data_file.write((char*)&rows, sizeof(size_t));
				data_file.write((char*)&colSize, sizeof(size_t));

				for (size_t i = 0; i < rows; ++i) data_file.write(map[i].c_str(), colSize);

			}

		}
		else throw std::string("Treasure map is empty!");

	}

	void TreasureMap::recall(const char* filename)
	{

		// VARIABLE DECLARATION.
		std::fstream fin(filename, std::ios::binary | std::ios::in);

		if (fin)
		{

			fin.read((char*)&rows, sizeof(size_t));
			fin.read((char*)&colSize, sizeof(size_t));

			map = new std::string[rows];

			for (size_t i = 0; i < rows; ++i)
			{

				// VARIABLE DECLARATION.
				char* row = new char[colSize + 1];
				fin.read(row, colSize);
				row[colSize] = '\0';
				map[i] = row;
				delete[] row;

			}

		}

	}

	void TreasureMap::clear()
	{

		delete[] map;
		map = nullptr;
		rows = 0;
		colSize = 0;

	}

	size_t TreasureMap::findTreasure(char mark)
	{

		// VARIABLE DECLARATION.
		size_t count = 0;
		packed_task* task = new packed_task[rows];
		future_variable* task_answers = new future_variable[rows];
		std::thread* threads = new std::thread[this->rows];

		for (size_t i = 0; i < rows; i++)
		{

			task[i] = std::move(packed_task(std::bind(digForTreasure, map[i], mark)));
			task_answers[i] = task[i].get_future();

			threads[i] = std::thread(std::move(task[i]));

			count += task_answers[i].get();

		}

		for (size_t i = 0; i < rows; i++) threads[i].join();

		delete[] threads;
		delete[] task;
		delete[]task_answers;

		return count;

	}

}