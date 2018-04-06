/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Instruction.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 05:09:10 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/06 05:24:17 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Instruction.hpp"

Instruction::Instruction(void) : _c(0) {}
Instruction::Instruction(Container *ptr) : _c(ptr) {}
Instruction::~Instruction(void) {}
