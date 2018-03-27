/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 18:27:36 by pbondoer          #+#    #+#             */
/*   Updated: 2018/03/27 19:20:32 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#include "Zombie.hpp"
#include "ZombieHorde.hpp"

int main(void)
{
	ZombieHorde horde = ZombieHorde(42);

	horde.announce();
}
