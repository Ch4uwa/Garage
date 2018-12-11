#include "Vehicle.h"


Vehicle::Vehicle(string name, string regNr, string color, int nrWheel)
	:name(name), regNr(regNr), color(color), nrWheel(nrWheel)
{
	LOG("Vehicle ctor");
}

string Vehicle::vehicleInfo()
{
	std::stringstream ss;
	ss << "\n--> " << getType() << " Info <--"
		<< "\nRegistration number: " << getRegNr()
		<< "\nName: " << getName()
		<< "\nColor: " << getColor()
		<< "\nNumber of wheels: " << getNrWheel()
		<< "\n" << getVspec1()
		<< "\n" << getVspec2()
		<< "\n";

	return ss.str();
}

Vehicle::~Vehicle()
{
	LOG("Vehicle dtor");
}




/************* CAR *************/

Car::Car(string name, string regNr, string color, int nrWheel,
	bool nav, bool wash)
	:Vehicle(name, regNr, color, nrWheel),
	isNav(nav), isWash(wash)
{
	LOG("Car ctor called");
}


Car::~Car()
{
	LOG("Car dtor called");
}



/************* Bicycle *************/

Bicycle::Bicycle(string name, string regNr, string color,
	int nrWheel, string jetEngine, string rollCage)
	:Vehicle(name, regNr, color, nrWheel),
	jetEngine(jetEngine), rollCage(rollCage)
{
	LOG("Bicycle ctor called");
}

Bicycle::~Bicycle()
{
	LOG("Bicycle dtor called");
}