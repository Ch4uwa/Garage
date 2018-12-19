#include "Program.h"



Program::Program()
	:garName("NONAME"), garSize(0), activeGar(0), active(true), quit(false)
{
	LOG("Program ctor");
}

/*-------- int input handler --------*/
int Program::input()
{
	int choice{};
	LOG(choice);
	std::cout << "\n--> ";
	while (!(std::cin >> choice) || choice < 0)
	{
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cerr << "<ERROR> Enter positiv numeric value.";
		std::cout << "\n--> ";
	}
	return choice;
}

/*-------- Initialize --------*/
void Program::init()
{
	std::cout << "Enter garage name:\n--> ";
	getline(std::cin, this->garName);
	std::cout << "Enter garage size:";
	this->garSize = input();

	garage.emplace_back(new Garage(garName, garSize));
	this->activeGar = garage.size() - 1;
	startMenu();
}

void Program::startMenu()
{
	do
	{
		std::cout << "\n-------- Main Menu --------"
			<< "\n<" << garage[activeGar]->getGarName() << ">" << garage[activeGar]->getPamt()
			<< "\n1. Add Vehicle"
			<< "\n2. Search Vehicle"
			<< "\n3. Print all"
			<< "\n4. Print parked Vehicles"
			<< "\n5. Print all types of vehicles"
			<< "\n6. Remove Vehicle"
			<< "\n7. Manage Garage"
			<< "\n0. EXIT";

		switch (input())
		{
		default:
			std::cout << "\nFaulty input value.\n";
			break;
		case 1:
			if (garage[activeGar]->isFull())
			{
				std::cout << "\nGarage is full.\n";
			}
			else
			{
				addMenu();
			}
			break;
		case 2:
			if (garage[activeGar]->isEmpty())
			{
				std::cout << "Garage is empty";
			}
			else
			{
				searchMenu();
			}
			break;
		case 3:
			garage[activeGar]->printAll();
			break;
		case 4:
			if (!(garage[activeGar]->isEmpty()))
			{
				garage[activeGar]->printParked();
			}
			else
			{
				std::cout << "Garage is empty";
			}
			break;
		case 5:
			garage[activeGar]->printType();
			break;
		case 6:
			if (garage[activeGar]->isEmpty())
			{
				std::cout << "Garage is empty";
			}
			else
			{
				eraseMenu();
			}
			break;
		case 7:
			std::cin.ignore();
			manageGarage();
			break;
		case 0:
			std::cin.ignore();
			quit = true;
			break;
		}
	} while (!quit);
}

void Program::addMenu()
{
	active = true;
	while (active)
	{
		if (!(garage[activeGar]->isFull()))
		{
			std::cout << "\n-------- Add Menu --------"
				<< "\n<" << garage[activeGar]->getGarName() << ">" << garage[activeGar]->getPamt()
				<< "\n1. Car"
				<< "\n2. Bicycle"
				<< "\n3. Motorcycle"
				<< "\n4. Bus"
				<< "\n5. Excavator"
				<< "\n0. Back";
			switch (input())
			{
			default:
				std::cout << "\nFaulty input value.\n";
				break;
			case CAR: // Car
				garage[activeGar]->freeSlot(CAR);
				break;
			case BIKE: // Bicycle
				garage[activeGar]->freeSlot(BIKE);
				break;
			case MC: // MC
				garage[activeGar]->freeSlot(MC);
				break;
			case BUS: // Bus
				garage[activeGar]->freeSlot(BUS);
				break;
			case EXCAVATOR: // Excavator
				garage[activeGar]->freeSlot(EXCAVATOR);
				break;
			case QUIT:
				active = false;
				break;
			}
			std::cout << "\nAdd More?\n";
		}
		{
			active = false;
		}
	}
}

