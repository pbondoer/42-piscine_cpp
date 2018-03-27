/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 16:40:48 by pbondoer          #+#    #+#             */
/*   Updated: 2018/03/27 19:20:19 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <string>

#include "Zombie.hpp"
#include "ZombieHorde.hpp"


ZombieHorde::ZombieHorde(int n) : _count(n)
{
	this->_zombies = new Zombie[n];

	for (int i = 0; i < n; i++)
	{
		_zombies[i].setType(ZombieHorde::_types[std::rand() % TYPE_COUNT]);
		_zombies[i].setName(ZombieHorde::_names[std::rand() % NAME_COUNT]);
	}
};

ZombieHorde::~ZombieHorde(void)
{
	delete [] this->_zombies;
};

void ZombieHorde::announce(void) const
{
	for (int i = 0; i < this->_count; i++)
		_zombies[i].announce();
}

std::string ZombieHorde::_types[TYPE_COUNT] = {
	"undead",
	"crazy",
	"runner",
	"boomer",
};

std::string ZombieHorde::_names[NAME_COUNT] = {
	"McZombie",
	"Brainiac",
	"David the Zombie",
	"Alice the Zombie",
	"Bob the Zombie Builder"
};
