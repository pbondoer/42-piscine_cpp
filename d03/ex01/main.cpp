/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 20:52:18 by pbondoer          #+#    #+#             */
/*   Updated: 2018/03/29 23:48:58 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	FragTrap ft("FR4GGY");
	FragTrap ft2(ft);

	for (int i = 0; i < 7; i++)
		ft.takeDamage(20);

	for (int i = 0; i < 7; i++)
		ft.beRepaired(20);

	ft.rangedAttack("alice");
	ft.meleeAttack("bob");

	for (int i = 0; i < 10; i++)
		ft.vaulthunter_dot_exe("GLADOS");

	ScavTrap st("SCAVVY");
	ScavTrap st2(st);

	for (int i = 0; i < 7; i++)
		st.takeDamage(20);

	for (int i = 0; i < 7; i++)
		st.beRepaired(20);

	st.rangedAttack("bobby");
	st.meleeAttack("john");

	for (int i = 0; i < 5; i++)
		st.challengeNewcomer("kenny");
}
