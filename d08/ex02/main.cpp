/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 01:19:20 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/06 02:43:41 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "mutantstack.hpp"

int main()
{
	MutantStack<int> mstack;
	std::cout << "Empty: " << mstack.empty() << std::endl;
	std::cout << "Size before push: " << mstack.size() << std::endl;
	mstack.push(17);
	std::cout << "---> " << mstack.top() << std::endl;
	std::cout << "Size after push: " << mstack.size() << std::endl;
	std::cout << "Empty: " << mstack.empty() << std::endl;
	mstack.pop();
	std::cout << "Size after pop: " << mstack.size() << std::endl;
	std::cout << "Empty: " << mstack.empty() << std::endl;

	for (int i = 0; i < 10; i++)
		mstack.push(i);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << std::endl;
	std::cout << mstack.size() << " items in mstack" << std::endl;
	while (it != ite)
	{
		std::cout << "> " << *it << std::endl;
		++it;
	}

	std::cout << std::endl;
	std::stack<int> s(mstack);

	std::cout << "(Copying to mstack2)" << std::endl;
	MutantStack<int> mstack2(s);

	std::cout << std::endl;
	std::cout << s.size() << " items in std::stack" << std::endl;
	while (!s.empty())
	{
		std::cout << "> " << s.top() << std::endl;
		s.pop();
	}


	it = mstack2.begin();
	ite = mstack2.end();
	++it;
	--it;
	std::cout << std::endl;
	std::cout << mstack2.size() << " items in mstack2" << std::endl;
	while (it != ite)
	{
		std::cout << "> " << *it << std::endl;
		++it;
	}

	return 0;
}
