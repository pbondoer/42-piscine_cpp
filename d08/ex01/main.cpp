/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 00:50:52 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/06 01:06:03 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "span.hpp"

int main(void)
{
	std::srand(time(0));

	Span sp = Span(10000);

	for (int i = 0; i < 10000; i++)
	{
		sp.addNumber(std::rand());
	}

	std::cout << "sp" << std::endl;
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	Span sp2 = Span(100);
	std::vector<int> v;

	for (int i = 0; i < 100; i++)
	{
		v.push_back(std::rand());
	}

	// push the vector
	sp2.addVector(v);

	std::cout << "sp2" << std::endl;
	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;

	// error checks:
	Span sp3 = Span(10);

	try
	{
		sp3.addVector(v);
	}
	catch (std::exception &e)
	{
		std::cout << "Can't push vector to span: input too large" << std::endl;
	}

	for (int i = 0; i < 20; i++)
	{
		try
		{
			sp3.addNumber(i);
			std::cout << i << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "can't push " << i << std::endl;
		}
	}
}
