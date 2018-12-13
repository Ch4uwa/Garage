#include "Program.h"



Program::Program(string garName, int garSize)
	:garName(garName), garSize(garSize), active(true), quit(false)
{
	LOG("Program ctor");

}

/*-------- int input handler --------*/
int Program::input()
{
	int choice{};
	std::cout << "\n--> ";
	while (!(std::cin >> choice) || choice < 0)
	{
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cerr << "<ERROR>\nEnter positiv numeric value.";
		std::cout << "\n--> ";
	}
	return choice;
}

/*-------- Initialize --------*/
void Program::init()
{
	std::cout << "Enter garage name:\n-->";
	getline(std::cin, garName);
	std::cout << "Enter garage size:";
	garSize = input();
	gar = new Garage(garName, garSize);
	startMenu();
}

void Program::startMenu()
{
	do
	{
		std::cout << "\n<" << this->garName << ">" << gar->getPamt()
			<< "\n-------- Main Menu --------"
			<< "\n1. Add"
			<< "\n2. Search"
			<< "\n3. Print all"
			<< "\n4. Print types"
			<< "\n5. Remove"
			<< "\n0. EXIT";

		switch (input())
		{
		default:
			std::cout << "\nFaulty input value.\n";
			break;
		case 1:
			if (gar->isFull())
			{
				std::cout << "\nGarage is full.\n";
			}
			else
			{
				addMenu();
			}
			break;
		case 2:
			if (gar->isEmpty())
			{
				std::cout << "Garage is empty";
			}
			else
			{
				searchMenu();
			}
			break;
		case 3:
			gar->printAll();
			break;
		case 4:
			gar->printType();
			break;
		case 5:
			if (gar->isEmpty())
			{
				std::cout << "Garage is empty";
			}
			else
			{
				eraseMenu();
			}
			break;
		case 0:
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
		std::cout << "\n<" << this->garName << ">" << gar->getPamt()
			<< "\n-------- Add Menu --------"
			<< "\n1. Car"
			<< "\n2. Bicycle"
			<< "\n3. Motorcycle"
			<< "\n4. Bus"
			<< "\n5. Truck"
			<< "\n0. Back";
		switch (input())
		{
		default:
			std::cout << "\nFaulty input value.\n";
			break;
		case CAR: // Car
			gar->freeSlot(CAR);
			break;
		case BIKE: // Bicycle
			gar->freeSlot(BIKE);
			break;
		case MC: // MC
			//gar->freeSlot(3);
			break;
		case BUS: // Bus
			//gar->freeSlot(4);
			break;
		case TRUCK: // Truck
			//gar->freeSlot(5);
			break;
		case QUIT:
			active = false;
			break;
		}
		std::cout << "\nAdd More?\n";
	}
}

void Program::searchMenu()
{

	active = true;
	while (active)
	{
		std::cout << "\n<" << this->garName << ">" << gar->getPamt()
			<< "\n-------- Search --------"
			<< "\n1. Registration number"
			<< "\n2. Make, Color or type"
			<< "\n3. Number of wheels"
			<< "\n4. Print all vehicles in garage"
			<< "\n0. Back";
		switch (input())
		{
		default:
			std::cout << "\nFaulty input value.\n";
			break;
		case 1:
			gar->searchRegNr();
			break;
		case 2:
			gar->searchString();
			break;
		case 3:
			gar->searchNrWheel();
			break;
		case 4:
			gar->printAll();
			break;
		case 0:
			active = false;
			break;
		}
	}
}

void Program::eraseMenu()
{
	active = true;
	while (active)
	{
		std::cout << "\n<" << this->garName << ">" << gar->getPamt()
			<< "\n-------- Remove --------"
			<< "\n1. Remove all"
			<< "\n2. SEEK AND DESTOY"
			<< "\n0. Back";

		switch (input())
		{
		default:
			std::cout << "\nFaulty input value.\n";
			break;
		case 1:
			gar->clear();
			break;
		case 2:
			gar->searchRegNr();
			break;
		case 0:
			active = false;
			break;
		}
	}
}