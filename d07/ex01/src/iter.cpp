/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 07:08:43 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/04 12:52:09 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

template <typename T>
inline void iter(T *arr, size_t len, void (*f)(T const &)) {
	for (size_t i = 0; i < len; i++)
		f(arr[i]);
}

void	print(const int &a)
{
	std::cout << a << std::endl;
}

int main(void)
{
	int arr[3] = {1, 2, 3};

	iter(arr, 3, print);
}
