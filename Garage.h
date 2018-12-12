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


	/* TODO Search, Print all functions, print types,
	add vehicle, remove vehicle*/

	// Methods
	
	void freeSlot(int);
	void add(int);
	void remove() {}
	void search() {}
	void clear() {}
	bool isEmpty()const;
	void printAll();
	void printType()const;
	inline const int &getPslot()const { return this->pSlot; }
	inline const bool &getIsFull()const { return this->isFull; }


};

#endif // !GARAGE_H

