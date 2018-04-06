/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Instruction.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 03:42:04 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/06 05:21:01 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTION_H
# define INSTRUCTION_H

# include "Container.hpp"

class Instruction
{
	public:
		Instruction(void);
		Instruction(Container *ptr);
		virtual ~Instruction(void) = 0;

		virtual void execute(void) = 0;
	protected:
		Container *_c;

};

#endif // INSTRUCTION_H
