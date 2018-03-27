/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 22:23:54 by pbondoer          #+#    #+#             */
/*   Updated: 2018/03/27 22:37:53 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name) : _name(name) {}
HumanB::~HumanB(void) {}

void HumanB::setWeapon(Weapon &w)
{
	this->_weapon = &w;
}

void HumanB::attack(void) const
{
	std::cout << this->_name << " attacks with his " << this->_weapon->getType()
		<< std::endl;
}
