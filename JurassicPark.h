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

	void addDinosaur();
	void removeDinosaur();
	void addCage();
	void reloadWarehouse();
};