#include "pch.h"
#include "Program.h"
#include"Garage.h"





int main()
{
	Garage gar("a", 5);
	
	gar.add();
	gar.printAll();
	/*
	Vehicle *pV = new Car("vulvo", "qwe123", "q", 2, 1, 0);
	std::cout<< pV->vehicleInfo();*/

	//Program program;
	//program.init();
	/*Vehicle* car = new Car("abc123","blue",4,1,1);
	std::cout << car->vehicleInfo();

	Vehicle* bike = new Bicycle("SPD666", "Hot Pink", 2, "2", "2");
	std::cout << bike->vehicleInfo();

	delete car;
	delete bike;*/
	getchar();
}