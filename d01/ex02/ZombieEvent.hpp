/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 16:40:59 by pbondoer          #+#    #+#             */
/*   Updated: 2018/03/27 16:52:01 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_CLASS_H
# define ZOMBIEEVENT_CLASS_H

# include "Zombie.hpp"

class ZombieEvent
{
	public:
		ZombieEvent(void);
		~ZombieEvent(void);

		void setZombieType(std::string type);
		Zombie* newZombie(std::string name) const;

		void randomChump(void) const;

	private:
		std::string _type;
		static std::string _names[5];
};

#endif
