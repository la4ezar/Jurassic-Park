#pragma once

class Warehouse {
	int food;

public:
	Warehouse();  //default tons of food

	void getFood() const;

	void reloading();
	void resize();
};