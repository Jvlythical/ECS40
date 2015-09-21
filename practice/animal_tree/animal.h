#ifndef ANIMAL_H
#define ANIMAL_H

class Animal {
	public:
		Animal ();
		Animal (int);
		void printAttr ();
		Animal &operator++();
		Animal operator++(int);
	private:
		int num_legs;
		int num_eyes;
		int num_ears;
};

#endif
