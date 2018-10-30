#pragma once
#include<string>

class Singleton
{
private:
	/* Here will be the instance stored. */
	static Singleton* instance;
	std::string farmer_name;

	/* Private constructor to prevent instancing. */
	Singleton();

public:
	/* Static access method. */
	static Singleton* getInstance();
	void setName(std::string a) { farmer_name = a; }
	std::string getName() { return farmer_name; }
};

/* Null, because instance will be initialized on demand. */
Singleton* Singleton::instance = 0;

Singleton* Singleton::getInstance()
{
	if (instance == 0)
	{
		instance = new Singleton();
	}

	return instance;
}

Singleton::Singleton()
{}