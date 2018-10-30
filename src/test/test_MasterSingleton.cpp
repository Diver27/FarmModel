#include <iostream>
#include "../main/FarmMaster/Singleton.h"


int main()
{
	//new Singleton(); // Won't work
	Singleton* farmer = Singleton::getInstance(); // Ok
	Singleton* farmer1 = Singleton::getInstance();
	farmer->setName("peter");
	/* The addresses will be the same. */
	std::cout << farmer->getName() << std::endl;
	/* The addresses will be the same. */
	std::cout << farmer1->getName() << std::endl;
}