


#include "ClapTrap.hpp"

int main() {
	ClapTrap clapTrap("CT-01");

	clapTrap.attack("C-3PO");
	clapTrap.takeDamage(5);
	std::cout << "Energy points: " << clapTrap.getEnergyPoints() << std::endl;
	std::cout << "Hit points: " << clapTrap.getHitPoints() << std::endl;
	clapTrap.beRepaired(3);
	std::cout << "Energy points: " << clapTrap.getEnergyPoints() << std::endl;
	std::cout << "Hit points: " << clapTrap.getHitPoints() << std::endl;
	clapTrap.setEnergyPoints(0);
	std::cout << "Energy points: " << clapTrap.getEnergyPoints() << std::endl;
	std::cout << "Hit points: " << clapTrap.getHitPoints() << std::endl;
	clapTrap.beRepaired(4);
	clapTrap.setEnergyPoints(10);
	clapTrap.attack("R2D2");
	clapTrap.setHitPoints(0);
	clapTrap.attack("Luke Skywalker");
	clapTrap.setHitPoints(10);
	clapTrap.attack("Luke Skywalker");
	return 0;
}
