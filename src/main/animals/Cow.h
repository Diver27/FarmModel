#pragma once
#ifndef FARMMODEL_COW_H
#define FARMMODEL_COW_H

#include <iostream>
#include "AbstractAnimal.h"

using namespace std;

/*
Definition for the class Cow
*/

class Cow :public AbstractAnimal {

public:

	Cow(void) :AbstractAnimal() {}

	/*
	The cows' specific collect procedure
	 */

	void collect() {

		milk();

	}

private:

	void milk(void) {

		cout << "The cows are milked." << endl;

	}
};

#endif