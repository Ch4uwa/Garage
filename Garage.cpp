#include "Garage.h"
#include "Program.h"


Garage::Garage(string garName, int garSize)
	:garName(garName), garSize(garSize), pSlot(0), result(true)
{
	this->garArr = new Vehicle*[garSize];
	for (int i{}; i < garSize; i++)
	{
		this->garArr[i] = 0;
	}
	LOG("Garage ctor");
}

//void Garage::garInit(string garName, int garSize)
//{
//	this->garArr = new Vehicle*[garSize];
//	for (int i{}; i < garSize; i++)
//	{
//		this->garArr[i] = 0;
//	}
//}

/*-------- Looks for a free P-Spot, to add too --------*/
void Garage::freeSlot(int input)
{
	pSlot = 0;
	while (garArr[pSlot] != 0 && pSlot < garSize)
	{
		if (garArr[pSlot] != 0)
		{
			pSlot++;
		}
	}
	if (garArr[pSlot] == 0)
	{
		add(input);
	}
	else
	{
		std::cout << "\nIt's Full, can't park'em on top of eachother!";
	}
}

/*-------- Adds Vehicles --------*/
void Garage::add(int input)
{
	string name{ "" }, regNr{ "" }, color{ "" };
	int	nrWheel{ 0 }, special1{ 0 }, special2{ 0 };

	std::cin.ignore(256, '\n');
	std::cout << "Enter make: ";
	getline(std::cin, uInput);
	name = StringToUpper(uInput);
	std::cout << "Enter registration number: ";
	getline(std::cin, uInput);
	regNr = StringToUpper(uInput);
	std::cout << "Enter color: ";
	getline(std::cin, uInput);
	color = StringToUpper(uInput);

	switch (input)
	{
	default:
		break;
	case 1: // CAR
	{
		std::cout << "Enter number of wheels: ";
		nrWheel = Program::input();

		std::cout << "Do you have nav system?\n1. Yes\n0. No";
		if (Program::input() > 0) { special1 = 1; }
		else { special1 = 0; }

		std::cout << "Should we wash your car?\n1. Yes\n0. No";
		if (Program::input() > 0) { special2 = 1; }
		else { special2 = 0; }

		garArr[pSlot] = new Car(name, regNr, color, nrWheel, special1, special2);
		std::cout << "Your car is parked at P-Slot " << pSlot + 1;
		break;
	}
	case 2://BICYCLE
	{
		std::cout << "Enter number of wheels: ";
		nrWheel = Program::input();

		std::cout << "Do you have a jet engine?\n1. Yes\n0. No";
		if (Program::input() > 0) { special1 = 1; }
		else { special1 = 0; }

		std::cout << "Is there a rollcage?\n1. Yes\n0. No";
		if (Program::input() > 0) { special2 = 1; }
		else { special2 = 0; }

		garArr[pSlot] = new Bicycle(name, regNr, color, nrWheel, special1, special2);
		std::cout << "Your bicycle is parked at P-Slot: " << pSlot + 1;
		break;
	}
	case 3: // MC
	{
		std::cout << "Enter number of wheels: ";
		nrWheel = Program::input();

		std::cout << "Is your MC turbo charged?\n1. Yes\n0. No";
		if (Program::input() > 0) { special1 = 1; }
		else { special1 = 0; }

		std::cout << "What style does it have?\n1. Old School\n0. Super sport";
		if (Program::input() > 0) { special2 = 1; }
		else { special2 = 0; }

		garArr[pSlot] = new MC(name, regNr, color, nrWheel, special1, special2);
		std::cout << "Your MC is parked at P-Slot " << pSlot + 1;
		break;
	}
	case 4: // BUS
	{
		std::cout << "Enter number of wheels: ";
		nrWheel = Program::input();

		std::cout << "What kind of bus is it?\n1. Party bus\n0. Church bus";
		if (Program::input() > 0) { special1 = 1; }
		else { special1 = 0; }

		std::cout << "What gender?\n1. Male\n0. Female";
		if (Program::input() > 0) { special2 = 1; }
		else { special2 = 0; }

		garArr[pSlot] = new Bus(name, regNr, color, nrWheel, special1, special2);
		std::cout << "Your bus is parked at P-Slot " << pSlot + 1;
		break;
	}
	case 5: // EXCAVATOR
	{
		std::cout << "Does it have?\n1. Larvae\n0. Wheels";
		if (Program::input() > 0) { special1 = 1; }
		else { special1 = 0; }
		if (special1 == 0)
		{
			std::cout << "Enter number of wheels: ";
			nrWheel = Program::input();
		}
		else if (special1>0)
		{
			nrWheel = 24;
		}
		std::cout << "How much does it weigh?";
		special2 = Program::input();

		garArr[pSlot] = new Excavator(name, regNr, color, nrWheel, special1, special2);
		std::cout << "Your excavator is parked at P-Slot " << pSlot + 1;
		break;
	}
	}
}
/*-------- Remove specific vehicle --------*/
void Garage::remove(int pSlot)
{
	std::cout << "\n" << garArr[pSlot]->getRegNr() << " Has been removed from the garage.";
	delete garArr[pSlot];
	garArr[pSlot] = 0;
}
/*-------- Search methods --------*/
void Garage::searchRegNr()
{
	result = false;
	std::cin.ignore(256, '\n');
	std::cout << "Enter registration number to search: ";
	getline(std::cin, uInput);
	uInput = StringToUpper(uInput);

	for (int i = 0; i < garSize; i++)
	{
		if (garArr[i] != 0)
		{
			if (garArr[i]->getRegNr() == uInput)
			{
				pSlot = i;
				result = true;
				std::cout << "\nSearch result: At P-Space: " << pSlot + 1 << ".\n" << garArr[pSlot]->vehicleInfo()
					<< "\nDo you want to remove this vehicle from the garage?"
					<< "\n1. Yes\n0. No\n";

				if (Program::input() > 0) { remove(pSlot); }

			}
		}
	}
	if (!result)
	{
		std::cout << "\nThese are not the attributes you are looking for.";
	}
}
void Garage::searchString()
{
	result = false;
	std::cin.ignore(256, '\n');
	std::cout << "Enter make, color or type to search for: ";
	getline(std::cin, uInput);
	uInput = StringToUpper(uInput);

	for (int i = 0; i < garSize; i++)
	{
		if (garArr[i] != 0)
		{
			if (garArr[i]->getColor() == uInput || garArr[i]->getName() == uInput
				|| garArr[i]->getType() == uInput)
			{
				pSlot = i;
				result = true;
				std::cout << "\nSearch result: At P-Space: " << pSlot + 1 << ".\n" << garArr[pSlot]->vehicleInfo();
			}
		}
	}
	if (!result)
	{
		std::cout << "\nThese are not the attributes you are looking for.";
	}
}
void Garage::searchNrWheel()
{
	result = false;
	std::cin.ignore(256, '\n');
	std::cout << "Enter number of wheels to search for: ";
	int nrWheel = Program::input();

	for (int i = 0; i < garSize; i++)
	{
		if (garArr[i] != 0)
		{
			if (nrWheel == garArr[i]->getNrWheel())
			{
				pSlot = i;
				result = true;
				std::cout << "\nSearch result: At P-Space: " << pSlot + 1 << ".\n" << garArr[pSlot]->vehicleInfo();
			}
		}
	}
	if (!result)
	{
		std::cout << "\nThese are not the wheels you are looking for.";
	}
}

