#include "Warehouse.h"

Warehouse::Warehouse(): food(0), food_capacity(0) {}
Warehouse::Warehouse(int food_capacity): food(0), food_capacity(food_capacity) {}

int Warehouse::getFood() const {
	return food;
}

int Warehouse::getFoodCapacity() const {
	return food_capacity;
}

void Warehouse::reloading() {
	food = food_capacity;
}
void Warehouse::resize() {
	food_capacity += 10;
}