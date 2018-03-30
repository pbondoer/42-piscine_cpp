/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 20:52:17 by pbondoer          #+#    #+#             */
/*   Updated: 2018/03/30 23:39:06 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#include "SuperTrap.hpp"
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

SuperTrap::SuperTrap(const std::string name) :
	ClapTrap(name, 100, 100, 120, 120, 1, 60, 20, 5),
	FragTrap(name), NinjaTrap(name)
{
	std::cout << "<SUP3-TP> Hello, it's me!" << std::endl;
}

void SuperTrap::meleeAttack(std::string const & target)
{
	NinjaTrap::meleeAttack(target);
}

void SuperTrap::rangedAttack(std::string const & target)
{
	FragTrap::rangedAttack(target);
}


SuperTrap::SuperTrap(const SuperTrap &rhs) :
	FragTrap(rhs), NinjaTrap(rhs)
{
	std::cout << "<SUP3-TP> Hello, it's me!" << std::endl;
}

SuperTrap::~SuperTrap(void)
{
	std::cout << "<SUP3-TP> I'm dead!" << std::endl;
}
