#include <iostream>
#include <exception>
#include <stdexcept>

using namespace std;
class Eerror : public runtime_error {
	public:	
		Eerror (string mess) : runtime_error (mess) {};
};

class Animal {
public:
	Animal () {
		cout << "Animal is created" << endl;

		legs = 4;
	}

	virtual  ~Animal () {
		cout << "Animal is dead" << endl;
	}

	virtual void print () const {
		cout << "I am an animal" << endl;
	}

	void print2 () const {
		cout << "I am an animal2" << endl;
	}
protected:
	int legs;
};

class A : public Animal {
public:
	 ~A () {
		cout << "A is dead" << endl;
	}

	A () {
		cout << "A is created" << endl;
	}

	virtual void print () const {
		cout << "I am an A" << endl;
	}

	void print2 () const {
		cout << "I am an A2" << endl;
	}
};

class B {
public:
	B () {
		cout << "B is created" << endl;
	}
	~B () {
		cout << "B is dead" << endl;
	}

	virtual void print () const {
		cout << "I am a B" << endl;
	}

	void print2 () const {
		cout << "I am a B2" << endl;
	}
};

class C : public A, public B {
public:
	C () {
		cout << "C is created" << endl;
	}

	~C () {
		cout << "C is dead" << endl;
	}

	void print () const {
		cout << "I am a C" << endl;

	}

	void print2 () const {
		cout << "I am a C2" << endl;
	}

	int getLegs () const {
		return legs;
	}

};

void thrower () {
	throw Eerror ("error");
}

int main () {
	A *a = new A;
	B *b = new B;
	C *c = new C;
	Animal *an = new Animal;

	//Note here that because the print2 method is dereferenced from a b
	//pointer, the B print2 method is called
	//This because the print2 method is not virtual
	b = c;
	b->print2 ();

	try {
		if (b != NULL) {
			//b->print();
		}

		thrower ();
	}
	catch (Eerror &e) {
		//cout << e.what() << endl;
		//cout << "hi" << endl;
	}

	delete a;
	delete b;
	//delete c;
	delete an;

	return 0;
}
