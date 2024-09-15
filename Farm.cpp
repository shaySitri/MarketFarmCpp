/*
 * Farm.cpp
 *
 *  Created on: Dec 31, 2021
 *      Author: ise
 */

#include "Farm.h"

int Farm::m_farmNumber = 1;

Farm::Farm() : m_ID(m_farmNumber), m_money(10) {
	m_fProducts[Milk] = 0;
	m_fProducts[Wool] = 0;
	m_fProducts[Eggs] = 0;
	m_farmNumber++;

}

Farm::~Farm() {
	unsigned int i = 0;
	for (i = 0 ; i < m_animals.size(); i++)
		delete m_animals[i];
	m_fProducts.clear();
	m_potentialBuyers.clear();
	m_animals.clear();
}


void Farm::printFarm()const
{
	// prints only farm products since it common to all farms.
	cout << "Milk" << "[" << this->m_fProducts.at(Milk) << "], " << "Wool" << "[" <<
			this->m_fProducts.at(Wool) << "], " <<  "Eggs" << "[" << this->m_fProducts.at(Eggs) << "]" << endl;
}

bool Farm::addClient(const Farm* farm)const{
	bool add = true;
	vector<Farm*>::iterator it;
	unsigned int i = 0;
	for (i = 0; i < this->m_potentialBuyers.size(); i++)
	{
		if (this->m_potentialBuyers[i] == farm)
		{
			add = false;
			break;
		}
	}
	for (i = 0; i < farm->m_potentialBuyers.size(); i++)
	{
		if (farm->m_potentialBuyers[i] == farm)
		{
			add = false;
			break;
		}
	}

	return add;
}

void Farm::ageUpAnimals(int years){
	unsigned int i = 0;
	for (i = 0; i < this->m_animals.size(); i++)
	{
		this->m_animals[i]->ageUp(years);
	}
}

void Farm::cleanFarm(){
	vector<Animal*>::iterator it;

	for (it = this->m_animals.begin(); it < this->m_animals.end(); it++)
	{
		if ((*it)->isDyingAge())
		{
			Animal* delAnimal = *it;
			this->m_animals.erase(it);
			it--;
			delete delAnimal;
		}
	}
}

