/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 16:34:20 by pbondoer          #+#    #+#             */
/*   Updated: 2018/03/27 18:53:19 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_CLASS_H
# define ZOMBIE_CLASS_H

# include <string>

class Zombie
{
	public:
		Zombie(std::string name, std::string type);
		~Zombie(void);

		std::string	getName() const;
		std::string	getType() const;
		void		announce() const;

	private:
		std::string _name;
		std::string _type;
};

#endif // ZOMBIE_CLASS_H
