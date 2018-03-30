/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 20:52:17 by pbondoer          #+#    #+#             */
/*   Updated: 2018/03/29 23:35:03 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string name) :
	_name(name), _health(100), _maxHealth(100), _energy(100), _maxEnergy(100),
	_level(1), _meleeDmg(30), _rangedDmg(20), _armor(5)
{
	std::cout << "<FR4G-TP> Directive one: Protect humanity! Directive two: \
Obey Jack at all costs. Directive three: Dance!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &rhs) :
	_name(rhs._name), _health(rhs._health), _maxHealth(rhs._maxHealth),
	_energy(rhs._energy), _maxEnergy(rhs._maxEnergy), _level(rhs._level),
	_meleeDmg(rhs._meleeDmg), _rangedDmg(rhs._rangedDmg), _armor(rhs._armor)
{
	std::cout << "<FR4G-TP> Directive one: Protect humanity! Directive two: \
Obey Jack at all costs. Directive three: Dance!" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "<FR4G-TP> Argh arghargh death gurgle gurglegurgle urgh... \
death." << std::endl;
}

void FragTrap::rangedAttack(std::string const &target)
{
	std::cout << "<FR4G-TP> I'm Trap, Claptrap. Double oh... Trap." << std::endl;
	std::cout << " * " << this->_name << " inflicted " << this->_rangedDmg
		<< " ranged damage to " << target << std::endl;
}

void FragTrap::meleeAttack(std::string const &target)
{
	std::cout << "<FR4G-TP> Ready for the PUNCHline?!" << std::endl;
	std::cout << " * " << this->_name << " inflicted " << this->_meleeDmg
		<< " melee damage to " << target << std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
{
	std::cout << "<FR4G-TP> I'll die the way I lived: annoying!" << std::endl;

	if (amount >= this->_armor)
		amount -= this->_armor;
	else
		amount = 0;

	amount = std::min(amount, this->_health);

	std::cout << " * " << this->_name << " took " << amount << " damage"
		<< std::endl;

	if (this->_health >= amount)
		this->_health -= amount;
	else
		this->_health = 0;
}

void FragTrap::beRepaired(unsigned int amount)
{
	amount = std::min(amount, this->_maxHealth - this->_health);

	std::cout << "<FR4G-TP> Health! Eww, what flavor is red?" << std::endl;
	std::cout << " * " << this->_name << " was repaired for " << amount
		<< " health" << std::endl;

	this->_health += amount;
}

std::string FragTrap::_vaulthunterQuotes[25] = {
	"This time it'll be awesome, I promise!",
	"Hey everybody, check out my package!",
	"Place your bets!",
	"Defragmenting!",
	"Recompiling my combat code!",
	"Running the sequencer!",
	"It's happening... it's happening!",
	"It's about to get magical!",
	"I'm pulling tricks outta my hat!",
	"You can't just program this level of excitement!",
	"What will he do next?",
	"Things are about to get awesome!",
	"Let's get this party started!",
	"Glitchy weirdness is term of endearment, right?",
	"Push this button, flip this dongle, voila! Help me!",
	"square the I, carry the 1... YES!",
	"Resequencing combat protocols!",
	"Look out everybody, things are about to get awesome!",
	"I have an IDEA!",
	"Round and around and around she goes!",
	"It's like a box of chocolates...",
	"Step right up to the sequence of Trapping!",
	"Hey everybody, check out my package!",
	"Loading combat packages!",
	"F to the R to the 4 to the G to the WHAAT!"
};

void FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	if (this->_energy < 25)
	{
		std::cout << "<FR4G-TP> Does this mean I can start dancing? \
Pleeeeeeaaaaase?" << std::endl;
		std::cout << " * Out of energy" << std::endl;
		return;
	}
	this->_energy -= 25;
	std::cout << "<FR4G-TP> " << FragTrap::_vaulthunterQuotes[std::rand() % 25]
		<< std::endl;
	std::cout << " * Used vaulthunter.exe on " << target << std::endl;
}
