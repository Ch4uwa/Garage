#include "pch.h"
#include "Program.h"





int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Program p;
	
	{
		p.init();
	}

	std::cin.ignore();
	getchar();
}