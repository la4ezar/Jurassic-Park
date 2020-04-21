#pragma once
#include <iostream>

enum Food {
	Grass,
	Meat,
	Fish,
	unknown_food
};
std::ostream& operator<<(std::ostream& out, const Food& value);