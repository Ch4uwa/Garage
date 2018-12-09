#ifndef VEHICLE_H
#define VEHICLE_H
#include "pch.h"


class Vehicle
{
protected:
	string regNr;
	string color;
	string type;
	int nrWheel;

public:
	Vehicle(string regNr, string color, int nrWheel);
	virtual ~Vehicle();

	// Virtuals
	virtual string vehicleInfo() = 0;

	// Virtual getters
	virtual string getVspec1()const = 0;
	virtual string getVspec2()const = 0;
	virtual string getRegNr()const = 0;
	virtual string getType()const = 0;
	virtual string getColor()const = 0;
	virtual int getNrWheel()const = 0;

	// Mutator
	virtual void setType() = 0;

};



/************* CAR *************/
class Car : public Vehicle
{
private:
	string carModel;
	string carMake;

public:
	Car(string regNr, string color, int nrWheel,
		string carModel, string carMake);
	~Car();

	string vehicleInfo()override;

	// Getter
	string getVspec1()const override { return this->carMake; };
	string getVspec2()const override { return this->carModel; };
	string getRegNr()const override { return this->regNr; };
	string getType()const override { return this->type; };
	string getColor()const override { return this->color; };
	int getNrWheel()const override { return this->nrWheel; };

	// Mutator
	virtual void setType() { this->type = "Car"; };
};



#endif // !VEHICLE_H
