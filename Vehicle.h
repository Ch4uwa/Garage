#ifndef VEHICLE_H
#define VEHICLE_H
#include "pch.h"


class Vehicle
{
protected:
	string regNr;
	string color;
	int nrWheel;

public:
	Vehicle(string regNr, string color, int nrWheel);
	virtual ~Vehicle();

	// Virtuals
	virtual string vehicleInfo() = 0;
	
	
};



/************* CAR *************/
class Car : public Vehicle
{
private:
	string carModel;
	string carMake;

public:
	Car(string regNr, string color, int nrWheel, string carModel, string carMake);
	~Car();

	string vehicleInfo()override;

};



#endif // !VEHICLE_H
