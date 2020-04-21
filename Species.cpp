#include "Speciesh.h"

std::ostream& operator<<(std::ostream& out, const Species& value) {
	switch (value) {
	case Plesiosaur:
		out << "Plesiosaur";
		break;
	case Tyrannosaurus:
		out << "Tyrannosaurus";
		break;
	case Brontosaurus:
		out << "Brontosaurus";
		break;
	case Triceratops:
		out << "Triceratops";
		break;
	case Stegosaurus:
		out << "Stegosaurus";
		break;
	case Velociraptor:
		out << "Velociraptor";
		break;
	case Pterodactyl:
		out << "Pterodactyl";
		break;
	default:
		out << "unknown_species";
	}
	return out;
}
