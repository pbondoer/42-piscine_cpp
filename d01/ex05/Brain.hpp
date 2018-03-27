/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 19:49:44 by pbondoer          #+#    #+#             */
/*   Updated: 2018/03/27 22:02:32 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_CLASS_H
# define BRAIN_CLASS_H

# include <string>

class Brain
{
	public:
		Brain(void);
		~Brain(void);

		std::string identify(void) const;
};

#endif // BRAIN_CLASS_H
