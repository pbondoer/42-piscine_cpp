/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 00:12:42 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/03 03:00:31 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept>
#include <string>
#include <iostream>

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string name, int sign, int exec) :
	_name(name), _gradeSign(sign), _gradeExec(exec), _signed(false)
{
	if (sign < 1)
		throw GradeTooHighException(sign);
	if (sign > 150)
		throw GradeTooLowException(sign);

	if (exec < 1)
		throw GradeTooHighException(exec);
	if (exec > 150)
		throw GradeTooLowException(exec);
}

Form::Form(Form const &obj) :
	_name(obj._name), _gradeSign(obj._gradeSign), _gradeExec(obj._gradeExec),
	_signed(obj._signed)
{}

Form::~Form(void)
{}

Form& Form::operator=(Form const &)
{
	return *this;
}

std::ostream &operator<<(std::ostream &o, Form const &rhs)
{
	o << "Form: " << rhs.getName() << " (sign " << rhs.getGradeSign()
		<< ", exec " << rhs.getGradeExec() << ")";
	return o;
}

const std::string Form::getName(void) const
{
	return this->_name;
}

int Form::getGradeSign(void) const
{
	return this->_gradeSign;
}

int Form::getGradeExec(void) const
{
	return this->_gradeExec;
}

bool Form::isSigned(void) const
{
	return this->_signed;
}

void Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > this->_gradeSign)
		throw GradeTooLowException(b.getGrade());

	this->_signed = true;
}

// Exceptions
typedef Form::GradeTooHighException GradeTooHighException;

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

typedef Form::GradeTooLowException GradeTooLowException;

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
