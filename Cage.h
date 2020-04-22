#pragma once
#include "Dinosaur.h"
#include "Climate.h"

class Cage {
	unsigned size;
	Dinosaur* dinosaurs_arr;
	Climate climate;
	Era era;
	Type type;
	unsigned dinosaurs_num;

public:
	Cage();
	Cage(int size, Climate climate);
	Cage& operator=(const Cage& other);
	~Cage();

	bool isEmpty() const;
	bool isFull() const;
	bool isSuitable(Dinosaur& dino) const;
	int dinosaurPosition(const char* name, Gender gender, Era era, Species species, Type type, Food food) const;

	unsigned getDinosaursNum() const;
	unsigned getSize() const;
	Climate getClimate() const;
	Era getEra() const;
	Dinosaur* getDinosaursArr() const;

	void addDinosaur(const char* name, Gender gender, Era era, Species species, Type type, Food food);
	void removeDinosaur(const char* name, Gender gender, Era era, Species species, Type type, Food food);
	void addDinosaur(const Dinosaur other);
	void removeDinosaur(const Dinosaur other);
};