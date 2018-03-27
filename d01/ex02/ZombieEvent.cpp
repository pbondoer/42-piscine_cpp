/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 16:40:48 by pbondoer          #+#    #+#             */
/*   Updated: 2018/03/27 18:54:13 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <string>

#include "Zombie.hpp"
#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent(void) {};
ZombieEvent::~ZombieEvent(void) {};

std::string ZombieEvent::_names[5] = {
	"McZombie",
	"Brainiac",
	"David the Zombie",
	"Alice the Zombie",
	"Bob the Zombie Builder"
};

void ZombieEvent::setZombieType(std::string type)
{
	this->_type = type;
}

Zombie *ZombieEvent::newZombie(std::string name) const
{
	return new Zombie(name, this->_type);
}

void	ZombieEvent::randomChump(void) const
{
	Zombie z = Zombie(ZombieEvent::_names[std::rand() % 5], this->_type);
}
