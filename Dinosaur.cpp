#include "Dinosaur.h"
#include <cstring>

Dinosaur::Dinosaur() : gender(unknown_gender), era(unknown_era), species(unknown_species), 
					   type(unknown_type), food(unknown_food) {
	strcpy(this->name, "Unknown");

}

Dinosaur::Dinosaur(const char* name, Gender gender, Era era, Species species, Type type, Food food) 
				  : gender(gender), era(era), species(species), type(type), food(food) {
	strcpy(this->name, name);
	
}

Dinosaur::Dinosaur(const char* name, Gender gender, Era era, Species species)
				  : gender(gender), era(era), species(species) {
	strcpy(this->name, name);
}

Dinosaur& Dinosaur::operator=(const Dinosaur& other) {
	if (this != &other) {
		strcpy(this->name, other.name);
		this->gender = other.gender;
		this->era = other.era;
		this->food = other.food;
		this->type = other.type;
		this->species = other.species;
	}
	return *this;
}

bool Dinosaur::operator==(const Dinosaur& other) const {
	return (!strcmp(this->name, other.name) &&
			this->era == other.era &&
			this->species == other.species &&
			this->gender == other.gender &&
			this->type == other.type &&
			this->food == other.food);
}


std::ostream& operator<<(std::ostream& out, const Dinosaur& dino) {
	return out << dino.getName() << ' ' << dino.getGender() << ' ' << dino.getEra() <<
		' ' << dino.getSpecies() << ' ' << dino.getType() << ' ' << dino.getFood();
}

const char* Dinosaur::getName() const {
	return name;
}

Gender Dinosaur::getGender() const {
	return gender;
}
Era Dinosaur::getEra() const {
	return era;
}
Species Dinosaur::getSpecies() const {
	return species;
}
Type Dinosaur::getType() const {
	return type;
}
Food Dinosaur::getFood() const {
	return food;
}

void Dinosaur::setUnknown() {
	Dinosaur d;
	*this = d;
}