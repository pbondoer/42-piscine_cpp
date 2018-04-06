/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AddPosInstruction.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 05:07:23 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/06 05:27:33 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AddPosInstruction.hpp"
#include "Instruction.hpp"
#include "Container.hpp"

AddPosInstruction::AddPosInstruction(Container *c) : Instruction(c) {}
AddPosInstruction::AddPosInstruction(AddPosInstruction const &obj)
{
	*this = obj;
}
AddPosInstruction::~AddPosInstruction(void) {}

AddPosInstruction const &AddPosInstruction::operator=(AddPosInstruction const &obj)
{
	if (this == &obj)
		return *this;

	this->_c = obj._c;

	return *this;
}

void AddPosInstruction::execute(void)
{
	_c->addPos();
}
