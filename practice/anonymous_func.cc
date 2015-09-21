#include <iostream>

using namespace std;

int test () {
	int i = [] () {
		return 1;
	};

	return i;
}

int main () {
	
	test();

	return 0;
}
