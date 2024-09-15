/*
 * SheepFarm.cpp
 *
 *  Created on: Jan 1, 2022
 *      Author: ise
 */

#include "SheepFarm.h"

SheepFarm::SheepFarm() {
	int i;
	for (i = 0; i<3; i++)
	{
		Sheep* sheep = new Sheep();
		if (sheep == NULL)
			exit(0);
		else
		m_animals.emplace_back(sheep);
	}}

void SheepFarm::buyAnimals(){
	int price = Sheep::c_price;
	int totalSheeps = 0;
	while (this->m_money - price >= 0)
	{
		Sheep* sheep = new Sheep();
		if (sheep == NULL) exit(0);
		m_animals.push_back(sheep);
		this->m_money = this->m_money - price;
		totalSheeps++;
	}
	if (totalSheeps > 0)
	cout << "Sheep farm(" << this->m_ID << ") bought " << totalSheeps <<  " sheeps for " <<
			totalSheeps*price << " dollars" << endl;

}

void SheepFarm::printFarm()const{
	cout << "Farm Id: " << this->m_ID << ", type: Sheep farm, Money: " << this->m_money << ", Animals: " <<
			this->m_animals.size() << " sheep, Products: ";
	Farm::printFarm();
}

void SheepFarm::updateFarmProduction(){
	int newProductAmount = 0;
	vector<Animal*>::iterator it;
	for (it = this->m_animals.begin(); it < this->m_animals.end(); it++)
		newProductAmount += (*it)->getAge();
	this->m_fProducts[Wool] += newProductAmount;
}

void SheepFarm::buyProducts(Farm* farm){
	int total = 0;
	while (this->m_money - Milk >= 0 && farm->getProductAmount() > 0) // possible buying eggs
	{
		this->m_fProducts[Milk]++;
		this->m_money -= Milk;
		farm->addMoney(Milk);
		farm->updateProduct();
		total++;
	}
	if (total > 0)
		cout << "Sheep farm(" << this->getID() << ") bought " << total << " milk for " << Milk*total
				<< " dollars from Cow farm(" << farm->getID() << ")" << endl;

}


void SheepFarm::addChicken(Farm* chickenFarm){
	this->m_potentialBuyers.push_back(chickenFarm);
	cout << "Sheep farm(" << this->m_ID << ") Added Chicken farm(" << chickenFarm->getID() << ") to his client list" << endl;

}

void SheepFarm::handleCow(Farm* cowFarm){
	cowFarm->addSheep(this);
}
