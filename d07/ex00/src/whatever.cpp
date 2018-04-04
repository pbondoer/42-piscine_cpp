/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 07:08:43 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/04 12:01:55 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

template <typename T>
inline const T& min(const T &a, const T &b) { 
	return a < b ? a : b; 
}

template <typename T>
inline const T& max(const T &a, const T &b) { 
	return a > b ? a : b; 
}

template <typename T>
inline void swap(T &a, T &b) {
	T t;

	t = a;
	a = b;
	b = t;
}

int main(void)
{
	int a = 0;
	int b = 42;

	std::cout << min(a, b) << std::endl;
	std::cout << max(a, b) << std::endl;

	std::cout << a << " " << b << std::endl;
	::swap(a, b);
	std::cout << a << " " << b << std::endl;
}
