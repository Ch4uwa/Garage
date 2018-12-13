#ifndef PROGRAM_H
#define PROGRAM_H
#include "pch.h"
#include "Garage.h"

class Program
{
private:
	int garSize;
	string garName;
	const enum VEHICLES { QUIT = 0, CAR = 1, BIKE, MC, BUS, TRUCK };
	bool active, quit;
	Garage *gar;
public:
	/* Constructor */
	Program(string garName = "NONAME", int garSize = 12);
	/* Destructor */
	~Program()
	{
		delete gar;
		LOG("Program dtor called");
	};

	// Methods
	void init();
	void startMenu();
	void addMenu();
	void searchMenu();
	void eraseMenu();

	int input();
	// Getter
	inline string getGarName()const { return this->garName; }
	inline int getGarSize()const { return this->garSize; }


	// Mutator

};

#endif // !PROGRAM_H