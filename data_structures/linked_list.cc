#include <iostream>
#include "LinkedList.h"

using namespace std;

int main () {
	int i;
	LinkedList *l = new LinkedList ();
	LinkedList *l3 = new LinkedList ();

	l3->insertAtEnd (3);

	(*l).operator=(*l3);

	l->insertAtEnd (10);
	l->insertAtN (11, 1);

	LinkedList &l2 = *l;

	l2.displayAll();

	for (i = 0; i < 10; i++) {
		l2.insertAtEnd (i);
	}

	l2.displayAll ();

	return 0;
}

