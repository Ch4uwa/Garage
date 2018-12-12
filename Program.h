#ifndef PROGRAM_H
#define PROGRAM_H
#include "pch.h"
#include "Garage.h"


class Program
{
private:
	int choice;
	int garSize;
	string garName;
	bool active;
	bool quit;
	Garage *gar;
public:
	Program();
	~Program()
	{
		delete gar;
		LOG("Program dtor called");
	};

	// Methods
	void init();
	int input();
	void startMenu();
	void addMenu();
	void searchMenu();
	void eraseMenu();

	// Getter
	inline string getGarName() { return this->garName; }
	inline int getGarSize() { return this->garSize; }

	// Mutator

};

#endif // !PROGRAM_H