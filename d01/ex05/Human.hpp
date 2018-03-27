/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 22:05:50 by pbondoer          #+#    #+#             */
/*   Updated: 2018/03/27 22:14:59 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_CLASS_H
# define HUMAN_CLASS_H

# include "Brain.hpp"

class Human
{
	public:
		Human(void);
		~Human(void);

		const Brain &getBrain() const;
		std::string identify() const;

	private:
		const Brain _brain;
};

#endif // HUMAN_CLASS_H
