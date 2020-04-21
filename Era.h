#pragma once
#include <iostream>

enum Era {
	Triassic,
	Jurassic,
	Cretaceous,
	unknown_era
};
std::ostream& operator<<(std::ostream& out, const Era& value);
