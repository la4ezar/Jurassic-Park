#include "Climate.h"

std::ostream& operator<<(std::ostream& out, const Climate& value) {
	switch (value) {
	case terrestrial:
		out << "terrestrial";
		break;
	case air:
		out << "air";
		break;
	case aqueous:
		out << "aqueous";
		break;
	default:
		out << "unknown_climate";
	}
	return out;
}