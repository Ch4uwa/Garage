#include "Vehicle.h"


Vehicle::Vehicle(string name, string regNr, string color, int nrWheel)
	:name(name), regNr(regNr), color(color), nrWheel(nrWheel)
{
	LOG("Vehicle ctor");
}

string Vehicle::vehicleInfo()
{
	std::stringstream ss;
	ss << "\n\t--> " << getType() << " Info <--"
		<< "\n\tRegistration number: " << getRegNr()
		<< "\n\tName: " << getName()
		<< "\n\tColor: " << getColor()
		<< "\n\tNumber of wheels: " << getNrWheel()
		<< "\n\t" << getVspec1()
		<< "\n\t" << getVspec2()
		<< "\n";

	return ss.str();
}

Vehicle::~Vehicle()
{
	LOG("Vehicle dtor");
}

/************* CAR *************/
Car::Car(string name, string regNr, string color, int nrWheel,
	int nav, int wash)
	:Vehicle(name, regNr, color, nrWheel),
	isNav(nav), isWash(wash)
{
	LOG("Car ctor called");
}

/************* Bicycle *************/
Bicycle::Bicycle(string name, string regNr, string color,
	int nrWheel, int jetEngine, int rollCage)
	:Vehicle(name, regNr, color, nrWheel),
	jetEngine(jetEngine), rollCage(rollCage)
{
	LOG("Bicycle ctor called");
}

/************* MC *************/
MC::MC(string name, string regNr, string color, int nrWheel, int turbo, int style)
	:Vehicle(name, regNr, color, nrWheel),
	turbo(turbo), style(style)
{
	LOG("MC ctor called");
}

string MC::getVspec1() const
{
	return this->turbo ? "Turbo!!" : "Slow poke";
}

string MC::getVspec2() const
{
	return this->style ? "Old School" : "Super Sport";
}

/************* Bus *************/
Bus::Bus(string name, string regNr, string color, int nrWheel, int partyBus, int soccerMom)
	:Vehicle(name, regNr, color, nrWheel),
	partyBus(partyBus), soccerMom(soccerMom)
{
	LOG("Bus ctor called");
}

string Bus::getVspec1() const
{
	return this->partyBus ? "Party Bus" : "Gangsta church bus";
}

string Bus::getVspec2() const
{
	return this->soccerMom ? "I'ma soccer'dad" : "Gangsta Mom";
}


/************* Excavator *************/
Excavator::Excavator(string name, string regNr, string color, 
	int nrWheel, int hasLarvae, int tons)
	:Vehicle(name, regNr, color, nrWheel),
	hasLarvae(hasLarvae), tons(tons)
{
	LOG("Excavator ctor called");
}

string Excavator::getVspec1() const
{
	return this->hasLarvae ? "Larvae equipped" : "Wheels";
}

string Excavator::getVspec2() const
{
	return std::to_string(this->tons) + " Tons.";
}
