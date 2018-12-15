#ifndef PROGRAM_H
#define PROGRAM_H
#include "pch.h"
#include "Garage.h"

class Program
{
private:
	int garSize;
	size_t activeGar;
	string garName;
	const enum VEHICLES { QUIT = 0, CAR = 1, BIKE, MC, BUS, EXCAVATOR };
	bool active, quit;
	std::vector<std::shared_ptr<Garage>>garage;
public:
	/* Constructor */
	Program();
	/* Destructor */
	~Program()
	{
		LOG("Program dtor called");
	};

	// Methods
	void init();
	void startMenu();
	void addMenu();
	void searchMenu();
	void eraseMenu();
	void manageGarage();
	void removeGarage();
	void switchGarage();
	static int input();
	// Getter
	inline string getGarName()const { return this->garName; }
	inline int getGarSize()const { return this->garSize; }


	// Mutator

};

#endif // !PROGRAM_H