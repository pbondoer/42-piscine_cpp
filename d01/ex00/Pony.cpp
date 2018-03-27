/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 16:06:19 by pbondoer          #+#    #+#             */
/*   Updated: 2018/03/27 16:23:14 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Pony.hpp"

Pony::Pony(std::string name) : _name(name), _isAmazing(true)
{
	std::cout << "Hey " << name << " :D" << std::endl;
}

Pony::~Pony(void)
{
	std::cout << "Sorry " << this->_name << " :(" << std::endl;
}

bool Pony::IsAmazing(void) const
{
	return this->_isAmazing;
}
