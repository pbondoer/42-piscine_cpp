/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 22:00:58 by pbondoer          #+#    #+#             */
/*   Updated: 2018/03/27 22:04:59 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <sstream>

#include "Brain.hpp"

Brain::Brain(void) {}
Brain::~Brain(void) {}

std::string Brain::identify(void) const
{
	std::stringstream ss;
	ss << (void *)this;
	return ss.str();
}
