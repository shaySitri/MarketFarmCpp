/*
 * CowFarm.h
 *
 *  Created on: Dec 31, 2021
 *      Author: ise
 */
#include "Farm.h"
#include "Cow.h"

#ifndef COWFARM_H_
#define COWFARM_H_

class CowFarm : public Farm{
public:
	// Cow constructor - initiate with 3 cows.
	CowFarm();
	// Cow distructor.
	virtual ~CowFarm() {}
	// Cow buy animals method - farm buy COWS until she has no enough money left to buy another cow.
	void buyAnimals();
	// Print cow farm.
	void printFarm()const;
	// Update farm Milk production, according all cows ages. (cow product eggs)
	void updateFarmProduction();
	// Cow buying method. If this method is activate, cow buy eggs from chicken farm.
	void buyProducts(Farm* farm);
	// Return number of milk farm has.
	int getProductAmount()const {return this->m_fProducts.at(Milk);}
	// Decrease milk amount in specific farm by 1.
	virtual void updateProduct();

	// Cow is a potential client of Chicken. So: cow adds himself to chicken potential clients.
	virtual void handleChicken(Farm* farm);
	// Cow farm adds sheep farm to his potential clients list.
	virtual void addSheep(Farm* farm);
	// Observe pattern methods
	virtual void handleSheep(Farm* farm){}
	virtual void handleCow(Farm* farm){}
	virtual void addCow(Farm* farm) {}
	virtual void addChicken(Farm* farm) {}

};

#endif /* COWFARM_H_ */
