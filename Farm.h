/*
 * Farm.h
 *
 *  Created on: Dec 31, 2021
 *      Author: ise
 */


#ifndef FARM_H_
#define FARM_H_
#include "Animal.h"
#include <map>
#include <vector>
using namespace std;

// enum name hold products name, enum val product price.
enum Products {Milk = 3, Wool = 2, Eggs = 1, none};

class Farm {
protected:
	// Counter of farm's number.
	static int m_farmNumber;
	// Hold specific ID.
	int m_ID;
	// Farm's money.
	int m_money;
	// Products list. All farms have the same product list, initiate to 0 for all products.
	map <Products, int> m_fProducts;
	// Each farm holds her potential clients.
	vector <Farm*> m_potentialBuyers;
	// Each farm holds her animals.
	vector <Animal*> m_animals;


public:
	// Farm constructor.
	Farm();
	// Farm distractor.
	virtual ~Farm();
	// Common for all farms. return farm ID.
	int getID()const{return this->m_ID;}
	// Add money to farm's money.
	void addMoney(int amount) {this->m_money += amount;}
	// Add to each animal of farm X years.
	void ageUpAnimals(int years);
	// Clean dead animals from farm.
	void cleanFarm();
	// Return if this appears in other(farm) potential clients and opposite.
	bool addClient(const Farm* farm)const;


	//PURE VIRTUAL:
	// Each farm buy her OWN animals.
	virtual void buyAnimals() = 0;
	// Decrease farm specific product in 1.
	virtual void updateProduct() = 0;
	// Buying products.  Differ for each kind of farm.
	// This buy products from other (farm). each farm buy different products.
	virtual void buyProducts(Farm* const farm) = 0;
	// Each farm has her own printing.
	// Common for all farms - poducts lidt print.
	virtual void printFarm()const = 0;
	// Update products status for farm. Differ for each kind of farm.
	// For example, for cow farm - there is growth of farm own milk. (cow products milk)
	// Calculate according animal age.
	virtual void updateFarmProduction() = 0;
	// Return the amount of farm self production.
	virtual int getProductAmount()const = 0;
	// Check is 1 farm is equal to other, according farm ID.
	bool operator== (const Farm* farm)const {return this->m_ID == farm->getID();}
	// add this to be client of farm
	virtual void handleSheep(Farm* farm) = 0;
	virtual void handleCow(Farm* farm) = 0;
	virtual void handleChicken(Farm* farm) = 0;
	// add farm to be client of this
	virtual void addSheep(Farm* farm) = 0;
	virtual void addCow(Farm* farm) = 0;
	virtual void addChicken(Farm* farm) = 0;


	friend class Market;





};

#endif /* FARM_H_ */
