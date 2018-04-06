/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LoopInstruction.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 05:07:23 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/06 06:33:18 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LoopInstruction.hpp"
#include "Instruction.hpp"
#include "Container.hpp"

#include <vector>

LoopInstruction::LoopInstruction(Container *c, std::vector<Instruction *> v) :
	Instruction(c), _v(v) {}
LoopInstruction::LoopInstruction(LoopInstruction const &obj)
{
	*this = obj;
}
LoopInstruction::~LoopInstruction(void) {}

LoopInstruction const &LoopInstruction::operator=(LoopInstruction const &obj)
{
	if (this == &obj)
		return *this;

	this->_c = obj._c;
	this->_v = obj._v;

	return *this;
}

void LoopInstruction::execute(void)
{
	if (*_c->get() == 0)
		return;

	for (std::vector<Instruction *>::iterator it = _v.begin();
			it != _v.end();
			it++)
	{
		(*it)->execute();
	}

	this->execute();
}
