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

	int getCagesNum() const;
	Cage* getCages() const;

	void addDinosaur(const char* name, Gender gender, Era era, Species species, Type type, Food food);
	void removeDinosaur(const char* name, Gender gender, Era era, Species species, Type type, Food food);
	void addCage();	//resize the warehouse and staff
	void reloadWarehouse();
};