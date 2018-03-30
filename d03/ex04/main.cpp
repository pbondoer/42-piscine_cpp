/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 20:52:18 by pbondoer          #+#    #+#             */
/*   Updated: 2018/03/30 15:40:48 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

int main(void)
{
	{
		FragTrap ft("FR4GGY");

		for (int i = 0; i < 7; i++)
			ft.takeDamage(20);

		for (int i = 0; i < 7; i++)
			ft.beRepaired(20);

		ft.rangedAttack("alice");
		ft.meleeAttack("bob");

		for (int i = 0; i < 10; i++)
			ft.vaulthunter_dot_exe("GLADOS");

		ScavTrap st("SCAVVY");

		for (int i = 0; i < 7; i++)
			st.takeDamage(20);

		for (int i = 0; i < 7; i++)
			st.beRepaired(20);

		st.rangedAttack("bobby");
		st.meleeAttack("john");

		for (int i = 0; i < 5; i++)
			st.challengeNewcomer("kenny");

		NinjaTrap n("NINJA");

		for (int i = 0; i < 7; i++)
			n.takeDamage(20);

		for (int i = 0; i < 7; i++)
			n.beRepaired(20);

		n.ninjaShoebox(n);
		n.ninjaShoebox(ft);
		n.ninjaShoebox(st);

		ClapTrap t("hi", 10, 10, 10, 10, 1, 10, 10, 10);
		n.ninjaShoebox(t);
	}

	{
		std::cout << std::endl;
		SuperTrap s("hello");

		s.rangedAttack("hello");
		s.meleeAttack("hello");
	}
}
