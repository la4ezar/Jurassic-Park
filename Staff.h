#pragma once

class Staff {
	int staff;

public:
	//Staff(); //default value for the staff
	Staff(int staff = 0);

	int getStaff() const;

	void resize(int new_people);
};