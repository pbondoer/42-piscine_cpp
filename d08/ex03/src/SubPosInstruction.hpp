/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SubPosInstruction.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 03:54:50 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/06 05:25:15 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUBPOSINSTRUCTION_H
# define SUBPOSINSTRUCTION_H

# include "Instruction.hpp"
# include "Container.hpp"

class SubPosInstruction : public Instruction
{
	public:
		SubPosInstruction(Container *c);
		SubPosInstruction(SubPosInstruction const &obj);
		~SubPosInstruction(void);

		SubPosInstruction const &operator=(SubPosInstruction const &obj);

		void execute(void);
};

#endif // SUBPOSINSTRUCTION_H
