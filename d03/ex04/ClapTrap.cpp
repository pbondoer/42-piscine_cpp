/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 20:52:17 by pbondoer          #+#    #+#             */
/*   Updated: 2018/03/30 15:15:09 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << "<CL4P-TP> We CL4P-TP units can be programmed to do anything \
from open doors to ninja-sassinate highly important Janitory officals!"
		<< std::endl;
}

ClapTrap::ClapTrap(const std::string name, unsigned int health,
		unsigned int maxHealth, unsigned int energy, unsigned int maxEnergy,
		unsigned int level, unsigned int meleeDmg, unsigned int rangedDmg,
		unsigned int armor) :
	_name(name), _health(health), _maxHealth(maxHealth), _energy(energy),
	_maxEnergy(maxEnergy), _level(level), _meleeDmg(meleeDmg),
	_rangedDmg(rangedDmg), _armor(armor)
{
	std::cout << "<CL4P-TP> We CL4P-TP units can be programmed to do anything \
from open doors to ninja-sassinate highly important Janitory officals!"
		<< std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &rhs) :
	_name(rhs._name), _health(rhs._health), _maxHealth(rhs._maxHealth),
	_energy(rhs._energy), _maxEnergy(rhs._maxEnergy), _level(rhs._level),
	_meleeDmg(rhs._meleeDmg), _rangedDmg(rhs._rangedDmg), _armor(rhs._armor)
{
	std::cout << "<CL4P-TP> We CL4P-TP units can be programmed to do anything \
from open doors to ninja-sassinate highly important Janitory officals!"
		<< std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "<CL4P-TP> I'M DEAD I'M DEAD OHMYGOD I'M DEAD!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "<CL4P-TP> I'll die the way I lived: annoying!" << std::endl;

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

std::string ClapTrap::getName(void) const
{
	return this->_name;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	amount = std::min(amount, this->_maxHealth - this->_health);

	std::cout << "<CL4P-TP> Health! Eww, what flavor is red?" << std::endl;
	std::cout << " * " << this->_name << " was repaired for " << amount
		<< " health" << std::endl;

	this->_health += amount;
}
