#include <iostream>
#include <ctime>
#include <cstdlib>
#include "JurassicPark.h"

void TestCage();
void TestDinosaurCompare();
void TestDinosaurUnknown();
void TestCageAdd();
void TestCageAddnRemove();
void TestJurrasicParkConstructor(JurassicPark& park);

int main() {
	srand(time(nullptr));
	JurassicPark park;

	//TestCage();
	//TestDinosaurCompare();
	//TestDinosaurUnknown();
	//TestCageAdd();
	//TestCageAddnRemove();
	//TestJurrasicParkConstructor(park);
	return 0;
}

void TestCage() {
	Cage cage1(3, terrestrial);
	std::cout << cage1.getDinosaursNum() << std::endl;
	cage1.addDinosaur("Luchozavur", Male, Jurassic, Tyrannosaurus, Carnivorous, Meat);
	cage1.addDinosaur("Goshozavur", Male, Jurassic, Plesiosaur, Carnivorous, Fish);
	cage1.addDinosaur("Qkozavur", Male, Jurassic, Tyrannosaurus, Carnivorous, Meat);
	std::cout << cage1.getDinosaursNum() << std::endl;
	Dinosaur* arr = cage1.getDinosaursArr();
	for (int i = 0; i < cage1.getSize(); ++i) {
		std::cout << arr[i].getName() << std::endl;
	}
	delete[] arr;

	cage1.removeDinosaur("Goshozavur", Male, Jurassic, Plesiosaur, Carnivorous, Fish);
	std::cout << cage1.getDinosaursNum() << std::endl;

	cage1.removeDinosaur("Ivanozavur", Male, Jurassic, Brontosaurus, Carnivorous, Meat);

	arr = cage1.getDinosaursArr();
	for (int i = 0; i < cage1.getSize(); ++i) {
		std::cout << arr[i].getName() << std::endl;
	}
	delete[] arr;

	cage1.addDinosaur("Krasizavur", Male, Jurassic, Plesiosaur, Carnivorous, Fish);
	std::cout << cage1.getDinosaursNum() << std::endl;
	
	arr = cage1.getDinosaursArr();
	for (int i = 0; i < cage1.getSize(); ++i) {
		std::cout << arr[i].getName() << std::endl;
	}

	for (int i = 0; i < cage1.getSize(); ++i) {
		cage1.removeDinosaur(arr[i]);
	}
	delete[] arr;

	arr = cage1.getDinosaursArr();
	for (int i = 0; i < cage1.getSize(); ++i) {
		std::cout << arr[i].getName() << std::endl;
	}

	std::cout << cage1.getDinosaursNum() << std::endl;

	delete[] arr;
	
}

void TestDinosaurCompare() {
	Dinosaur d1("Luchozavur", Male, Jurassic, Tyrannosaurus, Carnivorous, Meat);
	Dinosaur d2("Luchozavur", Male, Jurassic, Tyrannosaurus, Carnivorous, Meat);
	Dinosaur d3("Lucho", Male, Jurassic, Tyrannosaurus, Carnivorous, Meat);
	std::cout << (d1 == d2) << ' ' << (d2 == d3) << ' ' << (d1 == d3) << ' ' << (d2 == d1);
}

void TestDinosaurUnknown() {
	Dinosaur d1("Luchozavur", Male, Jurassic, Tyrannosaurus, Carnivorous, Meat);
	std::cout << d1 << std::endl;
	d1.setUnknown();
	std::cout << d1 << std::endl;
}

void TestCageAdd() {
	Cage cage1(3, terrestrial);
	cage1.addDinosaur("Luchozavur", Male, Jurassic, Pterodactyl, Flying, Meat);
	Dinosaur* arr = cage1.getDinosaursArr();
	std::cout << arr[0] << std::endl;
	delete[] arr;

	cage1.addDinosaur("Luchozavur", Male, Jurassic, Tyrannosaurus, Carnivorous, Meat);
	arr = cage1.getDinosaursArr();
	std::cout << arr[0] << std::endl;
	cage1.removeDinosaur(arr[0]);
	delete[] arr;

	Dinosaur d1("Luchozavur", Male, Jurassic, Triceratops, Carnivorous, Meat);
	cage1.addDinosaur(d1);
	arr = cage1.getDinosaursArr();
	std::cout << arr[0] << std::endl;
	delete[] arr;
}

void TestCageAddnRemove() {
	Cage cage1(3, air);
	cage1.addDinosaur("Luchozavur", Male, Jurassic, Pterodactyl, Flying, Meat);
	cage1.addDinosaur("Yavorozavur", Male, Jurassic, Pterodactyl, Flying, Meat);
	cage1.addDinosaur("Borkozavur", Male, Jurassic, Pterodactyl, Flying, Meat);
	Dinosaur* arr = cage1.getDinosaursArr();
	for (int i = 0; i < 3; ++i)
		std::cout << arr[i] << std::endl;
	std::cout << std::endl;
	cage1.removeDinosaur(arr[1]);
	delete[] arr;
	arr = cage1.getDinosaursArr();
	for (int i = 0; i < 3; ++i)
		std::cout << arr[i] << std::endl;;
	std::cout << std::endl;
	for (int i = 0; i < 3; ++i)
		cage1.removeDinosaur(arr[i]);
	delete[] arr;
	arr = cage1.getDinosaursArr();
	for (int i = 0; i < 3; ++i)
		std::cout << arr[i] << std::endl;;
	std::cout << std::endl;

}

void TestJurrasicParkConstructor(JurassicPark& park) {
	Cage* arr = park.getCages();
	int n = park.getCagesNum();
	for (int i = 0; i < n; ++i)
		std::cout << arr[i].getSize() << ' ' << arr[i].getClimate() << std::endl;
}