/*
 * CowFarm.cpp
 *
 *  Created on: Dec 31, 2021
 *      Author: ise
 */

#include "CowFarm.h"

CowFarm::CowFarm() {
	int i;
	for (i = 0; i<3; i++)
	{
		Cow* cow = new Cow();
		if (cow == NULL)
			exit(0);
		else
		m_animals.emplace_back(cow);
	}
}


void CowFarm::buyAnimals() {
	int price = Cow::c_price;
	int totalCows = 0;
	while (this->m_money - price >= 0)
	{
		Cow* cow = new Cow();
		if (cow == NULL) exit(0);
		m_animals.push_back(cow);
		this->m_money = this->m_money - price;
		totalCows++;
		//delete a;
	}
	if (totalCows > 0)
	cout << "Cow farm(" << this->m_ID << ") bought " << totalCows <<  " cows for " <<
			totalCows*price << " dollars"<<endl;

}

void CowFarm::printFarm()const {
	cout << "Farm Id: " << this->m_ID << ", type: Cow farm, Money: " << this->m_money << ", Animals: " <<
			m_animals.size() << " cows, Products: ";
	Farm::printFarm();
}

void CowFarm::updateFarmProduction()
{
	int newProductAmount = 0;
	vector<Animal*>::iterator it;
	for (it = this->m_animals.begin(); it < this->m_animals.end(); it++)
		newProductAmount += (*it)->getAge();
	this->m_fProducts[Milk] += newProductAmount;
}

void CowFarm::buyProducts(Farm* farm){
	int total = 0;
	while (this->m_money - Eggs >= 0 && farm->getProductAmount() > 0) // possible buying eggs
	{
		this->m_fProducts[Eggs]++;
		this->m_money -= Eggs;
		farm->addMoney(Eggs);
		farm->updateProduct();
		total++;
	}
	if (total > 0)
		cout << "Cow farm(" << this->getID() << ") bought " << total << " eggs for " << Eggs*total
				<< " dollars from Chicken farm(" << farm->getID() << ")" << endl;

}

void CowFarm::addSheep(Farm* sheepFarm){
	this->m_potentialBuyers.push_back(sheepFarm);
	cout << "Cow farm(" << this->getID() << ") Added Sheep farm(" << sheepFarm->getID() << ") to his client list" << endl;

}

void CowFarm::handleChicken(Farm* farm){
	farm->addCow(this);

}

void CowFarm::updateProduct() {this->m_fProducts[Milk]--;}
