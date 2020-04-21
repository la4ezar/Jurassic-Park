#include "Era.h"

std::ostream& operator<<(std::ostream& out, const Era& value) {
	switch (value) {
	case Triassic:
		out << "Triassic";
		break;
	case Jurassic:
		out << "Jurassic";
		break;
	case Cretaceous:
		out << "Cretaceous";
		break;
	default:
		out << "unknown_era";
	}
	return out;
}
