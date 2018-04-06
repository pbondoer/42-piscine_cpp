/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DisplayInstruction.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 05:07:23 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/06 05:27:46 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DisplayInstruction.hpp"
#include "Instruction.hpp"
#include "Container.hpp"

DisplayInstruction::DisplayInstruction(Container *c) : Instruction(c) {}
DisplayInstruction::DisplayInstruction(DisplayInstruction const &obj)
{
	*this = obj;
}
DisplayInstruction::~DisplayInstruction(void) {}

DisplayInstruction const &DisplayInstruction::operator=(DisplayInstruction const &obj)
{
	if (this == &obj)
		return *this;

	this->_c = obj._c;

	return *this;
}

void DisplayInstruction::execute(void)
{
	_c->display();
}
