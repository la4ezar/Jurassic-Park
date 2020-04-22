#include "JurassicPark.h"
#include <ctime>
#include <cstdlib>
#include <iostream>


JurassicPark::JurassicPark() {
	int x = (rand() % 15) + 1;
	cages_num = x;
	cages = new Cage[x];
	int rand_climate;
	int dinosaurs_num = 0;
	int y;
	for (int i = 0; i < x; ++i) {
		rand_climate = rand() % 3;
		Climate climate;
		switch (rand_climate){
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
		y = rand() % 15;
		cages[i] = Cage(y, climate);
		dinosaurs_num += y;
	}
	warehouse = Warehouse(dinosaurs_num * 10);	// default operator= is okay here(we have only ints to copy)
	staff = Staff(0);

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

void JurassicPark::reloadWarehouse() {
	warehouse.reloading();
}

void JurassicPark::addDinosaur(const char* name, Gender gender, Era era, Species species, Type type, Food food) {
	Dinosaur dino(name, gender, era, species, type, food);

	bool added = false;
	for (int i = 0; i < cages_num; ++i) {
		if (!cages[i].isFull() && cages[i].isSuitable(dino)) {
			cages[i].addDinosaur(dino);
			added = true;
			break;
		}
	}

	if (added == false)
		std::cerr << "We don't have cage for this dino. We can't add it.\n";
	else {
		std::cout << "Succesfully added.\n";
		staff.resize(1);
	}
}

void JurassicPark::removeDinosaur(const char* name, Gender gender, Era era, Species species, Type type, Food food) {
	int position;
	for (int i = 0; i < cages_num; ++i) {
		position = cages[i].dinosaurPosition(name, gender, era, species, type, food);
		if (position != -1) {
			cages[i].removeDinosaur(name, gender, era, species, type, food);
			staff.resize(-1);
			std::cout << "Succesfully removed.\n";
			return;
		}
	}
	std::cerr << "This dinosaur is not in the park. We can't remove it.\n";
}

void JurassicPark::addCage(int size, Climate climate) {
	Cage new_cage(size, climate);
	Cage* new_cages = new Cage[cages_num + 1];
	for (int i = 0; i < cages_num; ++i) {
		new_cages[i] = cages[i];
	}
	new_cages[cages_num] = new_cage;
	++cages_num;
	delete[] cages;
	cages = new_cages;
	new_cages = nullptr;
}