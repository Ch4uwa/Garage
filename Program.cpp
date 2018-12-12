#include "Program.h"



Program::Program()
	:choice(0), garName(""), garSize(0), active(true)
{
	LOG("Program ctor called");

}

int Program::input()
{
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

void Program::init()
{
	std::cout << "Enter garage name: ";
	getline(std::cin, garName);
	std::cout << "Enter garage size: ";
	garSize = input();
	gar = new Garage(garName, garSize);
	startMenu();
}

void Program::startMenu()
{
	do
	{
		std::cout << "\n" << this->garName
			<< "\n-------- Main Menu --------"
			<< "\n1. Add"
			<< "\n2. Search"
			<< "\n3. Print all"
			<< "\n4. Print types"
			<< "\n0. EXIT";

		switch (input())
		{
		default:
			break;
		case 1:
			if (!(gar->getIsFull()))
			{
				addMenu();
			}
			else
			{
				std::cout << "\nGarage is full.\n";
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
		case 0:
			LOG("Exit program");
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
		std::cout << "\n" << this->garName
			<< "\n-------- Add Menu --------"
			<< "\n1. Car"
			<< "\n2. Bicycle"
			<< "\n3. "
			<< "\n4. "
			<< "\n0. Back";
		switch (input())
		{
		default:
			break;
		case 1:
			gar->freeSlot(1);
			break;
		case 2:
			gar->freeSlot(2);
			break;
		case 3:
			//gar->freeSlot(3);
			break;
		case 4:
			//gar->freeSlot(4);
			break;
		case 0:
			active = false;
			break;
		}
		std::cout << "\nAdd More?\n";
	}
}

void Program::searchMenu()
{
	string regNr, make, color, type;
	int nrWheel{ 0 };

	active = true;
	while (active)
	{
		std::cout << "\n" << this->garName
			<< "\n-------- Search --------"
			<< "\n1. Registration number"
			<< "\n2. Color"
			<< "\n3. Type"
			<< "\n4. Number of wheels"
			<< "\n5. Make"
			<< "\n6. Print all vehicles in garage"
			<< "\n0. Back";
		switch (input())
		{
		default:
			std::cout << "\nFaulty input value.\n";
			break;
		case 1:
			std::cin.ignore(256, '\n');
			std::cout << "Enter registration number to search: ";
			getline(std::cin, regNr);
			gar->searchRegNr(regNr);
			break;
		case 2:
			std::cin.ignore(256, '\n');
			std::cout << "Enter color to search: ";
			getline(std::cin, color);
			gar->searchColor(color);
			break;
		case 3:
			std::cin.ignore(256, '\n');
			std::cout << "Enter type to search: ";
			getline(std::cin, type);
			gar->searchType(type);
			break;
		case 4:
			std::cin.ignore(256, '\n');
			std::cout << "Enter number of wheels to search: ";
			nrWheel = input();
			gar->searchNrWheel(nrWheel);
			break;
		case 5:
			std::cin.ignore(256, '\n');
			std::cout << "Enter make to search: ";
			getline(std::cin, make);
			gar->searchName(make);

			break;
		case 6:
			gar->printAll();
			break;
		case 0:
			LOG("Back");
			active = false;
			break;
		}
	}
}

void Program::eraseMenu()
{
	std::cout << "\n" << this->garName
		<< "\n-------- Remove --------"
		<< "\n1. "
		<< "\n2. "
		<< "\n3. "
		<< "\n4. "
		<< "\n0. Back";

	switch (input())
	{
	default:
		break;
	case 0:
		LOG("Back");
		break;
	}
}