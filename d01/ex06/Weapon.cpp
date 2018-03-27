/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 22:18:03 by pbondoer          #+#    #+#             */
/*   Updated: 2018/03/27 22:19:49 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {}
Weapon::~Weapon(void) {}

const std::string Weapon::getType(void) const
{
	return this->_type;
}

void Weapon::setType(std::string type)
{
	this->_type = type;
}
