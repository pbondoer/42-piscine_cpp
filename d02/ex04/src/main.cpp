/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 00:38:24 by pbondoer          #+#    #+#             */
/*   Updated: 2018/03/29 01:32:22 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <string>

#include "Fixed.hpp"
#include "main.hpp"

Fixed	parse_number(std::string s, int &pos)
{
	Fixed nbr;

	while (s.at(pos) == ' ')
		pos++;

	if (s.at(pos) == '(')
	{
		pos++;
		nbr = parse_sum(s, pos);
		if (s.at(pos) == ')')
			pos++;
		return (nbr);
	}


	std::stringstream ss(s.substr(pos));
	float result;

	ss >> result;
	pos += ss.tellg();
	return (Fixed(result));
}

Fixed	parse_factors(std::string s, int &pos)
{
	Fixed	nbr;
	Fixed	nbr2;
	char	op;

	nbr = parse_number(s, pos);
	while ((size_t)pos < s.size())
	{
		while (s.at(pos) == ' ')
			pos++;

		op = s.at(pos);
		if (op != '/' && op != '*')
			return (nbr);

		pos++;
		nbr2 = parse_number(s, pos);

		if (op == '/')
			nbr = nbr / nbr2;
		else if (op == '*')
			nbr = nbr * nbr2;
	}
	return (nbr);
}

Fixed	parse_sum(std::string s, int &pos)
{
	Fixed	nbr;
	Fixed	nbr2;
	char	op;

	nbr = parse_factors(s, pos);

	while ((size_t)pos < s.size())
	{
		while (s.at(pos) == ' ')
			pos++;

		op = s.at(pos);
		if (op != '+' && op != '-')
			return (nbr);

		pos++;
		nbr2 = parse_factors(s, pos);

		if (op == '+')
			nbr = nbr + nbr2;
		else
			nbr = nbr - nbr2;
	}
	return (nbr);
}

int		main(int argc, char **argv)
{
	if (argc <= 1)
	{
		std::cout << "Usage: ./eval_expr (expression)" << std::endl;
		return (0);
	}

	int pos = 0;
	std::cout << parse_sum(argv[1], pos) << std::endl;
	return (0);
}
