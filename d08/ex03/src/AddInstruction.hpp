/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AddInstruction.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 03:54:50 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/06 05:21:58 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADDINSTRUCTION_H
# define ADDINSTRUCTION_H

# include "Instruction.hpp"
# include "Container.hpp"

class AddInstruction : public Instruction
{
	public:
		AddInstruction(Container *c);
		AddInstruction(AddInstruction const &obj);
		~AddInstruction(void);

		AddInstruction const &operator=(AddInstruction const &obj);

		void execute(void);
};

#endif // ADDINSTRUCTION_H
