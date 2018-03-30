/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 20:52:17 by pbondoer          #+#    #+#             */
/*   Updated: 2018/03/30 15:14:25 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap(const std::string name) : 
	ClapTrap(name, 100, 100, 50, 50, 1, 20, 15, 3)
{
	std::cout << "<SC4V-TP> I once started a revolution myself. There were \
lots of guns and a lot of dying. You'd think I would have gotten some better \
benefits out of the whole thing but no, demoted back to door-opening \
servitude!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &rhs) :
	ClapTrap(rhs)
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
