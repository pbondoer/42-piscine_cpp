/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 03:15:54 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/06 06:37:32 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <fstream>
#include <queue>
#include <typeinfo>

#include "Container.hpp"
#include "Instruction.hpp"
#include "AddInstruction.hpp"
#include "SubInstruction.hpp"
#include "AddPosInstruction.hpp"
#include "SubPosInstruction.hpp"
#include "LoopInstruction.hpp"
#include "DisplayInstruction.hpp"
#include "InputInstruction.hpp"

// ugly but it works
Container c;

template<typename T>
void parse_instructions(T &container, std::stringstream &s)
{
	(void)container;
	char cur;
	while (s.get(cur))
	{
		Instruction *i = NULL;
		std::vector<Instruction *> arr;

		switch(cur)
		{
			case 'a': // +
				i = new AddInstruction(&c);
				break;
			case 's': // -
				i = new SubInstruction(&c);
				break;
			case 'r': // >
				i = new AddPosInstruction(&c);
				break;
			case 'l': // <
				i = new SubPosInstruction(&c);
				break;
			case 'o': // [
				parse_instructions(arr, s);

				i = new LoopInstruction(&c, arr);
				break;
			case 'c': // ]
				return;
			case 'd': // .
				i = new DisplayInstruction(&c);
				break;
			case 'i': // ,
				i = new InputInstruction(&c);
				break;
		}

		if (i == NULL)
			continue;

		container.push_back(i);
	}
}

void mindopen(std::istream &input)
{
	std::stringstream s;
	s << input.rdbuf();

	// c::in control given back here
	std::vector<Instruction *> q;
	parse_instructions(q, s);

	// execute
	for (std::vector<Instruction *>::iterator it = q.begin();
			it != q.end();
			it++)
	{
		(*it)->execute();
	}
}

int main(int argc, char **argv)
{
	if (argc == 1)
		mindopen(std::cin);
	else
	{
		std::ifstream input(argv[1]);

		if (!input.good())
		{
			std::cerr << argv[0] << ": " << argv[1] << ": "
				<< strerror(errno) << std::endl;
		}

		mindopen(input);
	}

	return (0);
}
