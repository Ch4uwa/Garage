#include "Garage.h"


Garage::Garage(string garName, int garSize)
	:garName("\n" + garName), garSize(garSize), pSlot(0), isFull(false)
{
	this->garArr = new Vehicle*[garSize];
	for (int i{}; i < garSize; i++)
	{
		this->garArr[i] = 0;
	}
	LOG("Garage ctor");
}

void Garage::freeSlot(int input)
{
	while (garArr[pSlot] != 0 && pSlot < garSize)
	{
		if (garArr[pSlot] != 0)
		{
			pSlot++;
		}
		if (pSlot == garSize)
		{
			std::cout << "\nNo available P-Spot\n";
			isFull = true;
		}
	}
	if (garArr[pSlot] == 0)
	{
		add(input);
	}
}

void Garage::add(int input)
{
	char error = 'a';
	string name{ "" }, regNr{ "" }, color{ "" };
	int	nrWheel{ 0 };
	bool special1{ 0 }, special2{ 0 };

	std::cin.ignore(256, '\n');

	std::cout << "Enter make: ";
	getline(std::cin, name);
	std::cout << "Enter registration number: ";
	getline(std::cin, regNr);
	std::cout << "Enter color: ";
	getline(std::cin, color);

	try
	{
		std::cout << "Enter number of wheels: ";
		std::cin >> nrWheel;
		if (!std::cin)
			throw error;
	}
	catch (...)
	{
		std::cout << "ERROR Input numeric value.";
		std::cin.clear();
		std::cin.ignore(256, '\n');
	}

	switch (input)
	{
	default:
		break;
	case 1: // CAR
	{
		std::cout << "Do you have nav system?\n1. Yes\n0. No";
		std::cin >> special1;
		std::cout << "Should we wash your car?\n1. Yes\n0. No";
		std::cin >> special2;

		garArr[pSlot] = new Car(name, regNr, color, nrWheel, special1, special2);
		std::cout << "Car added to slot: " << pSlot + 1;
		break;
	}
	case 2://BICYCLE
	{
		std::cout << "Do you have a jet engine?\n1. Yes\n0. No";
		std::cin >> special1;
		std::cout << "Is there a rollcage?\n1. Yes\n0. No";
		std::cin >> special2;

		garArr[pSlot] = new Bicycle(name, regNr, color, nrWheel, special1, special2);
		std::cout << "Bicycle added to slot: " << pSlot + 1;
		break;
	}
	}
}

void Garage::printAll()
{
	for (int i = 0; i < this->garSize; i++)
	{
		if (garArr[i] != 0)
		{
			std::cout << "\n" << i + 1 << ". " << garArr[i]->vehicleInfo() << "\n";
		}
		else if (garArr[i] == 0)
		{
			std::cout << "\n" << i + 1 << ".\t EMPTY";
		}
		else
		{
			std::cout << "n\nUFO!!!!\n\n";
		}
	}
}

void Garage::printType() const
{
	int cars{};
	int bicycles{};

	if (!isEmpty())
	{
		for (int i = 0; i < garSize; i++)
		{
			if (garArr[i] != 0)
			{
				if (garArr[i]->getType() == "Car")
				{
					cars++;
				}
				if (garArr[i]->getType() == "Bicycle")
				{
					bicycles++;
				}
			}
		}
		if (cars != 0)
		{
			std::cout << "\nNumber of cars: " << cars;
		}
		if (bicycles != 0)
		{
			std::cout << "\nNumber of bicycles: " << bicycles;
		}
	}
	else
	{
		std::cout << "\nGarage is empty\n";
	}
}

bool Garage::isEmpty()const
{
	for (int i = 0; i < garSize; i++)
	{
		if (garArr[i] != 0)
		{
			return false;
		}
	}
}