/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 20:52:17 by pbondoer          #+#    #+#             */
/*   Updated: 2018/03/30 15:13:43 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap(const std::string name) :
	ClapTrap(name, 100, 100, 100, 100, 1, 30, 20, 5)
{
	std::cout << "<FR4G-TP> Directive one: Protect humanity! Directive two: \
Obey Jack at all costs. Directive three: Dance!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &rhs) :
	ClapTrap(rhs)
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
