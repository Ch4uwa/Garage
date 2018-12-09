#include "pch.h"
#include "Vehicle.h"





int main()
{
	Vehicle* car = new Car("abc123","blue",4,"v40","volvo");
	std::cout << car->vehicleInfo();

	Vehicle* bike = new Bicycle("SPD666", "Hot Pink", 2, "Yes", "Yes");
	std::cout << bike->vehicleInfo();
	
	delete car;
	delete bike;

	getchar();
}