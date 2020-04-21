#include "Type.h"

std::ostream& operator<<(std::ostream& out, const Type& value) {
	switch (value) {
	case Herbivorous:
		out << "Herbivorous";
		break;
	case Carnivorous:
		out << "Carnivorous";
		break;
	case Flying:
		out << "Flying";
		break;
	case Watery:
		out << "Watery";
		break;
	default:
		out << "unknown_type";
	}
	return out;
}
