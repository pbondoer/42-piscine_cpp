/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InputInstruction.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 05:07:23 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/06 05:28:33 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "InputInstruction.hpp"
#include "Instruction.hpp"
#include "Container.hpp"

InputInstruction::InputInstruction(Container *c) : Instruction(c) {}
InputInstruction::InputInstruction(InputInstruction const &obj)
{
	*this = obj;
}
InputInstruction::~InputInstruction(void) {}

InputInstruction const &InputInstruction::operator=(InputInstruction const &obj)
{
	if (this == &obj)
		return *this;

	this->_c = obj._c;

	return *this;
}

void InputInstruction::execute(void)
{
	_c->input();
}
