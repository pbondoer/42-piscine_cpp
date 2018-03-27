/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 23:15:17 by pbondoer          #+#    #+#             */
/*   Updated: 2018/03/27 23:36:41 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#include "Human.hpp"

void Human::meleeAttack(std::string const &target)
{
	std::cout << "Melee attack -> " << target << std::endl;
}

void Human::rangedAttack(std::string const &target)
{
	std::cout << "Ranged attack -> " << target << std::endl;
}

void Human::intimidatingShout(std::string const &target)
{
	std::cout << "Intimidating shout -> " << target << std::endl;
}

typedef void(Human::* actionPtr) (std::string const &);

void Human::action(std::string const &action, std::string const &target)
{
	std::string names[3] = {
		"melee", "ranged", "shout"
	};

	actionPtr actions[3] = {
		&Human::meleeAttack,
		&Human::rangedAttack,
		&Human::intimidatingShout
	};

	for (int i = 0; i < 3; i++)
	{
		if (names[i].compare(action) == 0)
		{
			(this->*actions[i])(target);
		}
	}
}
