/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 18:27:36 by pbondoer          #+#    #+#             */
/*   Updated: 2018/03/27 18:56:32 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int main(void)
{
	ZombieEvent event;

	event.setZombieType("undead");
	Zombie *zombie = event.newZombie("Zom-by");
	Zombie *zombie2 = event.newZombie("Billy the Zombie");

	event.setZombieType("chump");
	for (int i = 0; i < 10; i++)
		event.randomChump();

	delete zombie;
	delete zombie2;
}
