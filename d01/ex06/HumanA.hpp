/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 22:23:20 by pbondoer          #+#    #+#             */
/*   Updated: 2018/03/27 22:34:19 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_CLASS_H
# define HUMANA_CLASS_H

# include <string>

# include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(std::string name, Weapon &w);
		~HumanA(void);

		void	attack(void) const;

	private:
		std::string _name;
		Weapon &_weapon;
};

#endif // HUMANA_CLASS_H
