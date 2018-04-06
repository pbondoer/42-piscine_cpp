/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 23:24:33 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/05 23:36:23 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
# define EASYFIND_H

# include <algorithm>
# include <exception>

template<typename T>
int easyfind(T &obj, int i)
{
	typename T::iterator it = std::find(obj.begin(), obj.end(), i);

	if (it == obj.end())
		throw std::exception();	

	return *it;
}

#endif // EASYFIND_H
