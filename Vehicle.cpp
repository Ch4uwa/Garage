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




				/* CAR */

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
	ss << "\n--> Info <--"
		<< "\nregistration number: " << this->regNr
		<< "\nMake: " << this->carMake
		<< "\nModel: " << this->carModel
		<< "\nColor: " << this->color
		<< "\nNumber of wheels: " << this->nrWheel
		<< "\n";

	return ss.str();
}



Car::~Car()
{
	LOG("Car dtor called");
}
