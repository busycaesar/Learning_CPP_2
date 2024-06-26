// Workshop 9 - Multi-threading
// TreasureMap.h
// Michael Huang

#ifndef SDDS_TREASUREMAP_H
#define SDDS_TREASUREMAP_H

// REQUIRED HEADER FILES.
#include<cstddef>
#include<iostream>
#include<fstream>
#include <thread>
#include <future>
#include <functional>

// MACROS.
#define packed_task std::packaged_task<size_t()>
#define future_variable std::future<size_t>

namespace sdds
{

	size_t digForTreasure(const std::string& str, char mark);

	// CLASS.
	class TreasureMap
	{

		// VARIABLE DECLARATION.
		size_t rows = 0;
		size_t colSize = 0;
		std::string* map = nullptr;

	public:

		// METHODS.

		// CONSTRUCTORS AND DESTRUCTORS.
		TreasureMap(const char* filename);
		~TreasureMap();

		// OPERATORS.
		std::string operator[](int i) const { return map[i % rows]; }

		// QUERIES.
		size_t size() const { return rows; }

		// METHODS.
		std::ostream& display(std::ostream& os) const;
		void enscribe(const char* filename);
		void recall(const char* filename);
		void clear();
		size_t findTreasure(char mark);

	};

}

#endif