/*
 * ChickenFarm.cpp
 *
 *  Created on: Jan 1, 2022
 *      Author: ise
 */

#include "ChickenFarm.h"

ChickenFarm::ChickenFarm() {
	// chicken farm has 3 chicken initially.
	int i;
	for (i = 0; i<3; i++)
	{
		Chicken* chicken = new Chicken();
		if (chicken == NULL)
			exit(0);
		else
		m_animals.emplace_back(chicken);
	}
}


void ChickenFarm::buyAnimals() {
	int price = Chicken::c_price;
	int totalChicknes = 0;
	while (this->m_money - price >= 0)
	{
		Chicken* chicken = new Chicken();
		if (chicken == NULL) exit(0);
		m_animals.emplace_back(chicken);
		this->m_money = this->m_money - price;
		totalChicknes++;
	}
	if (totalChicknes > 0)
	cout << "Chicken farm(" << this->m_ID << ") bought " << totalChicknes <<  " chickens for " <<
			totalChicknes*price << " dollars" << endl;
}

void ChickenFarm::printFarm()const {
	cout << "Farm Id: " << this->m_ID << ", type: Chicken Farm, Money: " << this->m_money << ", Animals: " <<
	this->m_animals.size() << " chickens, Products: ";
	Farm::printFarm();
}

void ChickenFarm::updateFarmProduction() {
	int newProductAmount = 0;
	vector<Animal*>::iterator it;
	for (it = this->m_animals.begin(); it < this->m_animals.end(); it++)
		newProductAmount += (*it)->getAge();
	this->m_fProducts[Eggs] += newProductAmount;
}


void ChickenFarm::buyProducts(Farm* farm){
	int total = 0;
	while (this->m_money - Wool >= 0 && farm->getProductAmount() > 0) // possible buying eggs
	{
		this->m_fProducts[Wool]++;
		this->m_money -= Wool;
		farm->addMoney(Wool);
		farm->updateProduct();
		total++;
	}
	if (total > 0)
		cout << "Chicken farm(" << this->getID() << ") bought " << total << " wool for " << Wool*total
				<< " dollars from Sheep farm(" << farm->getID() << ")" << endl;
}


void ChickenFarm::addCow(Farm* cowFarm){
	this->m_potentialBuyers.push_back(cowFarm);
	cout << "Chicken farm(" << this->getID() << ") Added Cow farm(" << cowFarm->getID()
			<< ") to his client list" << endl;
}

void ChickenFarm::handleSheep(Farm* farm){
	farm->addChicken(this);
}

void ChickenFarm::updateProduct() {this->m_fProducts[Eggs]--;}

