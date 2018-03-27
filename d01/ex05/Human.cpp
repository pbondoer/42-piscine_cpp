/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 22:07:26 by pbondoer          #+#    #+#             */
/*   Updated: 2018/03/27 22:15:05 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"
#include "Brain.hpp"

Human::Human(void) {}
Human::~Human(void) {}

const Brain &Human::getBrain(void) const
{
	return this->_brain;
}

std::string Human::identify(void) const
{
	return this->_brain.identify();
}
