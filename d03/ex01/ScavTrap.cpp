/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 20:52:17 by pbondoer          #+#    #+#             */
/*   Updated: 2018/03/29 23:48:37 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string name) :
	_name(name), _health(100), _maxHealth(100), _energy(50), _maxEnergy(50),
	_level(1), _meleeDmg(20), _rangedDmg(15), _armor(3)
{
	std::cout << "<SC4V-TP> I once started a revolution myself. There were \
lots of guns and a lot of dying. You'd think I would have gotten some better \
benefits out of the whole thing but no, demoted back to door-opening \
servitude!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &rhs) :
	_name(rhs._name), _health(rhs._health), _maxHealth(rhs._maxHealth),
	_energy(rhs._energy), _maxEnergy(rhs._maxEnergy), _level(rhs._level),
	_meleeDmg(rhs._meleeDmg), _rangedDmg(rhs._rangedDmg), _armor(rhs._armor)
{
	std::cout << "<SC4V-TP> I once started a revolution myself. There were \
lots of guns and a lot of dying. You'd think I would have gotten some better \
benefits out of the whole thing but no, demoted back to door-opening \
servitude!" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "<SC4V-TP> Crap happens." << std::endl;
}

void ScavTrap::rangedAttack(std::string const &target)
{
	std::cout << "<SC4V-TP> Chk-chk, BOOM!" << std::endl;
	std::cout << " * " << this->_name << " inflicted " << this->_rangedDmg
		<< " ranged damage to " << target << std::endl;
}

void ScavTrap::meleeAttack(std::string const &target)
{
	std::cout << "<SC4V-TP> Meet professor punch!" << std::endl;
	std::cout << " * " << this->_name << " inflicted " << this->_meleeDmg
		<< " melee damage to " << target << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
	std::cout << "<SC4V-TP> I'm too pretty to die!" << std::endl;

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

void ScavTrap::beRepaired(unsigned int amount)
{
	amount = std::min(amount, this->_maxHealth - this->_health);

	std::cout << "<SC4V-TP> Sweet life juice!" << std::endl;
	std::cout << " * " << this->_name << " was repaired for " << amount
		<< " health" << std::endl;

	this->_health += amount;
}

std::string ScavTrap::_challenges[5] = {
	"Hello, newcomer! Find me a lemon, and this door shall be yours.",
	"Is the cake a lie?",
	"Tell me a joke, and maybe I'll consider opening. Wait, that's a great joke!",
	"I'm SC4V-TP. I won't let you go through, unless you solve my riddle.",
	"Fetch me a mojito, and I'll call quits on this one."
};

void ScavTrap::challengeNewcomer(std::string const & target)
{
	std::cout << "<SC4V-TP> " << ScavTrap::_challenges[std::rand() % 5]
		<< std::endl;
	std::cout << " * Challenged " << target << std::endl;
}
