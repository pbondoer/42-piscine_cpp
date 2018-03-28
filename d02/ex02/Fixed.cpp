/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 22:52:31 by pbondoer          #+#    #+#             */
/*   Updated: 2018/03/29 01:31:49 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::_fractionalBits = 8;

Fixed::Fixed(void) : _value(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const value)
{
	//std::cout << "Int constructor called" << std::endl;

	this->_value = value << Fixed::_fractionalBits;
}

Fixed::Fixed(float const value)
{
	//std::cout << "Float constructor called" << std::endl;

	this->_value = (int)roundf(value * (1 << Fixed::_fractionalBits));
}

Fixed::Fixed(Fixed const &src) : _value(src.getRawBits())
{
	//std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	//std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator=(Fixed const &rhs)
{
	this->_value = rhs.getRawBits();

	return *this;
}

bool Fixed::operator==(Fixed const &rhs) const
{
	return this->_value == rhs.getRawBits();
}

bool Fixed::operator!=(Fixed const &rhs) const
{
	return this->_value != rhs.getRawBits();
}

bool Fixed::operator<(Fixed const &rhs) const
{
	return this->_value < rhs.getRawBits();
}

bool Fixed::operator<=(Fixed const &rhs) const
{
	return this->_value <= rhs.getRawBits();
}

bool Fixed::operator>(Fixed const &rhs) const
{
	return this->_value > rhs.getRawBits();
}

bool Fixed::operator>=(Fixed const &rhs) const
{
	return this->_value >= rhs.getRawBits();
}

Fixed Fixed::operator+(Fixed const &rhs)
{
	Fixed f;

	f.setRawBits(this->_value + rhs.getRawBits());
	return f;
}

Fixed Fixed::operator-(Fixed const &rhs)
{
	Fixed f;

	f.setRawBits(this->_value - rhs.getRawBits());
	return f;
}

Fixed Fixed::operator*(Fixed const &rhs)
{
	Fixed f;

	f.setRawBits((this->_value * rhs.getRawBits()) >> Fixed::_fractionalBits);
	return f;
}

Fixed Fixed::operator/(Fixed const &rhs)
{
	Fixed f;

	f.setRawBits((this->_value << Fixed::_fractionalBits) / rhs.getRawBits());
	return f;
}

Fixed &Fixed::operator++(void)
{
	this->_value++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed &Fixed::operator--(void)
{
	this->_value--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return tmp;
}

int Fixed::getRawBits(void) const
{
	return this->_value;
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

int Fixed::toInt(void) const
{
	return this->_value >> Fixed::_fractionalBits;
}

float Fixed::toFloat(void) const
{
	return this->_value / (float)(1 << Fixed::_fractionalBits);
}

Fixed & Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

const Fixed & Fixed::min(Fixed const &a, Fixed const &b)
{
	return (a < b ? a : b);
}

Fixed & Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

const Fixed & Fixed::max(Fixed const &a, Fixed const &b)
{
	return (a > b ? a : b);
}

std::ostream &operator<<(std::ostream &o, Fixed const &rhs)
{
	o << rhs.toFloat();
	return o;
}
