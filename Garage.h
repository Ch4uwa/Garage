#ifndef GARAGE_H
#define GARAGE_H
#include "pch.h"
#include "Vehicle.h"


class Garage
{
private:
	int garSize;
	string garName;
	bool isFull;
	std::vector<Vehicle *> vehicle;
public:
	Garage(string garName = "112", int garSize = 1);
	~Garage();

	/* TODO Search, Print all functions, print types,
	add vehicle, remove vehicle*/

	// Methods
	void add(){ Vehicle* car = new Car("abc123", "blue", 4, 1, 1); }

};

#endif // !GARAGE_H