/*-------- Clears the garage --------*/
void Garage::clear()
{
	for (int i = 0; i < garSize; i++)
	{
		delete garArr[i];
		garArr[i] = 0;
	}
	std::cout << "\nGarage is now empty.";
}

/*-------- Prints all vehicles in garage --------*/
void Garage::printAll()
{
	for (int i = 0; i < this->garSize; i++)
	{
		if (garArr[i] != 0)
		{
			std::cout << "\n" << i + 1 << ".\n" << garArr[i]->vehicleInfo();
		}
		else if (garArr[i] == 0)
		{
			std::cout << "\n" << i + 1 << ".\t EMPTY\n";
		}
		else
		{
			std::cout << "n\nUFO!!!!\n\n";
		}
	}
}

/*-------- Prints all vehicles in garage --------*/
void Garage::printParked()
{
	for (int i = 0; i < this->garSize; i++)
	{
		if (garArr[i] != 0)
		{
			std::cout << "\n" << i + 1 << ".\n" << garArr[i]->vehicleInfo();
		}
	}
}

/*-------- Prints amount of types in garage --------*/
void Garage::printType() const
{
	int cars{0}, bicycles{0}, mc{0}, bus{0}, excavator{0};

	if (!isEmpty())
	{
		for (int i = 0; i < garSize; i++)
		{
			if (garArr[i] != 0)
			{
				if (garArr[i]->getType() == "CAR")
				{
					cars++;
				}
				else if (garArr[i]->getType() == "BICYCLE")
				{
					bicycles++;
				}
				else if (garArr[i]->getType() == "MOTORCYCEL")
				{
					mc++;
				}
				else if (garArr[i]->getType() == "BUS")
				{
					bus++;
				}
				else if (garArr[i]->getType() == "EXCAVATOR")
				{
					excavator++;
				}
			}
		}
		if (cars != 0)
		{
			std::cout << "\nNumber of Cars: " << cars;
		}
		if (bicycles != 0)
		{
			std::cout << "\nNumber of Bicycles: " << bicycles;
		}
		if (mc != 0)
		{
			std::cout << "\nNumber of MC's: " << mc;
		}
		if (bus != 0)
		{
			std::cout << "\nNumber of Busses: " << bus;
		}
		if (excavator != 0)
		{
			std::cout << "\nNumber of Excavators: " << excavator;
		}
		
	}
	else
	{
		std::cout << "\nGarage is empty\n";
	}
}

/*-------- Return true if garage is empty --------*/
bool Garage::isEmpty()const
{
	if (free == garSize)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*-------- Return true if garage is full --------*/
bool Garage::isFull()const
{
	if (free == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*-------- Prints number of free spots and parked cars. --------*/
const string Garage::getPamt()
{
	free = 0;
	taken = 0;

	for (int i{ 0 }; i < garSize; i++)
	{
		if (garArr[i] == 0)
		{
			free++;
		}
		else if (garArr[i] != 0)
		{
			taken++;
		}
	}
	return "\nFree space: " + std::to_string(free) + "/" + std::to_string(garSize) +
		"\nTotal Parked: " + std::to_string(taken) + "/" + std::to_string(garSize);
}

/*-------- Convertes string to uppercase --------*/
string Garage::StringToUpper(string strToConvert)
{
	std::transform(strToConvert.begin(), strToConvert.end(), strToConvert.begin(), ::toupper);

	return strToConvert;
}