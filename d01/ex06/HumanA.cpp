/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 22:23:54 by pbondoer          #+#    #+#             */
/*   Updated: 2018/03/27 22:34:15 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string name, Weapon &w) : _name(name), _weapon(w) {}
HumanA::~HumanA(void) {}

void HumanA::attack(void) const
{
	std::cout << this->_name << " attacks with his " << this->_weapon.getType()
		<< std::endl;
}
