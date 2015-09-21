#include <iostream>
#include <cstdlib>

struct Node {
	struct Node *next;
	int data;
};

int main () {
	struct Node *n1 = NULL, *n2 = NULL;
	struct Node *cur;
	int count = 0;

	n1 = (struct Node *) malloc (sizeof (struct Node));
	n2 = (struct Node *) malloc (sizeof (struct Node));

	n1->data = 1;
	n2->data = 2;
	n1->next = n2;
	n2->next = NULL;

	cur = n1;
	while (cur != NULL) {
		cur = cur->next;
		count++;
	}

	std::cout << count;
	

	return 0;
}
