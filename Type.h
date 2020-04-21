#pragma once
#include <iostream>

enum Type {
	Herbivorous,
	Carnivorous,
	Flying,
	Watery,
	unknown_type
};
std::ostream& operator<<(std::ostream& out, const Type& value);
