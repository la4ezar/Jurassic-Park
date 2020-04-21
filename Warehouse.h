#pragma once

class Warehouse {
	int food;
	int food_capacity;

public:
	Warehouse();  //default tons of food
	Warehouse(int food_capacity);

	int getFood() const;
	int getFoodCapacity() const;

	void reloading();
	void resize();
};