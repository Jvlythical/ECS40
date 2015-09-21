#ifndef LINKEDLIST_H

#define LINKEDLIST_H
	struct node {
		int data;
		struct node *next;
		struct node *prev;
	};

	class LinkedList {
		public:
			LinkedList ();
			node* getHead ();
			void insertAtEnd (int d);
			void insertAtN (int d, int nth);
			void displayAll ();
			void displayN (int nth);

		private:
			node *head;
			node *tail;
	};

	LinkedList::LinkedList () {
		head = new node ();
		tail = new node ();

		head->prev = NULL;
		head->next = tail;
		tail->prev = head;
		tail->next = NULL;
	}

	void LinkedList::insertAtEnd (int d) {
		node *n = new node ();
		n->data = d;
		n->prev = tail->prev;
		tail->prev->next = n;
		n->next = tail;
		tail->prev = n;
	}

	node* LinkedList::getHead () {
		return head;
	}

	void LinkedList::insertAtN (int d, int nth) {
		int i = nth, k;
		node *n = new node ();
		n->data = d;
		node *cur = this->head->next;

		for (k = 0; k < i; k++) {
			cur = cur->next;
		}

		n->prev = cur->prev;
		cur->prev->next = n;
		n->next = cur;
		cur->prev = n;
	}

	void LinkedList::displayN (int nth) {
		int i = nth, k;
		node *cur = this->head->next;

		for (k = 0; k < i; k++) {
			cur = cur->next;
		}

		std::cout << cur->data << std::endl;
	}

	void LinkedList::displayAll () {
		node *cur = this->head->next;

		while (cur->next != NULL) {
			std::cout << cur->data << std::endl;
			cur = cur->next;
		}
	}

#endif

