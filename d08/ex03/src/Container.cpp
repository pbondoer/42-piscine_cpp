/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Container.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 04:10:09 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/06 06:50:41 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Container.hpp"

const int Container::_size = 128 * 1024;

Container::Container(void) :
	_memory(new char[Container::_size]()),
	_position(0)
{}
Container::Container(Container const &obj) { *this = obj; }
Container::~Container(void) { delete [] this->_memory; }

char *Container::get(void)
{
	return this->_memory + this->_position;
}

void Container::add(void) { *this->get() += 1; }
void Container::sub(void) { *this->get() -= 1; }
void Container::addPos(void)
{
	this->_position++;

	if (this->_position >= Container::_size)
		this->_position = 0;
}
void Container::subPos(void)
{
	this->_position--;

	if (this->_position < 0)
		this->_position = Container::_size - 1;

}
void Container::display(void) { std::cout << *this->get(); std::cout.flush(); }
void Container::input(void) { std::cin >> *this->get(); }

Container const &Container::operator=(Container const &obj)
{
	if (this == &obj)
		return *this;

	*this->_memory = *obj._memory;

	return *this;
}
