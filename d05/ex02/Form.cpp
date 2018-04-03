/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 00:12:42 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/03 04:17:46 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept>
#include <string>
#include <iostream>

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void) :
	_name("default"), _gradeSign(150), _gradeExec(150), _signed(false),
	_target("default_target") {};
Form::Form(const std::string name, int sign, int exec, std::string target) :
	_name(name), _gradeSign(sign), _gradeExec(exec), _signed(false),
	_target(target)
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
	_signed(obj._signed), _target(obj._target)
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

std::string Form::getTarget(void) const
{
	return this->_target;
}

void Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > this->_gradeSign)
		throw GradeTooLowException(b.getGrade());

	this->_signed = true;
}

void Form::execute(Bureaucrat const &b) const
{
	if (!this->_signed)
		throw NotSignedException();

	if (b.getGrade() > this->_gradeExec)
		throw GradeTooLowException(b.getGrade());

	this->_execute(b);
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

typedef Form::NotSignedException NotSignedException;

NotSignedException::NotSignedException(void) {}

NotSignedException::NotSignedException(NotSignedException const &) {}

NotSignedException::~NotSignedException(void) throw() {}

NotSignedException &NotSignedException::operator=(
		NotSignedException const &
	)
{
	return *this;
}

const char *NotSignedException::what(void) const throw()
{
	return "Form not signed";
}
