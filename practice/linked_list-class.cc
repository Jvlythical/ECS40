#include <iostream>

class Node {
	private:
		Node *n;
		int d;

	public:
		Node ();
		void setNext (Node *n);
		void setData (int d);
		Node * getNext();
		int getData ();
};

int main () {
	int d;

	Node *n1 = new Node ();
	Node *n2 = new Node ();

	n1->setData (1);
	n1->setNext (n1);
	n2->setData (2);
	n2->setNext (NULL);
	d = n1->getData();

	std::cout << d;

	return 0;
}

Node::Node() {
	this->d = 0;
}

void Node::setData (int d) {
	this->d = d;
}

void Node::setNext (Node *n) {
	this->n = n;
}

Node * Node::getNext () {
	return this->n;
}

int Node::getData () {
	return this->d;
}
