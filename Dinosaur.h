#pragma once
#include "Gender.h"
#include "Era.h"
#include "Speciesh.h"
#include "Type.h"
#include "Food.h"

class Dinosaur {
	char name[30];
	Gender gender;
	Era era;
	Species species;
	Type type;
	Food food;

public:
	Dinosaur();
	Dinosaur(const char* name,Gender gender, Era era, Species species, Type type, Food food);
	Dinosaur(const char* name, Gender gender, Era era, Species species);
	//~Dinosaur();
	Dinosaur& operator=(const Dinosaur& other);
	bool operator==(const Dinosaur& other) const;
	friend std::ostream& operator<<(std::ostream& out, const Dinosaur& dino);

	const char* getName() const;
	Gender getGender() const;
	Era getEra() const;
	Species getSpecies() const;
	Type getType() const;
	Food getFood() const;

	void setUnknown();
};
