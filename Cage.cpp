#include "Cage.h"
#include <iostream>

Cage::Cage()
	: size(0), climate(unknown_climate), dinosaurs_num(0), era(unknown_era), type(unknown_type) {
	dinosaurs_arr = nullptr;
}

Cage::Cage(int size, Climate climate) 
	: size(size), climate(climate), dinosaurs_num(0), era(unknown_era), type(unknown_type) {
	if (size != 3 && size != 10 && size != 1) {
		if (size < 1) size = 1;
		else if (size > 10) size = 10;
		else size = 3;
	}
	dinosaurs_arr = new Dinosaur[size];
	this->size = size;
}

Cage& Cage::operator=(const Cage& other) {
	if(this != &other){
		this->size = other.size;
		if (dinosaurs_num == 1)
			delete this->dinosaurs_arr;
		else
			delete[] this->dinosaurs_arr;
		this->dinosaurs_arr = other.getDinosaursArr();
		this->climate = other.climate;
		this->era = other.era;
		this->type = other.type;
		this->dinosaurs_num = other.dinosaurs_num;
	}
	return *this;
}

Cage::~Cage() {
	delete[] dinosaurs_arr;
	dinosaurs_arr = nullptr;
}


bool Cage::isEmpty() const {
	return (dinosaurs_num == 0);
}

bool Cage::isFull() const {
	if (dinosaurs_num == size)
		return true;
	return false;
}

bool Cage::isSuitable(Dinosaur& dino) const {
	if (isFull())
		return false;

	Type type = dino.getType();
	switch (type) {
	case Herbivorous:
	case Carnivorous:
		if (climate != terrestrial) {
			return false;
		}
		break;
	case Flying:
		if (climate != air) {
			return false;
		}
		break;
	case Watery:
		if (climate != aqueous) {
			return false;
		}
		break;
	}
	
	if (dino.getEra() != era && era != unknown_era)
		return false;

	return true;
}

unsigned Cage::getDinosaursNum() const {
	return dinosaurs_num;
}
unsigned Cage::getSize() const {
	return size;
}
Climate Cage::getClimate() const {
	return climate;
}
Era Cage::getEra() const {
	return era;
}

Dinosaur* Cage::getDinosaursArr() const {
	Dinosaur* new_arr = new Dinosaur[size];
	for (int i = 0; i < size; ++i) {
		new_arr[i] = dinosaurs_arr[i];
	}
	return new_arr;
}

void Cage::addDinosaur(const char* name, Gender gender, Era era, Species species, Type type, Food food) {
	if(isFull()) {
		std::cerr << "There is not enough space for one more dinosaur ! \n";
		return;
	}

	switch (type) {
	case Herbivorous:
	case Carnivorous:
		if (climate != terrestrial) {
			std::cout << "This dinosaur can't live in " << climate << " climate! We will not add it to the cage! \n";
			return;
		}
		break;
	case Flying:
		if (climate != air) {
			std::cout << "This dinosaur can't live in " << climate << " climate! We will not add it to the cage! \n";
			return;
		}
		break;
	case Watery:
		if (climate != aqueous) {
			std::cout << "This dinosaur can't live in " << climate << " climate! We will not add it to the cage! \n";
			return;
		}
		break;
	}

	if (this->era == unknown_era) 
		this->era = era;
	

	if (this->type == unknown_type) 
		this->type = type;
	
	if (this->era != era) {
		std::cerr << "This dinosaur is NOT from " << this->era << " era! We will not add it to the cage!\n";
		return;
	}

	if (this->type != type) {
		std::cerr << "This dinosaur is NOT " << this->type << " ! We will not add it to the cage!\n";
		return;
	}

	

	Dinosaur new_dino(name, gender, era, species, type, food);
	
	for (int i = 0; i < size; ++i) {
		if (dinosaurs_arr[i].getGender() == unknown_gender) {
			dinosaurs_arr[i] = new_dino;
			++dinosaurs_num;
			break;
		}
	}
}

int Cage::dinosaurPosition(const char* name, Gender gender, Era era, Species species, Type type, Food food) const {
	Dinosaur searched_dino(name, gender, era, species, type, food);
	for (int i = 0; i < size; ++i) 
		if (dinosaurs_arr[i] == searched_dino) 
			return i;		// The position of the dino if it is in the cage.
		
	return -1;	// If this dino is not in the cage.
}

void Cage::removeDinosaur(const char* name, Gender gender, Era era, Species species, Type type, Food food) {
	if (isEmpty()) {
		std::cout << "The cage is empty!";
		return;
	}

	if (gender == unknown_gender)
		return;
	
	int dinoPosition = dinosaurPosition(name, gender, era, species, type, food);

	if (dinoPosition != -1) {
		dinosaurs_arr[dinoPosition].setUnknown();
		--dinosaurs_num;
		if (dinosaurs_num == 0)
			type = unknown_type;
		return;
	}
	std::cout << "This dinosaur is NOT in that cage!" << std::endl;
}

void Cage::removeDinosaur(const Dinosaur other) {
	removeDinosaur(other.getName(), other.getGender(), other.getEra(), other.getSpecies(), other.getType(), other.getFood());
}

void Cage::addDinosaur(const Dinosaur other) {
	addDinosaur(other.getName(), other.getGender(), other.getEra(), other.getSpecies(), other.getType(), other.getFood());
}