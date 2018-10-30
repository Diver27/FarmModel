
#include <iostream>
#include "../main/animals/Cow.h"
#include "../main/animals/Sheep.h"

using namespace std;

/**

 * Test program for animal

 * @return

 */

int main(void) {

	Cow cow;

	cow.harvest();

	Sheep sheep;

	sheep.harvest();

	cow.operate(1);

	return 0;

}