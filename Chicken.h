/*
 * Chicken.h
 *
 *  Created on: Dec 31, 2021
 *      Author: ise
 */

#include "Animal.h"

#ifndef CHICKEN_H_
#define CHICKEN_H_

class Chicken : public Animal{
public:
	const static int c_price;
	const static int c_dyingAge;
	Chicken() : Animal(c_price,c_dyingAge) {}
	virtual ~Chicken() {}
	int getPrice()const;
	bool isDyingAge();

};

#endif /* CHICKEN_H_ */
