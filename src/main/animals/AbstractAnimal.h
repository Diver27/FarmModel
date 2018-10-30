#pragma once

#ifndef ANIMAL_H
#define ANIMAL_H

#include"Operation.h"
#include<iostream>

/*
Abstract class for all kinds of plants
 */
class AbstractAnimal
{
private:
	Operation* operation;
public:
	AbstractAnimal(void): operation(NULL) {}

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

	/*
	 Harvest the animal
	 */
	void harvest(void) {
		cout << "Begin harvest process..." << endl;
		cout << "Assemble workers" << endl;
		collect();
		cout << "Harvest process finished" << endl;
	}

	/*
	Template method. Collect something from certain kind of animals.
	 */
	virtual void collect() = 0;
};

#endif
