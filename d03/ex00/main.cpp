/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 20:52:18 by pbondoer          #+#    #+#             */
/*   Updated: 2018/03/29 23:33:46 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

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
}
