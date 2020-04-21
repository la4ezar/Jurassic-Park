#pragma once
#include <iostream>

enum Gender {
	Male,
	Female,
	unknown_gender
};
std::ostream& operator<<(std::ostream& out, const Gender& value);