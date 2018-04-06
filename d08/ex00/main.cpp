/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 23:32:42 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/05 23:42:34 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include <set>

#include "easyfind.hpp"

int main(void)
{
	std::set<int> s;

	for (int i = 1; i <= 10; i++)
		s.insert(i);


	// confirm that it works
	for (int i = -10; i <= 20; i++)
	{
		try
		{
			std::cout << easyfind(s, i) << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "couldn't find " << i << std::endl;
		}
	}
}
