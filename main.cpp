#include "pch.h"
#include "Vehicle.h"





int main()
{
	Vehicle* car = new Car("abc123","blue",4,"v40","volvo");
	std::cout << car->vehicleInfo();
	
	delete car;

	getchar();
}