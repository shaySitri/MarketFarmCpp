/*
 * Cow.cpp
 *
 *  Created on: Dec 31, 2021
 *      Author: ise
 */

#include "Cow.h"

const int Cow::c_price = 10;
const int Cow::c_dyingAge = 10;

int Cow::getPrice()const {return this->c_price;}
bool Cow::isDyingAge() {return this->m_age >= this->c_dyingAge;}
