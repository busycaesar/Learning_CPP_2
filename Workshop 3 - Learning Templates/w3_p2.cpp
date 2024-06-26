// Workshop 3 - Templates
// 2022/06/22 - This code was made by Nathan.

// HEADER FILES.
#include <iostream>
#include <iomanip>
#include "Queue.h"
#include "Queue.h"
#include "UniqueQueue.h"
#include "UniqueQueue.h"
#include "Dictionary.h"
#include "Dictionary.h"

// VARIABLE DECLARATION.
int cout = 0; // won't compile if headers don't follow convention

int main(int argc, char** argv)
{

	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";

	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';

	std::cout << "--------------------------\n\n";

	// Data to be used by the template classes
	// VARIABLE DECLARATION.
	long   dataSetA[]{ 22, 1, 455, 90, 455, 6, 43 };
	double dataSetB[]{ 34.556, 3333.3303, 122.55, 3333.3333, 678.54, 3333.3389 };
	sdds::Dictionary pData[]{
		sdds::Dictionary("dome", "a rounded vault forming the roof of a building or structure."),
		sdds::Dictionary("pollution", "An introduction into the environment of a substance that has harmful effect"),
		sdds::Dictionary("slide", "a structure with a smooth sloping surface for children to slide down."),
		sdds::Dictionary("complete", "having all the necessary or appropriate parts"),
		sdds::Dictionary("pollution", "An introduction into the environment of a substance that has harmful effect"),
		sdds::Dictionary("slide", "a structure with a smooth sloping surface for children to slide down."),
		sdds::Dictionary("complete", "having all the necessary or appropriate parts"),
		sdds::Dictionary("acceptable", "able to be agreed on; suitable"),
		sdds::Dictionary("dome", "a rounded vault forming the roof of a building or structure.")
	};

	{

		std::cout << "******************************************************\n";
		std::cout << "* Testing the Queue of Integers                      *\n";
		std::cout << "******************************************************\n";

		// VARIABLE DECLARATION.
		sdds::Queue<long, 20> colIntegers;

		for (const auto& item : dataSetA)
			colIntegers.push(item);

		std::cout << "Queue size: [" << colIntegers.size() << "]\n";
		colIntegers.display();

		std::cout << "Item [0]: " << colIntegers[0] << "\n";
		std::cout << "Item [5]: " << colIntegers[5] << "\n";
		std::cout << "Item [9]: " << colIntegers[9] << "\n";
		std::cout << "******************************************************\n\n";

	}

	{

		std::cout << "******************************************************\n";
		std::cout << "* Testing the UniqueQueue of Integers                *\n";
		std::cout << "******************************************************\n";

		// VARIABLE DECLARATION.
		sdds::Queue<long, 100>* UniqueQueueIntegers = new sdds::UniqueQueue<long>();

		for (const auto& item : dataSetA)
			UniqueQueueIntegers->push(item);

		std::cout << "UniqueQueue size: [" << UniqueQueueIntegers->size() << "]\n";
		UniqueQueueIntegers->display();

		std::cout << "Item [0]: " << (*UniqueQueueIntegers)[0] << "\n";
		std::cout << "Item [5]: " << (*UniqueQueueIntegers)[5] << "\n";
		std::cout << "Item [9]: " << (*UniqueQueueIntegers)[9] << "\n\n";

		std::cout << "----------------------\n";
		std::cout << "| Testing Pop		   |\n";
		std::cout << "----------------------\n\n";

		std::cout << "Popped Item: " << UniqueQueueIntegers->pop() << std::endl;
		std::cout << "----------------------\n";
		UniqueQueueIntegers->display();
		std::cout << "******************************************************\n\n";
		delete UniqueQueueIntegers;

	}

	{

		std::cout << "******************************************************\n";
		std::cout << "* Testing the Queue of Floats                        *\n";
		std::cout << "******************************************************\n";

		// VARIABLE DECLARATION.
		sdds::Queue<double, 30> colFloats;

		for (const auto& item : dataSetB)
			colFloats.push(item);

		std::cout << "Queue size: [" << colFloats.size() << "]\n";
		colFloats.display();

		std::cout << "Item [0]: " << colFloats[0] << "\n";
		std::cout << "Item [5]: " << colFloats[5] << "\n";
		std::cout << "Item [9]: " << colFloats[9] << "\n";
		std::cout << "******************************************************\n\n";

	}

	{

		std::cout << "******************************************************\n";
		std::cout << "* Testing the UniqueQueue of Floats                  *\n";
		std::cout << "******************************************************\n";

		// VARIABLE DECLARATION.
		sdds::Queue<double, 100>* UniqueQueueFloats = new sdds::UniqueQueue<double>;

		for (const auto& item : dataSetB)
			UniqueQueueFloats->push(item);

		std::cout << "UniqueQueue size: [" << UniqueQueueFloats->size() << "]\n";
		UniqueQueueFloats->display();

		std::cout << "Item [1]: " << std::fixed << std::setprecision(4) << (*UniqueQueueFloats)[1] << "\n";
		std::cout << "Item [4]: " << std::fixed << std::setprecision(4) << (*UniqueQueueFloats)[4] << "\n";
		std::cout << "Item [9]: " << std::fixed << std::setprecision(4) << (*UniqueQueueFloats)[9] << "\n\n";

		std::cout << "----------------------\n";
		std::cout << "| Testing Pop		   |\n";
		std::cout << "----------------------\n\n";

		std::cout << "Popped Item: " << UniqueQueueFloats->pop() << std::endl;
		std::cout << "----------------------\n";
		UniqueQueueFloats->display();

		std::cout << "******************************************************\n\n";
		delete UniqueQueueFloats;

	}

	{

		std::cout << "******************************************************\n";
		std::cout << "* Testing the Queue of Dictionary Objects            *\n";
		std::cout << "******************************************************\n";

		// VARIABLE DECLARATION.
		sdds::Queue<sdds::Dictionary, 50> queueDictionary;

		for (const auto& item : pData)
			queueDictionary.push(item);

		std::cout << "Queue size: [" << queueDictionary.size() << "]\n";
		queueDictionary.display();

		std::cout << "Item [0]: [" << queueDictionary[0].getTerm() << "]["
			<< queueDictionary[0].getDefinition() << "]\n";
		std::cout << "Item [8]: [" << queueDictionary[8].getTerm() << "]["
			<< queueDictionary[8].getDefinition() << "]\n";
		std::cout << "Item [9]: [" << queueDictionary[9].getTerm() << "]["
			<< queueDictionary[9].getDefinition() << "]\n";
		std::cout << "******************************************************\n\n";

	}

	{

		std::cout << "******************************************************\n";
		std::cout << "* Testing the UniqueQueue of Pairs                   *\n";
		std::cout << "******************************************************\n";

		// VARIABLE DECLARATION.
		sdds::Queue<sdds::Dictionary, 100>* UniqueQueueDictionary = new sdds::UniqueQueue<sdds::Dictionary>();

		for (const auto& item : pData)
			UniqueQueueDictionary->push(item);

		std::cout << "UniqueQueueue size: [" << UniqueQueueDictionary->size() << "]\n";
		UniqueQueueDictionary->display();

		std::cout << "Item [1]: [" << (*UniqueQueueDictionary)[1].getTerm() << "]["
			<< (*UniqueQueueDictionary)[1].getDefinition() << "]\n";
		std::cout << "Item [4]: [" << (*UniqueQueueDictionary)[4].getTerm() << "]["
			<< (*UniqueQueueDictionary)[4].getDefinition() << "]\n";
		std::cout << "Item [11]: [" << (*UniqueQueueDictionary)[11].getTerm() << "]["
			<< (*UniqueQueueDictionary)[11].getDefinition() << "]\n";

		std::cout << "----------------------\n";
		std::cout << "| Testing Pop        |\n";
		std::cout << "----------------------\n\n";

		std::cout << "Popped Item: " << UniqueQueueDictionary->pop() << std::endl;
		std::cout << "----------------------\n";
		UniqueQueueDictionary->display();


		std::cout << "******************************************************\n\n";
		delete UniqueQueueDictionary;

	}

	return cout;
}