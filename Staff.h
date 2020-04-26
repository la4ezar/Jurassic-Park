#pragma once

class Staff {
	int staff;

public:
	Staff(int staff = 0);

	int getStaff() const;

	void resize(int new_people);
};