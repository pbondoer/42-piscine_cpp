/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 16:40:59 by pbondoer          #+#    #+#             */
/*   Updated: 2018/03/27 19:20:01 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_CLASS_H
# define ZOMBIEEVENT_CLASS_H

# include "Zombie.hpp"

#define TYPE_COUNT 4
#define NAME_COUNT 5

class ZombieHorde
{
	public:
		ZombieHorde(int n);
		~ZombieHorde(void);

		void	announce(void) const;

	private:
		int					_count;
		Zombie				*_zombies;
		static std::string	_types[TYPE_COUNT];
		static std::string	_names[NAME_COUNT];
};

#endif
