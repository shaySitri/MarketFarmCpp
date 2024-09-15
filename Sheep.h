/*
 * Sheep.h
 *
 *  Created on: Dec 31, 2021
 *      Author: ise
 */
#include "Animal.h"

#ifndef SHEEP_H_
#define SHEEP_H_

class Sheep : public Animal{
public:
	static int c_price;
	static int c_dyingAge;
	Sheep() : Animal(c_price,c_dyingAge) {}
	virtual ~Sheep() {}
	int getPrice()const;
	bool isDyingAge();
};

#endif /* SHEEP_H_ */
