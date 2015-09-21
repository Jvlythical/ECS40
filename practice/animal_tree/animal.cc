#include <iostream>
#include "animal.h"

Animal::Animal () {
	this->num_legs = 1;
	this->num_eyes = 2;
	this->num_ears = 2;
}

Animal::Animal (int num_legs) {
	this->num_legs = num_legs;
}

Animal &Animal::operator++() {
	Animal *baby = new Animal ();

	return *baby;
}

Animal Animal::operator++(int) {
	Animal *baby = new Animal ();

	return *this;
}

void Animal::printAttr () {
	std::cout << this->num_legs << std::endl;
	std::cout << this->num_eyes << std::endl;
	std::cout << this->num_ears << std::endl;
}
