#include "Food.h"

std::ostream& operator<<(std::ostream& out, const Food& value) {
	switch (value) {
	case Meat:
		out << "Meat";
		break;
	case Grass:
		out << "Grass";
		break;
	case Fish:
		out << "Fish";
		break;
	default:
		out << "unknown_food";
	}
	return out;
}
