/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 00:12:42 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/03 02:58:07 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept>
#include <string>
#include <iostream>

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	this->setGrade(grade);
}

Bureaucrat::Bureaucrat(Bureaucrat const &obj) :
	_name(obj._name), _grade(obj._grade)
{}

Bureaucrat::~Bureaucrat(void)
{}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const &rhs)
{
	this->_grade = rhs.getGrade();

	return *this;
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return o;
}

const std::string Bureaucrat::getName(void) const
{
	return this->_name;
}

int Bureaucrat::getGrade(void) const
{
	return this->_grade;
}

void Bureaucrat::setGrade(int grade)
{
	if (grade < 1)
		throw GradeTooHighException(grade);
	if (grade > 150)
		throw GradeTooLowException(grade);

	this->_grade = grade;
}

void Bureaucrat::incrementGrade(void)
{
	this->setGrade(this->_grade - 1);
}

void Bureaucrat::decrementGrade(void)
{
	this->setGrade(this->_grade + 1);
}

void Bureaucrat::signForm(Form &f)
{
	if (f.isSigned())
	{
		std::cout << this->_name << " cannot sign " << f.getName()
			<< " because it is already signed." << std::endl;
		return;
	}
	try {
		f.beSigned(*this);
		std::cout << this->_name << " signs " << f.getName() << std::endl;
	}
	catch (Form::GradeTooLowException &)
	{
		std::cout << this->_name << " cannot sign " << f.getName()
			<< " because the grade was too low." << std::endl;
	}
}

// Exceptions
typedef Bureaucrat::GradeTooHighException GradeTooHighException;

GradeTooHighException::GradeTooHighException(const int grade) : _grade(grade)
{}

GradeTooHighException::GradeTooHighException(GradeTooHighException const &obj) :
	_grade(obj._grade)
{}

GradeTooHighException::~GradeTooHighException(void) throw() {}

GradeTooHighException &GradeTooHighException::operator=(
		GradeTooHighException const &rhs
	)
{
	this->_grade = rhs._grade;

	return *this;
}

int GradeTooHighException::getGrade(void) const
{
	return this->_grade;
}

const char *GradeTooHighException::what(void) const throw()
{
	return "Grade is too high";
}

typedef Bureaucrat::GradeTooLowException GradeTooLowException;

GradeTooLowException::GradeTooLowException(const int grade) : _grade(grade)
{}

GradeTooLowException::GradeTooLowException(GradeTooLowException const &obj) :
	_grade(obj._grade)
{}

GradeTooLowException::~GradeTooLowException(void) throw() {}

GradeTooLowException &GradeTooLowException::operator=(
		GradeTooLowException const &rhs
	)
{
	this->_grade = rhs._grade;

	return *this;
}

int GradeTooLowException::getGrade(void) const
{
	return this->_grade;
}

const char *GradeTooLowException::what(void) const throw()
{
	return "Grade is too low";
}
