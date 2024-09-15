/*
 * Cow.h
 *
 *  Created on: Dec 31, 2021
 *      Author: ise
 */
#include "Animal.h"

#ifndef COW_H_
#define COW_H_

class Cow : public Animal{
public:
	const static int c_price;
	const static int c_dyingAge;
	Cow(): Animal(c_price,c_dyingAge) {}
	virtual ~Cow() {}
	int getPrice()const;
	bool isDyingAge();
};

#endif /* COW_H_ */
