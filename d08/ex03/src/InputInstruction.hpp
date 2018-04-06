/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InputInstruction.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 03:54:50 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/06 05:27:17 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUTINSTRUCTION_H
# define INPUTINSTRUCTION_H

# include "Instruction.hpp"
# include "Container.hpp"

class InputInstruction : public Instruction
{
	public:
		InputInstruction(Container *c);
		InputInstruction(InputInstruction const &obj);
		~InputInstruction(void);

		InputInstruction const &operator=(InputInstruction const &obj);

		void execute(void);
};

#endif // INPUTINSTRUCTION_H
