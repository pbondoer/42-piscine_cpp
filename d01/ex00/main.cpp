/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 16:06:22 by pbondoer          #+#    #+#             */
/*   Updated: 2018/03/27 16:21:12 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Pony.hpp"

void	ponyOnTheHeap(void)
{
	std::cout << "-- HEAP --" << std::endl;

	Pony *p = new Pony("David");

	if (p->IsAmazing())
	{
		std::cout << "Pony is amazing." << std::endl;
	}

	delete p;
}

void	ponyOnTheStack(void)
{
	std::cout << "-- STACK --" << std::endl;

	Pony p = Pony("Alice");

	if (p.IsAmazing())
	{
		std::cout << "Pony is amazing." << std::endl;
	}
}

int		main(void)
{
	ponyOnTheHeap();
	ponyOnTheStack();

	return (0);
}
