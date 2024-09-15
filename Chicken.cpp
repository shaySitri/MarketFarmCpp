/*
 * Chicken.cpp
 *
 *  Created on: Dec 31, 2021
 *      Author: ise
 */

#include "Chicken.h"

const int Chicken::c_price = 3;
const int Chicken::c_dyingAge = 3;

bool Chicken::isDyingAge() {return this->m_age >= this->c_dyingAge;}
int Chicken::getPrice()const  {return c_price;}

