#include "Garage.h"


Garage::Garage(string garName, int garSize)
	:garName(garName), garSize(garSize)
{
	LOG("Garage ctor");
}

Garage::~Garage()
{
	LOG("Garage dtor");
}
