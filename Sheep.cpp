/*
 * Sheep.cpp
 *
 *  Created on: Dec 31, 2021
 *      Author: ise
 */

#include "Sheep.h"

int Sheep::c_price = 5;
int Sheep::c_dyingAge = 5;



int Sheep::getPrice()const
{
	return c_price;
}

bool Sheep::isDyingAge(){
	 return this->m_age >= this->c_dyingAge;
}
