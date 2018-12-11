#ifndef GARAGE_H
#define GARAGE_H
#include "pch.h"
#include "Vehicle.h"


class Garage
{
private:
	int garSize, pSlot;
	string garName;
	bool isFull;

	Vehicle **garArr;
public:
	/*Constuctor*/
	Garage(string garName = "hej", int garSize = 10);

	/*Destructor*/
	~Garage()
	{
		LOG("Garage dtor");
		
		/*for (int i = 0; i < garSize; i++)
		{
			delete garArr[i];
		}
		delete[] garArr;*/
	}


	/* TODO Search, Print all functions, print types,
	add vehicle, remove vehicle*/

	// Methods
	void newGarage();
	void add();
	void remove() {}
	void search() {}
	void clear() {}
	void printAll();
	void printType()const {}
	const int &getPslot()const { return this->pSlot; }

};

#endif // !GARAGE_H

