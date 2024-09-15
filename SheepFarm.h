/*
 * SheepFarm.h
 *
 *  Created on: Jan 1, 2022
 *      Author: ise
 */
#include "Farm.h"
#include "Sheep.h"

#ifndef SHEEPFARM_H_
#define SHEEPFARM_H_

class SheepFarm : public Farm{
public:
	//Sheep constructor - initiate with 3 sheeps.
	SheepFarm();
	// Sheeps distructor.
	virtual ~SheepFarm() {}
	// Sheeps buy animals method - farm buy SHEEPS until it has no enough money left to buy another sheep.
	void buyAnimals();
	// Print chicken farm.
	void printFarm()const;
	// Update farm Wool production, according all sheeps ages. (sheep product wool)
	void updateFarmProduction();
	// Sheep buying method. If this method is activate, Sheep buy milk from cow farm.
	void buyProducts(Farm* farm);
	// Return number of wool farm has.
	int getProductAmount()const {return this->m_fProducts.at(Wool);}
	// Decrease eggs amount in specific farm by 1.
	void updateProduct() {this->m_fProducts[Wool]--;}

	// Sheep is a potential client of Cow. So: sheep adds itself to cow's potential clients.
	virtual void handleCow(Farm* farm);
	// Sheep farm adds chicken farm to his potential clients list.
	virtual void addChicken(Farm* farm);
	// Observe pattern methods
	virtual void handleSheep(Farm* farm) {}
	virtual void handleChicken(Farm* farm) {}
	virtual void addSheep(Farm* farm) {}
	virtual void addCow(Farm* farm) {}

};

#endif /* SHEEPFARM_H_ */
