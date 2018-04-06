/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 01:19:18 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/06 02:45:19 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>

#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(void): std::stack<T>() {}
		virtual ~MutantStack(void) {}

		// provide copy constructors
		MutantStack(std::stack<T> const &obj): std::stack<T>(obj) {}
		MutantStack(MutantStack const &obj): std::stack<T>(obj) {}

		// use the base class operator=
		using std::stack<T>::operator=;

		// container_type is a type which maps to Container
		// which itself holds the iterator type
		typedef typename std::stack<T>::container_type::iterator iterator;

		// http://en.cppreference.com/w/cpp/container/stack
		// c is the container, and a member of std::stack
		iterator begin(void) { return std::begin(std::stack<T>::c); }
		iterator end(void) { return std::end(std::stack<T>::c); }
};

#endif // MUTANTSTACK_H
