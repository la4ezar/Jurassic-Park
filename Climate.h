#pragma once
#include <iostream>

enum Climate {
	terrestrial,
	aqueous,
	air,
	unknown_climate
};
std::ostream& operator<<(std::ostream& out, const Climate& value);
