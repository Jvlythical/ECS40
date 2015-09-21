#include <iostream>
#include <string>
#include "LinkedList.h"
#include "ListNode.h"

using namespace std;

int test (const int &x) {
	if (x % 2 == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

int main () {
	LinkedList <int> ll;

	ll.insertAtFront (1);
	ll.insertAtFront (2);
	ll.insertAtFront (2);
	ll.insertAtFront (3);

	ll.map (test);
	ll.print ();

	return 0;
}
