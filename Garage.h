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
	Garage(string garName, int garSize);


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
	//void garInit(string, int);
	string StringToUpper(string);
	void freeSlot(int);
	void add(int);
	void remove(int);
	void searchRegNr();
	void searchString();
	void searchNrWheel();
	void clear();
	void printAll();
	void printParked();
	void printType()const;
	bool isEmpty()const;
	bool isFull()const;
	/* Accessor */
	const string getPamt();
	inline const string getGarName()const { return this->garName; }

};

#endif // !GARAGE_H

