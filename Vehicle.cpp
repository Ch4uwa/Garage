#include "Vehicle.h"


Vehicle::Vehicle(string regNr, string color, int nrWheel)
	:regNr(regNr), color(color), nrWheel(nrWheel)
{
	LOG("Vehicle ctor");
}

Vehicle::~Vehicle()
{
	LOG("Vehicle dtor");
}




/************* CAR *************/

Car::Car(string regNr, string color, int nrWheel,
	string carModel, string carMake)
	:Vehicle(regNr, color, nrWheel),
	carModel(carModel), carMake(carMake)
{
	LOG("Car ctor called");
}


string Car::vehicleInfo()
{
	std::stringstream ss;
	ss << "\n--> " << getType() << " Info <--"
		<< "\nRegistration number: " << getRegNr()
		<< "\nMake: " << getVspec1()
		<< "\nModel: " << getVspec2()
		<< "\nColor: " << getColor()
		<< "\nNumber of wheels: " << getNrWheel()
		<< "\n";

	return ss.str();
}





Car::~Car()
{
	LOG("Car dtor called");
}
