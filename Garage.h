#ifndef GARAGE_H
#define GARAGE_H
#include "pch.h"
#include "Vehicle.h"

class Garage
{
private:
	int garSize;
	string garName;
	std::vector<Vehicle *> vehicle;
public:
	Garage(string garName = "112", int garSize = 1);
	~Garage();

};

#endif // !GARAGE_H

