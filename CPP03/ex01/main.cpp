


#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ClapTrap clapTrap("CT-01");

    //testing difference of stack and heap
    // ansa is allocated to heap
    ClapTrap* ansa = new ClapTrap("ansa");
    ansa->attack("CT-01");
    ScavTrap scavTrap("ST-01");
    

    clapTrap.attack("target1");
    clapTrap.takeDamage(5);
    clapTrap.beRepaired(3);
    clapTrap.attack("target2");

    scavTrap.attack("target3");
    scavTrap.takeDamage(8);
    std::cout << "Energy points: " << scavTrap.getEnergyPoints() << std::endl;
	std::cout << "Hit points: " << scavTrap.getHitPoints() << std::endl;
    scavTrap.beRepaired(5);
    std::cout << "Energy points: " << scavTrap.getEnergyPoints() << std::endl;
	std::cout << "Hit points: " << scavTrap.getHitPoints() << std::endl;
    scavTrap.guardGate();
    // freeing ansa
    delete(ansa);
    return 0;
}

