/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AddPosInstruction.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 03:54:50 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/06 05:26:03 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADDPOSINSTRUCTION_H
# define ADDPOSINSTRUCTION_H

# include "Instruction.hpp"
# include "Container.hpp"

class AddPosInstruction : public Instruction
{
	public:
		AddPosInstruction(Container *c);
		AddPosInstruction(AddPosInstruction const &obj);
		~AddPosInstruction(void);

		AddPosInstruction const &operator=(AddPosInstruction const &obj);

		void execute(void);
};

#endif // ADDPOSINSTRUCTION_H
