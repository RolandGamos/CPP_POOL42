#include "Claptrap.hpp"

ClapTrap::ClapTrap(std::string name){
	std::cout << "The ClapTrap constructor of " << name << " has been called" << std::endl;
	_name = name;
	_Hitpoints = 10;
	_Energypoints = 10;
	_Attackdamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &src){
	_name = src._name;
	_Hitpoints = src._Hitpoints;
	_Energypoints = src._Energypoints;
	_Attackdamage = src._Attackdamage;
	std::cout << "The ClapTrap copy constructor of " << _name << " has been called" << std::endl;
}

ClapTrap::~ClapTrap(void){
	std::cout << "The ClapTrap destructor of " << _name << " has been called" << std::endl;
}

void	ClapTrap::setName(std::string name){
	_name = name;
}

void	ClapTrap::setHitpoints(int Hitpoints){
	_Hitpoints = Hitpoints;
}

void	ClapTrap::setEnergypoints(int Energypoints){
	_Energypoints = Energypoints;
}

void	ClapTrap::setAttackdamage(int Attackdamage){
	_Attackdamage = Attackdamage;
}

std::string	ClapTrap::getName(void) const{
	return (_name);
}

int	ClapTrap::getHitpoints(void) const{
	return (_Hitpoints);
}

int	ClapTrap::getEnergypoints(void) const{
	return (_Energypoints);
}

int	ClapTrap::getAttackdamage(void) const{
	return (_Attackdamage);
}

void	ClapTrap::attack(const std::string &target){
	std::cout <<  "ClapTrap " << _name << " attack " << target << ", causing " << _Attackdamage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount){
	std::cout <<  "ClapTrap " << _name << " take " << amount << " points of damage!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount){
	std::cout <<  "ClapTrap " << _name << " heal " << amount << " points of damage!" << std::endl;
}