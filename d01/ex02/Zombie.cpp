/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 16:37:12 by pbondoer          #+#    #+#             */
/*   Updated: 2018/03/27 18:53:56 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#include "Zombie.hpp"

Zombie::Zombie(std::string name, std::string type) : _name(name), _type(type)
{
	this->announce();
}

Zombie::~Zombie(void)
{
	std::cout << "<" << this->_name << " (" << this->_type
		<< ")> The sunlight, it burns!" << std::endl;
}

void Zombie::announce(void) const
{
	std::cout << "<" << this->_name << " (" << this->_type
		<< ")> Braiiiiiiinssss..." << std::endl;
}

std::string Zombie::getName(void) const
{
	return this->_name;
}

std::string Zombie::getType(void) const
{
	return this->_type;
}
