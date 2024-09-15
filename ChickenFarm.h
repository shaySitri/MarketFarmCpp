/*
 * ChickenFarm.h
 *
 *  Created on: Jan 1, 2022
 *      Author: ise
 */
#include "Farm.h"
#include "Chicken.h"

#ifndef CHICKENFARM_H_
#define CHICKENFARM_H_

class ChickenFarm : public Farm {
public:
	// Chicken constructor - initiate with 3 chickens.
	ChickenFarm();
	// Chicken distructor.
	virtual ~ChickenFarm() {}
	// Chicken by animals method - farm buy CHICKENS until she has no enough money left to buy another chicken.
	void buyAnimals();
	// Print chicken farm.
	void printFarm()const;
	// Update farm Eggs production, according all chickens ages. (chicken product eggs)
	void updateFarmProduction();
	// Chicken buying method. If this method is activate, chicken buy Wool from sheep farm.
	void buyProducts(Farm* farm);
	// Return number of eggs farm has.
	int getProductAmount()const {return this->m_fProducts.at(Eggs);}
	// Decrease eggs amount in specific farm by 1.
	virtual void updateProduct();
	// Chicken in a potential client of Sheep. So: chicken adds himself to sheep potential clients.
	virtual void handleSheep(Farm* farm);
	// Chicken farm adds Cow farm to his potential clients list.
	virtual void addCow(Farm* farm);
	// Observe pattern methods
	virtual void handleCow(Farm* farm){}
	virtual void handleChicken(Farm* farm){}
	virtual void addSheep(Farm* farm) {}
	virtual void addChicken(Farm* farm) {}


};

#endif /* CHICKENFARM_H_ */
