#pragma once

class Warehouse {
	int food;
	int food_capacity;

public:
	Warehouse();
	Warehouse(int food_capacity);

	int getFood() const;
	int getFoodCapacity() const;

	void reloading();
	void resize(int dino_num);
};