#include <iostream>
#include "animal.h"

int main () {
	Animal a(2), b(4), c(3);

	b.printAttr ();

	b = a++;

	b.printAttr ();

	return 0;
}
