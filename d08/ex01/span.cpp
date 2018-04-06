/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 00:24:08 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/06 01:06:17 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <algorithm>
#include <limits.h>
#include <cstdlib>

#include "span.hpp"

Span::Span(unsigned int n) : _n(n)
{
	_v.reserve(n);
}

Span::Span(Span const &obj)
{
	*this = obj;
}

Span::~Span(void)
{
	std::vector<int>().swap(this->_v);
}

Span const &Span::operator=(Span const &obj)
{
	if (this->_v == obj._v)
		return *this;

	this->_v = obj._v;
	this->_n = obj._n;

	return *this;
}

void Span::addNumber(int x)
{
	if (this->_v.size() == this->_n)
		throw std::exception();

	this->_v.push_back(x);
}

void Span::addVector(std::vector<int> &v)
{
	if (v.size() + this->_v.size() > this->_n)
		throw std::exception();

	this->_v.insert(this->_v.end(), v.begin(), v.end());
}

long Span::shortestSpan(void)
{
	long minDiff = LONG_MAX;
	long diff;

	std::vector<int> cpy = this->_v;
	std::sort(cpy.begin(), cpy.end());

	std::vector<int>::iterator last = cpy.begin();
	for (std::vector<int>::iterator it = cpy.begin() + 1;
			it != cpy.end();
			it++)
	{
		diff = std::abs(static_cast<long>(*it) - static_cast<long>(*last));

		if (diff < minDiff)
			minDiff = diff;

		last = it;
	}

	return minDiff;
}

long Span::longestSpan(void)
{
	return
		static_cast<long>(*std::max_element(this->_v.begin(), this->_v.end())) -
		static_cast<long>(*std::min_element(this->_v.begin(), this->_v.end()));
}
