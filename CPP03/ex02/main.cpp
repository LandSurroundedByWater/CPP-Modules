


#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    ClapTrap clapTrap("CT-01");

    //testing difference of stack and heap
    // ansa is allocated to heap
    ClapTrap* ansa = new ClapTrap("ansa");
    ansa->attack("CT-01");

    
    ScavTrap scavTrap("ST-01");
    FragTrap fragTrap("FT-01");
    

    clapTrap.attack("target1");
    clapTrap.takeDamage(5);
    clapTrap.beRepaired(3);
    clapTrap.attack("target2");

    scavTrap.attack("target3");
    scavTrap.takeDamage(8);
    std::cout << scavTrap.getName() << "Energy points: " << scavTrap.getEnergyPoints() << std::endl;
    std::cout << scavTrap.getName() << "Hit points: " << scavTrap.getHitPoints() << std::endl;
    scavTrap.beRepaired(5);
    std::cout << scavTrap.getName() << "Energy points: " << scavTrap.getEnergyPoints() << std::endl;
    std::cout << scavTrap.getName() << "Hit points: " << scavTrap.getHitPoints() << std::endl;
    scavTrap.guardGate();
    // freeing ansa

    fragTrap.attack("target4");
    std::cout << fragTrap.getName() << " Energy points: " << fragTrap.getEnergyPoints() << std::endl;
    std::cout << fragTrap.getName() << " Hit points: " << fragTrap.getHitPoints() << std::endl;

    fragTrap.takeDamage(10);        
    fragTrap.beRepaired(5);
    std::cout << fragTrap.getName() << " Energy points: " << fragTrap.getEnergyPoints() << std::endl;
    std::cout << fragTrap.getName() << " Hit points: " << fragTrap.getHitPoints() << std::endl;

    fragTrap.highFivesGuys();
    delete(ansa);
    return 0;
}

