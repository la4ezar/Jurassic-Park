#pragma once

class Staff {
	int staff;

public:
	Staff(); //default value for the staff
	Staff(int staff);

	int getStaff() const;

	void resize(int new_people);
};