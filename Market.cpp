/*
 * Market.cpp
 *
 *  Created on: Jan 6, 2022
 *      Author: ise
 */

#include "Market.h"
#include "Exceptions.h"


Market::~Market(){
	unsigned int i = 0;
	for (i = 0; i < this->m_Farms.size(); i++)
		delete m_Farms[i];
	m_Farms.clear();
}

void Market::checkCowFarmAmount(int amount)const{
	if (amount < 0)
	{
		cowException c;
		throw c;
	}
}
void Market::checkChickenFarmAmount(int amount)const{
	if (amount < 0)
	{
		chickenException c;
		throw c;
	}
}
void Market::checkSheepFarmAmount(int amount)const{
	if (amount < 0)
	{
		sheepException s;
		throw s;
	}
}


void Market::createNewFarms(){
	int i = 0;
	unsigned int m = 0;
	int cowAmount, chickenAmount, sheepAmount = 0;
	cout<< "----Creating new farms----" <<endl;
	bool valid = false;
	do
	{
		try
		{
			cout<< "How many new cow farms will be added this year?" << endl;
			cin >> cowAmount;
			this->checkCowFarmAmount(cowAmount);
			cout<< "How many new sheep farms will be added this year?" << endl;
			cin >> sheepAmount;
			this->checkSheepFarmAmount(sheepAmount);
			cout<< "How many new chicken farms will be added this year?" << endl;
			cin >> chickenAmount;
			this->checkChickenFarmAmount(chickenAmount);
			valid = true;
		}

		catch(exception& e)
		{
			cowAmount = 0;
			chickenAmount = 0;
			sheepAmount = 0;
			cout << e.what() << endl;
		}
	} while (!valid);



	cout<< "----Adding new farms to market----" <<endl;
	for (i = 0; i < cowAmount; i++)
	{
		Farm* cowF = new CowFarm();
		if (cowF == NULL)
			exit(0);
		this->m_Farms.push_back(cowF);
		for (m =0; m < this->m_Farms.size(); m++)
		{
			if (!cowF->addClient(m_Farms[m])) break;
			cowF->handleChicken(m_Farms[m]);
			m_Farms[m]->handleCow(cowF);
		}
	}
	for (i = 0; i < sheepAmount; i++)
	{
		Farm* sheepF = new SheepFarm();
		if (sheepF == NULL) exit(0);
		this->m_Farms.push_back(sheepF);
		for (m =0; m < this->m_Farms.size(); m++)
		{
			if (!sheepF->addClient(m_Farms[m])) break;
			sheepF->handleCow(m_Farms[m]);
			m_Farms[m]->handleSheep(sheepF);
		}
	}

	for (i = 0; i < chickenAmount; i++)
	{
		Farm* chickenF = new ChickenFarm();
		if (chickenF == NULL) exit(0);
		this->m_Farms.push_back(chickenF);
		for (m =0; m < this->m_Farms.size(); m++)
		{
			if (!chickenF->addClient(m_Farms[m])) break;
			chickenF->handleSheep(m_Farms[m]);
			m_Farms[m]->handleChicken(chickenF);
		}
	}
}



void Market::farmsTrade()
{
	unsigned int i= 0;
	vector<Farm*>::iterator it;
	for (it = this->m_Farms.begin(); it < this->m_Farms.end(); it++)
	{
		for (i = 0; i < (*it)->m_potentialBuyers.size(); i++){
			{
				if ((*it)->getProductAmount() < 1) break;
				(*it)->m_potentialBuyers[i]->buyProducts(*it);
			}
		}
	}
}



void Market::traidingDay(){
	cout<< "----Begin Market----" <<endl;
	this->farmsTrade();
	cout<< "----Buy Animals----" <<endl;
	this->buyAnimals();
}

void Market::buyAnimals(){
	vector<Farm*>::iterator it;
	for (it = this->m_Farms.begin(); it < this->m_Farms.end(); it++)
		(*it)->buyAnimals();
}

void Market::printMarketFarms()const{
	cout << "----Market Farms----"<<endl;
	unsigned int i = 0;
	for (i = 0; i < this->m_Farms.size(); i++)
		this->m_Farms.at(i)->printFarm();
}

void Market::updateFarmsProduction(){
	vector<Farm*>::iterator it;
	for (it = this->m_Farms.begin(); it < this->m_Farms.end(); it++)
		(*it)->updateFarmProduction();

}

void Market::ageUpYears(int years){
	vector<Farm*>::iterator it;
	for (it = this->m_Farms.begin(); it < this->m_Farms.end(); it++)
		(*it)->ageUpAnimals(years);
}

void Market::findDeadAnimals(){
	vector<Farm*>::iterator it1;
	for (it1 = this->m_Farms.begin(); it1 < this->m_Farms.end(); it1++)
	{
		(*it1)->cleanFarm();
	}

}

void Market::addMoneyToFarms(int amount){
	unsigned int i = 0;
	for (i = 0; i < this->m_Farms.size(); i++)
	{
		this->m_Farms[i]->addMoney(amount);
	}

}

void Market::nextYear(){
	this->createNewFarms();
	this->updateFarmsProduction();
	this->traidingDay();
	this->ageUpYears(1);
	this->findDeadAnimals();
	this->addMoneyToFarms(10);
	this->m_year++;
}

void Market::fastForwardYears(){
	int i, fastForward = 0;
	cout<< "How many years to fast forward?" << endl;
	cin >> fastForward;
	for (i = 0; i < fastForward; i++)
	{
		this->updateFarmsProduction();
		this->traidingDay();
		this->ageUpYears(1);
		this->findDeadAnimals();
		this->addMoneyToFarms(10);
		this->m_year++;
	}

}

