/*
 * Market.h
 *
 *  Created on: Jan 6, 2022
 *      Author: ise
 */

#ifndef MARKET_H_
#define MARKET_H_

#include "Farm.h"
#include "CowFarm.h"
#include "ChickenFarm.h"
#include "SheepFarm.h"

class Market {
private:
	int m_year;
	vector <Farm*> m_Farms;
	// PART 2 of TRADING DAY: each farm buy animals until it has no money left.
	void buyAnimals();
	// Each year new farms can join market.
	void createNewFarms();
	// PART 1 of TRADING DAY:
	void farmsTrade();
	// Update farm curren products this year.
	void updateFarmsProduction();
	// All animals in the market grows up in X years,
	void ageUpYears(int years);
	// Clean all dead animals from market.
	void findDeadAnimals();
	// All farms get extra money.
	void addMoneyToFarms(int amount);
	// Doing trading day.
	void traidingDay();
	// Check input methods:
	void checkCowFarmAmount(int amount)const;
	void checkChickenFarmAmount(int amount)const;
	void checkSheepFarmAmount(int amount)const;



public:
	// Initiate new market. Years = 0.
	Market() : m_year(0) {}
	// Market distructor
	virtual ~Market();
	// Trading day after 1 year.
	void nextYear();
	// Trading day - once a year, runs X years forward and print the trades been made.
	void fastForwardYears();
	// Print current market farms status.
	void printMarketFarms()const;
	// return current market age.
	int getYear()const {return this->m_year;}

};

#endif /* MARKET_H_ */
