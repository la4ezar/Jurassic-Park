#include "JurassicPark.h"
#include <ctime>
#include <cstdlib>
#include <iostream>


JurassicPark::JurassicPark() {
	int x = (rand() % 10) + 1;
	cages_num = x;
	cages = new Cage[x];
	int y;
	for (int i = 0; i < x; ++i) {
		y = rand() % 3;
		Climate climate;
		switch (y){
			case 0: 
				climate = terrestrial;
				break;
			case 1:
				climate = aqueous;
				break;
			case 2:
				climate = air;
				break;
			default:
				climate = unknown_climate;
		}
		cages[i] = Cage(rand() % 15, climate);
	}
}
JurassicPark::~JurassicPark() {
	if (cages_num == 1)
		delete cages;
	else
		delete[] cages;
}

int JurassicPark::getCagesNum() const {
	return cages_num;
}
Cage* JurassicPark::getCages() const {
	Cage* new_cages = new Cage[cages_num];
	for (int i = 0; i < cages_num; ++i) 
		new_cages[i] = cages[i];
	return new_cages;
}