#pragma once
#ifndef FARMMODEL_SHEEP_H
#define FARMMODEL_SHEEP_H

#include "AbstractAnimal.h"
#include <iostream>

using namespace std;

/*
Definition for the class Sheep
*/

class Sheep :public AbstractAnimal {

public:

	Sheep(void) :AbstractAnimal() {}

	/*
	The sheep's specific collect procedure
	 */

	void collect() {

		shear();

	}

private:

	void shear(void) {

		cout << "The sheep are sheared." << endl;

	}
};

#endif