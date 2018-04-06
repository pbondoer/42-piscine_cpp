/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SubInstruction.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 03:54:50 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/06 05:22:48 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUBINSTRUCTION_H
# define SUBINSTRUCTION_H

# include "Instruction.hpp"
# include "Container.hpp"

class SubInstruction : public Instruction
{
	public:
		SubInstruction(Container *c);
		SubInstruction(SubInstruction const &obj);
		~SubInstruction(void);

		SubInstruction const &operator=(SubInstruction const &obj);

		void execute(void);
};

#endif // SUBINSTRUCTION_H
