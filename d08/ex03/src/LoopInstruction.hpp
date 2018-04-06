/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LoopInstruction.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 03:54:50 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/06 05:35:01 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOPINSTRUCTION_H
# define LOOPINSTRUCTION_H

# include "Instruction.hpp"
# include "Container.hpp"

# include <vector>

class LoopInstruction : public Instruction
{
	public:
		LoopInstruction(Container *c, std::vector<Instruction *> _v);
		LoopInstruction(LoopInstruction const &obj);
		~LoopInstruction(void);

		LoopInstruction const &operator=(LoopInstruction const &obj);

		void execute(void);
	private:
		std::vector<Instruction *> _v;
};

#endif // LOOPINSTRUCTION_H
