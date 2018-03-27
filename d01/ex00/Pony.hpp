/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 16:06:20 by pbondoer          #+#    #+#             */
/*   Updated: 2018/03/27 16:21:45 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_CLASS_H
# define PONY_CLASS_H

#include <string>

class Pony
{
	public:
		Pony(std::string name);
		~Pony(void);

		bool		IsAmazing(void) const;

	private:
		std::string	_name;
		bool		_isAmazing;
};

#endif // PONY_CLASS_H
