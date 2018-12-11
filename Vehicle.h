#ifndef VEHICLE_H
#define VEHICLE_H
#include "pch.h"


class Vehicle
{
protected:
	string name, regNr, color;
	int nrWheel;

public:
	Vehicle(string name, string regNr, string color, int nrWheel);
	virtual ~Vehicle();

	// Virtuals
	virtual string vehicleInfo();

	// Virtual getters
	virtual string getName()const = 0;
	virtual string getRegNr()const = 0;
	virtual string getColor()const = 0;
	virtual string getType()const = 0;
	virtual int getNrWheel()const = 0;
	virtual string getVspec1()const = 0;
	virtual string getVspec2()const = 0;


};



/************* CAR *************/
class Car : public Vehicle
{
private:
	bool isNav, isWash;
	const string type{ "Car" };

public:
	Car(string name, string regNr, string color, int nrWheel,
		bool nav, bool wash);
	~Car();


	// Accessors
	string getVspec1()const override
	{
		return this->isWash ? "Cleaning ordered" : "No cleaning";
	}
	string getVspec2()const override
	{
		return this->isNav ? "Have GPS" : "No GPS";
	}
	virtual string getName()const override { return this->name; };
	inline string getRegNr()const override { return this->regNr; };
	inline string getType()const override { return this->type; };
	inline string getColor()const override { return this->color; };
	inline int getNrWheel()const override { return this->nrWheel; };

	// Modifyer

};


class Bicycle :public Vehicle
{
private:
	string jetEngine;
	string rollCage;
	const string type{ "Bicycle" };
public:
	Bicycle(string name, string regNr, string color, int nrWheel,
		string jetEngine, string rollCage);
	~Bicycle();

	// Accessors
	string getVspec1()const override { return this->jetEngine; };
	string getVspec2()const override { return this->rollCage; };
	virtual string getName()const override { return this->name; };
	inline string getRegNr()const override { return this->regNr; };
	inline string getType()const override { return this->type; };
	inline string getColor()const override { return this->color; };
	inline int getNrWheel()const override { return this->nrWheel; };

	// Modifyer

};


#endif // !VEHICLE_H