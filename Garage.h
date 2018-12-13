#ifndef GARAGE_H
#define GARAGE_H
#include "pch.h"
#include "Vehicle.h"

class Garage
{
private:
	int garSize, pSlot, free, taken;
	string garName, uInput;
	bool result;
	Vehicle **garArr;
public:
	/*Constuctor*/
	Garage(string garName = "SuperDuper", int garSize = 12);

	/*Destructor*/
	~Garage()
	{
		LOG("Garage dtor");
		for (int i = 0; i < garSize; i++)
		{
			delete garArr[i];
		}
		delete[] garArr;
	}

	// Methods
	string StringToUpper(string);
	void freeSlot(int);
	void add(int);
	void remove(int);
	void searchRegNr();
	void searchString();
	void searchNrWheel();
	void clear();
	void printAll();
	void printType()const;
	bool isEmpty()const;
	bool isFull()const;
	/* Accessor */
	const string getPamt();

};

#endif // !GARAGE_H

