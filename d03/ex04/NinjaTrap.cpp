/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 20:52:17 by pbondoer          #+#    #+#             */
/*   Updated: 2018/03/30 17:32:33 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#include "NinjaTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

NinjaTrap::NinjaTrap(const std::string name) :
	ClapTrap(name, 60, 60, 120, 120, 1, 60, 5, 0)
{ std::cout << "<N1NJ-TP> Nin." << std::endl; } 
NinjaTrap::NinjaTrap(const NinjaTrap &rhs) :
	ClapTrap(rhs)
{
	std::cout << "<N1NJ-TP> ...ja." << std::endl;
}

NinjaTrap::~NinjaTrap(void)
{
	std::cout << "<N1NJ-TP> Ugh." << std::endl;
}

void NinjaTrap::rangedAttack(std::string const &target)
{
	std::cout << "<N1NJ-TP> Pew pew!" << std::endl;
	std::cout << " * " << this->_name << " inflicted " << this->_rangedDmg
		<< " ranged damage to " << target << std::endl;
}

void NinjaTrap::meleeAttack(std::string const &target)
{
	std::cout << "<N1NJ-TP> NINJAAAAAA!" << std::endl;
	std::cout << " * " << this->_name << " inflicted " << this->_meleeDmg
		<< " melee damage to " << target << std::endl;
}

void NinjaTrap::ninjaShoebox(NinjaTrap & target)
{
	std::cout << "<N1NJ-TP> Oh! Another ninja!" << std::endl;
	std::cout << " * Shoeboxing " << target.getName() << "." << std::endl;
}
void NinjaTrap::ninjaShoebox(ClapTrap & target)
{
	std::cout << "<N1NJ-TP> Mmmm... CL4P-TP, we meet again..." << std::endl;
	std::cout << " * Shoeboxing " << target.getName() << "." << std::endl;
}
void NinjaTrap::ninjaShoebox(FragTrap & target)
{
	std::cout << "<N1NJ-TP> Ah, you must be the famous FR4G-TP!" << std::endl;
	std::cout << " * Shoeboxing " << target.getName() << "." << std::endl;
}
void NinjaTrap::ninjaShoebox(ScavTrap & target)
{
	std::cout << "<N1NJ-TP> Can you even fight? You're a glorified butler."
		<< std::endl;
	std::cout << " * Shoeboxing " << target.getName() << "." << std::endl;
}
