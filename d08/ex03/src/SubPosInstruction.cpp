/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SubPosInstruction.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 05:07:23 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/06 05:25:03 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SubPosInstruction.hpp"
#include "Instruction.hpp"
#include "Container.hpp"

SubPosInstruction::SubPosInstruction(Container *c) : Instruction(c) {}
SubPosInstruction::SubPosInstruction(SubPosInstruction const &obj)
{
	*this = obj;
}
SubPosInstruction::~SubPosInstruction(void) {}

SubPosInstruction const &SubPosInstruction::operator=(SubPosInstruction const &obj)
{
	if (this == &obj)
		return *this;

	this->_c = obj._c;

	return *this;
}

void SubPosInstruction::execute(void)
{
	_c->subPos();
}
