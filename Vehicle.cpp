#include "Vehicle.h"


Vehicle::Vehicle(string regNr, string color, int nrWheel)
	:regNr(regNr), color(color), nrWheel(nrWheel), type("")
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


string Vehicle::vehicleInfo()
{
	std::stringstream ss;
	ss << "\n--> " << getType() << " Info <--"
		<< "\nRegistration number: " << getRegNr()
		<< "\nSpecial: " << getVspec1()
		<< "\nSpecial: " << getVspec2()
		<< "\nColor: " << getColor()
		<< "\nNumber of wheels: " << getNrWheel()
		<< "\n";

	return ss.str();
}





Car::~Car()
{
	LOG("Car dtor called");
}



/************* Bicycle *************/

Bicycle::Bicycle(string regNr, string color, int nrWheel, string JetEngine, string RollCage)
	:Vehicle(regNr, color, nrWheel),
	JetEngine(JetEngine), RollCage(RollCage)
{
	LOG("Bicycle ctor called");
}

Bicycle::~Bicycle()
{
	LOG("Bicycle dtor called");
}
