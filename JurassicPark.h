#pragma once
#include "Cage.h"
#include "Staff.h"
#include "Warehouse.h"

class JurassicPark {
	int cages_num;
	Cage* cages;
	Staff staff;
	Warehouse warehouse;
	
public:
	JurassicPark();
	~JurassicPark();

	int getFood() const;
	int getFoodCapacity() const;
	int getStaff() const;
	int getCagesNum() const;
	Cage* getCages() const;

	void addDinosaur(const char* name, Gender gender, Era era, Species species, Type type, Food food);
	void removeDinosaur(const char* name, Gender gender, Era era, Species species, Type type, Food food);
	void addCage(int size, Climate climate);
	void reloadWarehouse();
};