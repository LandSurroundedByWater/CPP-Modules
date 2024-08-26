


#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
   ;
    ScavTrap scavTrap("ST-01");
    

    scavTrap.attack("target3");
    scavTrap.takeDamage(8);
    std::cout << "Energy points: " << scavTrap.getEnergyPoints() << std::endl;
	std::cout << "Hit points: " << scavTrap.getHitPoints() << std::endl;
    scavTrap.beRepaired(5);
    std::cout << "Energy points: " << scavTrap.getEnergyPoints() << std::endl;
	std::cout << "Hit points: " << scavTrap.getHitPoints() << std::endl;
    scavTrap.guardGate();
    // freeing ansa
    return 0;
}

