


#include "ClapTrap.hpp"

int main() {
    ClapTrap clapTrap("CT-01");

    clapTrap.attack("target1");
    clapTrap.takeDamage(5);
	std::cout << "Energy points: " << clapTrap.getEnergyPoints() << std::endl;
	std::cout << "Hit points: " << clapTrap.getHitPoints() << std::endl;
    clapTrap.beRepaired(3);
	std::cout << "Energy points: " << clapTrap.getEnergyPoints() << std::endl;
	std::cout << "Hit points: " << clapTrap.getHitPoints() << std::endl;
    clapTrap.attack("target2");

    return 0;
}
