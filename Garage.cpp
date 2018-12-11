#include "Garage.h"


Garage::Garage(string garName, int garSize)
	:garName(garName), garSize(garSize), pSlot(0)
{
	this->garArr = new Vehicle*[garSize];

	LOG("Garage ctor");
}

void Garage::newGarage()
{
}

void Garage::add()
{
	garArr[pSlot] = new Car("Beemer","AAA111","b",4,1,1);
}

void Garage::printAll()
{
	for (int i = 0; i < this->garSize; i++)
	{
		std::cout << garArr[i]->vehicleInfo();
	}
}

