#pragma once
#include <iostream>

enum Species {
	Plesiosaur,
	Tyrannosaurus,
	Brontosaurus,
	Triceratops,
	Stegosaurus,
	Velociraptor,
	Pterodactyl,
	unknown_species
};
std::ostream& operator<<(std::ostream& out, const Species& value);
