#include <iostream>
#include "../main/plants/PlantsPrototype.h"



int main()
{
	// Simulated stream of creation requests
	const int NUM_IMAGES = 10;		// 10 fields
	PlantType input[NUM_IMAGES] =
	{
	  Cotton, Cotton, Cotton, Wheat, Cotton, Wheat, Wheat, Cotton, Wheat, Cotton
	};

	Plant *images[NUM_IMAGES];

	// Given an plant type, find the right prototype, and return a clone
	for (int i = 0; i < NUM_IMAGES; i++)
		images[i] = Plant::findAndClone(input[i]);

	// Demonstrate that correct plant objects have been cloned
	for (int i = 0; i < NUM_IMAGES; i++)
		images[i]->draw();

	// Free the dynamic memory
	for (int i = 0; i < NUM_IMAGES; i++)
		delete images[i];
	return 0;
}