void Program::searchMenu()
{
	active = true;
	while (active)
	{
		if (!(garage[activeGar]->isEmpty()))
		{

			std::cout << "\n-------- Search Menu --------"
				<< "\n<" << garage[activeGar]->getGarName() << ">" << garage[activeGar]->getPamt()
				<< "\n1. Registration number"
				<< "\n2. Make, Color or type"
				<< "\n3. Number of wheels"
				<< "\n4. Print parked"
				<< "\n0. Back";
			switch (input())
			{
			default:
				std::cout << "\nFaulty input value.\n";
				break;
			case 1:
				garage[activeGar]->searchRegNr();
				break;
			case 2:
				garage[activeGar]->searchString();
				break;
			case 3:
				garage[activeGar]->searchNrWheel();
				break;
			case 4:
				if (!(garage[activeGar]->isEmpty()))
				{
					garage[activeGar]->printParked();
				}
				else
				{
					std::cout << "Garage is empty";
				}
				break;
			case 0:
				active = false;
				break;
			}
		}
		else
		{
			active = false;
		}
	}
}

void Program::eraseMenu()
{
	active = true;
	while (active)
	{
		if (!(garage[activeGar]->isEmpty()))
		{
			std::cout << "\n-------- Remove Menu --------"
				<< "\n<" << garage[activeGar]->getGarName() << ">" << garage[activeGar]->getPamt()
				<< "\n1. Remove all"
				<< "\n2. SEEK AND DESTOY"
				<< "\n3. Print parked"
				<< "\n0. Back";

			switch (input())
			{
			default:
				std::cout << "\nFaulty input value.\n";
				break;
			case 1:
				garage[activeGar]->clear();
				break;
			case 2:
				garage[activeGar]->searchRegNr();
				break;
			case 3:
				if (!(garage[activeGar]->isEmpty()))
				{
					garage[activeGar]->printParked();
				}
				else
				{
					std::cout << "Garage is empty";
				}
				break;
			case 0:
				active = false;
				break;
			}
		}
		else
		{
			active = false;
		}
	}
}

void Program::manageGarage()
{
	active = true;
	while (active)
	{
		std::cout << "\nWhat to do?"
			<< "\n1. New Garage"
			<< "\n2. Remove Garage"
			<< "\n3. Switch Garage"
			<< "\n0. Back";
		switch (input())
		{
		default:
			std::cout << "\nNot a valid input!";
			break;
		case 1:
			std::cin.ignore();
			init();
			break;
		case 2:
			std::cin.ignore();
			if (!(garage.empty()))
			{
				removeGarage();
			}
			else
			{
				std::cout << "\nThere's nothing here to remove.";
				active = false;
			}
			break;
		case 3:
			std::cin.ignore();
			if (garage.size() > 1)
			{
				switchGarage();
			}
			else
			{
				std::cout << "\nThere is really nothing to switch to\nMaybe go create a new Garage?";
			}
			break;
		case 0:
			active = false;
			break;
		}
	}
}

void Program::removeGarage()
{
	int it{ 1 };
	for (auto n : garage)
	{
		if (n != NULL)
		{
			std::cout << "\n" << it << ". " << n->getGarName();
			it++;
		}
	}
	std::cout << "\nEnter Garage to remove\n";

	it = input() - 1;
	if (it == this->activeGar)
	{
		std::cout << "\nDon't delete the garage you are standing in!.";
	}
	else if (!(it == this->activeGar))
	{
		if (!(it >= garage.size()))
		{
			std::cout << "\nGarage " << garage[it]->getGarName() << " Has been removed\n";
			garage.erase(garage.begin() + it);
			if (garage.empty())
			{
				std::cin.ignore();
				init();
			}
		}
	}
	else if (it >= garage.size())
	{
		std::cout << "\nHEY Play nice!";
	}

	if (!(this->activeGar < garage.size()))
	{
		switchGarage();
	}
}

void Program::switchGarage()
{
	int it{ 1 };
	for (auto n : garage)
	{
		if (n != NULL)
		{
			std::cout << "\n" << it << ". " << n->getGarName();
			it++;
		}
	}

	std::cout << "\nChoose Garage\n";

	it = input() - 1;
	if (it < garage.size())
	{
		this->activeGar = it;
		std::cout << "\nGarage " << garage[this->activeGar]->getGarName() << " Is the chosen one!\n";
	}
	else if (it >= garage.size())
	{
		std::cout << "\nHEY Play nice!";
	}
}