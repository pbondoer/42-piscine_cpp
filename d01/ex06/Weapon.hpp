/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 22:16:06 by pbondoer          #+#    #+#             */
/*   Updated: 2018/03/27 22:32:38 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_CLASS_H
# define WEAPON_CLASS_H

# include <string>

class Weapon
{
	public:
		Weapon(std::string type);
		~Weapon(void);

		const std::string getType(void) const;
		void setType(std::string type);

	private:
		std::string _type;
};

#endif // WEAPON_CLASS_H
