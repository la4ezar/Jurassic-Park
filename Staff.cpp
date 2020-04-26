#include "Staff.h"

Staff::Staff(int staff): staff(staff) {}

int Staff::getStaff() const {
	return staff;
}

void Staff::resize(int new_people) {
	staff += new_people;
}