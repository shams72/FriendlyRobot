#include <iostream>
#include "Window.h"


int main(void)
{
	try
	{
		Window mg;
		mg.run();
	}
	catch(const std::exception& ex)
	{
		std::cout << ex.what() << "\nDruecke eine Taste zum beenden." << std::endl;
		std::getchar();
	}


	return 1;
}