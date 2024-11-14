


#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {

	std::cout << std::endl;
	std::cout << "----------creating ClapTrap CT-01-----------" << std::endl;
	std::cout << std::endl;
	ClapTrap clapTrap("CT-01");

	std::cout << std::endl;
	std::cout << "----------creating SravTraps ST-01 and Jack-----------" << std::endl;
	std::cout << std::endl;
	
	ScavTrap scavTrap("ST-01");
	ScavTrap Jack("Jack");

	std::cout << std::endl;
	std::cout << "----------copy constructor copies Jack to anotherJack-----------" << std::endl;
	std::cout << std::endl;

	ScavTrap anotherJack(Jack);

	std::cout << std::endl;
	std::cout << "----------copy assign operator from ST-01 to Jack-----------" << std::endl;
	std::cout << std::endl;

	Jack = scavTrap;

	std::cout << std::endl;
	std::cout << "----------creating Fragtrap FT-01-----------" << std::endl;
	std::cout << std::endl;
	
	FragTrap fragTrap("FT-01");
	
	std::cout << std::endl;
	std::cout << "----------testing methods-----------" << std::endl;
	std::cout << std::endl;

	clapTrap.attack("3-CPO");
	fragTrap.attack("3-CPO");
	clapTrap.takeDamage(5);
	clapTrap.beRepaired(3);
	std::cout << clapTrap.getName() << "Energy points: " << clapTrap.getEnergyPoints() << std::endl;
	std::cout << clapTrap.getName() << "Hit points: " << clapTrap.getHitPoints() << std::endl;
	clapTrap.attack("R2-D2");
	scavTrap.attack("Luke Skywalker");
	fragTrap.attack("R2-D2");
	
	std::cout << std::endl;
	std::cout << "----------more testing methods-----------" << std::endl;
	std::cout << std::endl;
	scavTrap.takeDamage(8);
	std::cout << scavTrap.getName() << "Energy points: " << scavTrap.getEnergyPoints() << std::endl;
	std::cout << scavTrap.getName() << "Hit points: " << scavTrap.getHitPoints() << std::endl;
	scavTrap.beRepaired(5);
	std::cout << scavTrap.getName() << "Energy points: " << scavTrap.getEnergyPoints() << std::endl;
	std::cout << scavTrap.getName() << "Hit points: " << scavTrap.getHitPoints() << std::endl;
	scavTrap.guardGate();
	fragTrap.attack("Princess Leia");
	std::cout << fragTrap.getName() << " Energy points: " << fragTrap.getEnergyPoints() << std::endl;
	std::cout << fragTrap.getName() << " Hit points: " << fragTrap.getHitPoints() << std::endl;
	
	std::cout << std::endl;
	std::cout << "----------moretesting methods-----------" << std::endl;
	std::cout << std::endl;
	fragTrap.takeDamage(10);        
	fragTrap.beRepaired(5);
	std::cout << fragTrap.getName() << " Energy points: " << fragTrap.getEnergyPoints() << std::endl;
	std::cout << fragTrap.getName() << " Hit points: " << fragTrap.getHitPoints() << std::endl;
	fragTrap.highFivesGuys();
	std::cout << std::endl;
	std::cout << "----------End of testing, destroy all-----------" << std::endl;
	std::cout << std::endl;
	return 0;
}

