/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SubInstruction.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 05:07:23 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/06 06:07:51 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "SubInstruction.hpp"
#include "Instruction.hpp"
#include "Container.hpp"

SubInstruction::SubInstruction(Container *c) : Instruction(c) {}
SubInstruction::SubInstruction(SubInstruction const &obj)
{
	*this = obj;
}
SubInstruction::~SubInstruction(void) {}

SubInstruction const &SubInstruction::operator=(SubInstruction const &obj)
{
	if (this == &obj)
		return *this;

	this->_c = obj._c;

	return *this;
}

void SubInstruction::execute(void)
{
	_c->sub();
}
