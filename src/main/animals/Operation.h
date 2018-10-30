#pragma once

#ifndef HARVEST_H
#define HARVEST_H

#include "AbstractAnimal.h"
#include<iostream>

using namespace std;

/*
Strategy template. Choose different opreater to do for an animal.
*/

class Operation
{
public :
	virtual void operation(void)=0;
	Operation(void) {}
};


/*
Feed the animals
*/
class Feed :public Operation
{
public:
	void operation(void)
	{
		cout << "The animals are fed";
	}
	Feed(void) {}
};

/*
Lend the animals to visitors
*/
class Lend :public Operation
{
public:
	void operation(void)
	{
		cout << "The animals are lent";
	}
	Lend(void) {}
};

/*
Slaughter the animals to get meat
*/
class Slaughter :public Operation
{
public:
	void operation(void)
	{
		cout << "The animals are slaughtered";
	}
	Slaughter(void) {}
};

/*
Sell the animals out
*/
class Sell :public Operation
{
public:
	void operation(void)
	{
		cout << "The animals are sold";
	}
	Sell(void) {}
};

#endif