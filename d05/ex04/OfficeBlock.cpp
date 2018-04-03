/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 00:12:42 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/03 06:54:32 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept>
#include <string>
#include <iostream>

#include "OfficeBlock.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

OfficeBlock::OfficeBlock(void) :
	_intern(NULL), _signer(NULL), _executor(NULL)
{};

OfficeBlock::OfficeBlock(Intern *i, Bureaucrat *s, Bureaucrat *e) :
	_intern(i), _signer(s), _executor(e)
{
	if (i == NULL || s == NULL || e == NULL)
		throw InvalidEntityException();
}

OfficeBlock::~OfficeBlock(void)
{}

Intern *OfficeBlock::getIntern(void) const
{
	return this->_intern;
}
Bureaucrat *OfficeBlock::getSigner(void) const
{
	return this->_signer;
}
Bureaucrat *OfficeBlock::getExecutor(void) const
{
	return this->_executor;
}

void OfficeBlock::setIntern(Intern *i)
{
	if (i == NULL)
		throw InvalidEntityException();

	this->_intern = i;
}
void OfficeBlock::setSigner(Bureaucrat *b)
{
	if (b == NULL)
		throw InvalidEntityException();

	this->_signer = b;
}
void OfficeBlock::setExecutor(Bureaucrat *b)
{
	if (b == NULL)
		throw InvalidEntityException();

	this->_executor = b;
}

void OfficeBlock::doBureaucracy(std::string type, std::string target)
{
	if (this->_intern == NULL)
		throw NoInternException();
	if (this->_signer == NULL)
		throw NoSignerException();
	if (this->_executor == NULL)
		throw NoExecutorException();

	Form *f = this->_intern->makeForm(type, target);

	if (f == NULL)
		throw InvalidEntityException();

	f->beSigned(*this->_signer);
	f->execute(*this->_executor);
}

// Exceptions
typedef OfficeBlock::InvalidEntityException InvalidEntityException;

InvalidEntityException::InvalidEntityException(void) {}

InvalidEntityException::InvalidEntityException(InvalidEntityException const &) {}

InvalidEntityException::~InvalidEntityException(void) throw() {}

InvalidEntityException &InvalidEntityException::operator=(
		InvalidEntityException const &
	)
{
	return *this;
}

const char *InvalidEntityException::what(void) const throw()
{
	return "Invalid entity";
}

typedef OfficeBlock::NoInternException NoInternException;

NoInternException::NoInternException(void) {}

NoInternException::NoInternException(NoInternException const &) {}

NoInternException::~NoInternException(void) throw() {}

NoInternException &NoInternException::operator=(
		NoInternException const &
	)
{
	return *this;
}

const char *NoInternException::what(void) const throw()
{
	return "No intern";
}

typedef OfficeBlock::NoSignerException NoSignerException;

NoSignerException::NoSignerException(void) {}

NoSignerException::NoSignerException(NoSignerException const &) {}

NoSignerException::~NoSignerException(void) throw() {}

NoSignerException &NoSignerException::operator=(
		NoSignerException const &
	)
{
	return *this;
}

const char *NoSignerException::what(void) const throw()
{
	return "No signer";
}

typedef OfficeBlock::NoExecutorException NoExecutorException;

NoExecutorException::NoExecutorException(void) {}

NoExecutorException::NoExecutorException(NoExecutorException const &) {}

NoExecutorException::~NoExecutorException(void) throw() {}

NoExecutorException &NoExecutorException::operator=(
		NoExecutorException const &
	)
{
	return *this;
}

const char *NoExecutorException::what(void) const throw()
{
	return "No executor";
}
