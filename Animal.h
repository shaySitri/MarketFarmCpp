/*
 * Animal.h
 *
 *  Created on: Dec 31, 2021
 *      Author: ise
 */
#include <iostream>
using namespace std;

#ifndef ANIMAL_H_
#define ANIMAL_H_

// abstract class implements animal.

class Animal {
protected:
	int m_price;
	int m_dyingAge;
	int m_age;

public:
	// Animal constructor.
	Animal(int price, int dyingAge): m_price(price), m_dyingAge(dyingAge), m_age(0) {}
	// Return true if animal should die.
	virtual bool isDyingAge() = 0;
	// Return animal price. Each subclass return its own price.
	virtual int getPrice()const = 0;
	// Return animal current age.
	int getAge()const {return this->m_age;}
	// Animal distractor.
	virtual ~Animal() {}
	// Add X years to animal's age.
	void ageUp(int years) {this->m_age += years;}

};

#endif /* ANIMAL_H_ */
