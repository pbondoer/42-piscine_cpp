/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Token.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 08:06:43 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/06 10:35:11 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept>
#include <ostream>
#include <sstream>

#include "Token.hpp"

Token::Token(void) : _type(NONE), _value(0) {}
Token::Token(int n) : _type(NUMBER), _value(n) {}
Token::Token(char c) : _value(c)
{
	if (c == '+' || c == '-' || c == '/' || c == '*')
		this->_type = OPERATION;
	else if (c == '(')
		this->_type = PAR_OPEN;
	else if (c == ')')
		this->_type = PAR_CLOSE;
	else
		throw std::runtime_error("Invalid token");
}
Token::Token(Token const &obj) { *this = obj; }
Token::~Token(void) {}

int Token::getValue(void) const
{
	return this->_value;
}

Token::Type Token::getType(void) const
{
	return this->_type;
}

Token const &Token::operator=(Token const &obj)
{
	if (this == &obj)
		return *this;

	this->_type = obj._type;
	this->_value = obj._value;

	return *this;
}

std::string Token::toString(void) const
{
	std::stringstream o;

	if (this->_type == Token::NUMBER)
		o << "Num(" << this->_value << ")";
	else if (this->_type == Token::OPERATION)
		o << "Op(" << static_cast<char>(this->_value) << ")";
	else if (this->_type == Token::PAR_OPEN)
		o << "ParOpen";
	else if (this->_type == Token::PAR_CLOSE)
		o << "ParClose";
	else
		o << "None";

	return o.str();
}

std::ostream &operator<<(std::ostream &o, Token const &t)
{
	o << t.toString();
	return o;
}
