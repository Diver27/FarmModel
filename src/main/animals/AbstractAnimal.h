#pragma once

#ifndef ANIMAL_H
#define ANIMAL_H

#include"Operation.h"
#include<iostream>

/*
Abstract class for all kinds of plants
 */
class AbstractAmimal
{
private:
	Operation* operation;
public:
	/*
	Select operation from Strategy and do it on the animals
	*/
	void operate(int opt) {
		switch (opt)
		{
		case 1:
			operation = new Lend();
			break;
		case 2:
			operation = new Slaughter();
			break;
		case 3:
			operation = new Sell();
			break;
		default:
			break;
		}
		operation->operation();
	}
};

#endif
