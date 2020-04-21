#include "Gender.h"

std::ostream& operator<<(std::ostream& out, const Gender& value) {
	switch (value) {
	case Male:
		out << "Male";
		break;
	case Female:
		out << "Female";
		break;
	default:
		out << "unknown_gender";
	}
	return out;
}
