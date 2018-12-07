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
	Garage garage(garName, garSize);
	startMenu();
}

int Program::input() const
{
	std::cout << "\n--> ";
	while (!(std::cin, choice))
	{
		std::cin.clear();
		std::cin.ignore();
	}
	return choice;
}

void Program::startMenu()
{
	std::cout << this->garName
		<< "----------------------"
		<< "\n1. Look for space"
		<< "\n2. "
		<< "\n3. "
		<< "\n4. "
		<< "\n0. EXIT";

	switch (input())
	{
	default:
		break;
	case 0:
		LOG("Exit program");
		break;
	}
}

void Program::addMenu()
{
	std::cout << this->garName
		<< "----------------------"
		<< "\n1. Look for space"
		<< "\n2. "
		<< "\n3. "
		<< "\n4. "
		<< "\n0. EXIT";

	switch (input())
	{
	default:
		break;
	case 0:
		LOG("Exit program");
		break;
	}
}

void Program::searchMenu()
{
	std::cout << this->garName
		<< "----- Search ------"
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

void Program::eraseMenu()
{
	std::cout << this->garName
		<< "------ Collect -------"
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
