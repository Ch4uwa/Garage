#include "Vehicle.h"


Vehicle::Vehicle(string regNr, string color, int nrWheel)
	:regNr(regNr), color(color), nrWheel(nrWheel), type("")
{
	LOG("Vehicle ctor");
}

string Vehicle::vehicleInfo()
{
	std::stringstream ss;
	ss << "\n--> " << getType() << " Info <--"
		<< "\nRegistration number: " << getRegNr()
		<< "\n" << getVspec1()
		<< "\n" << getVspec2()
		<< "\nColor: " << getColor()
		<< "\nNumber of wheels: " << getNrWheel()
		<< "\n";

	return ss.str();
}

Vehicle::~Vehicle()
{
	LOG("Vehicle dtor");
}




/************* CAR *************/

Car::Car(string regNr, string color, int nrWheel,
	bool nav, bool wash)
	:Vehicle(regNr, color, nrWheel),
	isNav(nav), isWash(wash)
{
	LOG("Car ctor called");
}


Car::~Car()
{
	LOG("Car dtor called");
}



/************* Bicycle *************/

Bicycle::Bicycle(string regNr, string color,
	int nrWheel, string jetEngine, string rollCage)
	:Vehicle(regNr, color, nrWheel),
	jetEngine(jetEngine), rollCage(rollCage)
{
	LOG("Bicycle ctor called");
}

Bicycle::~Bicycle()
{
	LOG("Bicycle dtor called");
}
