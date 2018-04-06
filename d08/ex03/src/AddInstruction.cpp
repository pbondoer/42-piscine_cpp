/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AddInstruction.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 05:07:23 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/06 06:00:42 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AddInstruction.hpp"
#include "Instruction.hpp"
#include "Container.hpp"

AddInstruction::AddInstruction(Container *c) : Instruction(c) {}
AddInstruction::AddInstruction(AddInstruction const &obj)
{
	*this = obj;
}
AddInstruction::~AddInstruction(void) {}

AddInstruction const &AddInstruction::operator=(AddInstruction const &obj)
{
	if (this == &obj)
		return *this;

	this->_c = obj._c;

	return *this;
}

void AddInstruction::execute(void)
{
	_c->add();
}
