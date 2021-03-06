#ifndef VEHICLE_H
#define VEHICLE_H
#include "pch.h"


class Vehicle
{
protected:
	string name, regNr, color;
	int nrWheel;

public:
	/* Constructor */
	Vehicle(string name, string regNr, string color, int nrWheel);

	/* Virtual destructor, otherwise derived class destructor wont run.*/
	virtual ~Vehicle();

	// Virtual Method
	virtual string vehicleInfo();

	// Virtual accessors
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
	const string type{ "CAR" };

public:
	Car(string name, string regNr, string color, int nrWheel,
		int nav, int wash);
	~Car() { LOG("Car dtor called"); }



	// Accessors
	string getVspec1()const override
	{
		return this->isWash ? "Cleaning ordered" : "No cleaning";
	}
	string getVspec2()const override
	{
		return this->isNav ? "Have GPS" : "No GPS";
	}
	inline string getName()const override { return this->name; };
	inline string getRegNr()const override { return this->regNr; };
	inline string getType()const override { return this->type; };
	inline string getColor()const override { return this->color; };
	inline int getNrWheel()const override { return this->nrWheel; };

	// Modifyer

};

/************* Bicycle *************/
class Bicycle :public Vehicle
{
private:
	bool jetEngine, rollCage;
	const string type{ "BICYCLE" };
public:
	Bicycle(string name, string regNr, string color, int nrWheel,
		int jetEngine, int rollCage);
	~Bicycle() { LOG("Bicycle dtor called"); }

	// Accessors
	string getVspec1()const override
	{
		return this->jetEngine ? "Has Jet Engine" : "Pedals";
	}
	string getVspec2()const override
	{
		return this->rollCage ? "Good safety! Rollcage" : "Deathwish";
	}
	virtual string getName()const override { return this->name; };
	inline string getRegNr()const override { return this->regNr; };
	inline string getType()const override { return this->type; };
	inline string getColor()const override { return this->color; };
	inline int getNrWheel()const override { return this->nrWheel; };

	// Modifyer

};


/************* MC *************/
class MC :public Vehicle
{
private:
	bool turbo, style;
	const string type{ "MOTORCYCEL" };
public:
	MC(string name, string regNr, string color, int nrWheel,
		int turbo, int style);
	~MC() { LOG("MC dtor called"); }

	// Accessors
	string getVspec1()const override;
	string getVspec2()const override;
	virtual string getName()const override { return this->name; };
	inline string getRegNr()const override { return this->regNr; };
	inline string getType()const override { return this->type; };
	inline string getColor()const override { return this->color; };
	inline int getNrWheel()const override { return this->nrWheel; };

	// Modifyer

};


/************* Bus *************/
class Bus :public Vehicle
{
private:
	bool partyBus, soccerMom;
	const string type{ "BUS" };
public:
	Bus(string name, string regNr, string color, int nrWheel,
		int partyBus, int soccerMom);
	~Bus() { LOG("Bus dtor called"); }

	// Accessors
	string getVspec1()const override;
	string getVspec2()const override;
	
	virtual string getName()const override { return this->name; };
	inline string getRegNr()const override { return this->regNr; };
	inline string getType()const override { return this->type; };
	inline string getColor()const override { return this->color; };
	inline int getNrWheel()const override { return this->nrWheel; };

	// Modifyer

};


/************* Excavator *************/
class Excavator :public Vehicle
{
private:
	bool hasLarvae;
	int tons;
	const string type{ "EXCAVATOR" };
public:
	Excavator(string name, string regNr, string color, int nrWheel,
		int hasLarvae, int tons);
	~Excavator() { LOG("Excavator dtor called"); }

	// Accessors
	string getVspec1()const override;
	string getVspec2()const override;
	virtual string getName()const override { return this->name; };
	inline string getRegNr()const override { return this->regNr; };
	inline string getType()const override { return this->type; };
	inline string getColor()const override { return this->color; };
	inline int getNrWheel()const override { return this->nrWheel; };

	// Modifyer

};

#endif // !VEHICLE_H
