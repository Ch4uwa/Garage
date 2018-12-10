#include "Program.h"



Program::Program()
	:choice(0), garName(""), garSize(0)
{
	LOG("Program ctor called");
	
}


void Program::init()
{

	std::cout << "Enter garage name: ";
	getline(std::cin, garName);
	std::cout << "Enter garage size: ";
	std::cin >> garSize; // TODO Exception handling
	startMenu();
}



int Program::input()
{
	std::cout << "\n--> ";
	while (!(std::cin >> choice))
	{
		std::cin.clear();
		std::cin.ignore('\n');
	}
	return choice;
}

void Program::startMenu()
{
	std::cout << this->garName
		<< "\n-------- Main Menu --------"
		<< "\n1. Look for parking space"
		<< "\n2. Search for a Vehicle"
		<< "\n3. "
		<< "\n4. "
		<< "\n0. EXIT";

	switch (input())
	{
	default:
		break;
	case 1:
		addMenu();
		break;
	case 2:
		searchMenu();
		break;
	case 0:
		LOG("Exit program");
		break;
	}
}

void Program::addMenu()
{
	std::cout << this->garName
		<< "\n-------- Add Menu --------"
		<< "\n1. Car"
		<< "\n2. Bicycle"
		<< "\n3. "
		<< "\n4. "
		<< "\n0. EXIT";

	switch (input())
	{
	default:
		break;
	case 1:
		
		break;
	case 2:
		break;
	case 0:
		LOG("Exit program");
		startMenu();
		break;
	}
}

void Program::searchMenu()
{
	std::cout << this->garName
		<< "\n-------- Search --------"
		<< "\n1. Registration number"
		<< "\n2. Color"
		<< "\n3. Type"
		<< "\n4. Number of wheels"
		<< "\n5. Print all vehicles in garage"
		<< "\n0. Back";

	switch (input())
	{
	default:
		break;
	case 0:
		LOG("Back");
		startMenu();
		break;
	}
}

void Program::eraseMenu()
{
	std::cout << this->garName
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



Program::~Program()
{
	LOG("Program dtor called");
	
}
