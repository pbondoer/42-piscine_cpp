/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DisplayInstruction.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 03:54:50 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/06 05:27:17 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAYINSTRUCTION_H
# define DISPLAYINSTRUCTION_H

# include "Instruction.hpp"
# include "Container.hpp"

class DisplayInstruction : public Instruction
{
	public:
		DisplayInstruction(Container *c);
		DisplayInstruction(DisplayInstruction const &obj);
		~DisplayInstruction(void);

		DisplayInstruction const &operator=(DisplayInstruction const &obj);

		void execute(void);
};

#endif // DISPLAYINSTRUCTION_H
