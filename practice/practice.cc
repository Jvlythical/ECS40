#include <iostream>
#include <cstdlib>

struct node {
	int data;
	struct node *n;
};

int main () {
	struct node *n1 = (node *) malloc (sizeof (node));
	n1->data = 1;

	std::cout << n1->data;

	return 0;
}
