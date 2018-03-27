/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 16:34:20 by pbondoer          #+#    #+#             */
/*   Updated: 2018/03/27 19:19:29 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_CLASS_H
# define ZOMBIE_CLASS_H

# include <string>

class Zombie
{
	public:
		Zombie(void);
		~Zombie(void);

		void		setName(std::string name);
		void		setType(std::string type);
		std::string	getName() const;
		std::string	getType() const;

		void		announce() const;

	private:
		std::string _name;
		std::string _type;
};

#endif // ZOMBIE_CLASS_H
