/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Database.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 16:29:26 by pbondoer          #+#    #+#             */
/*   Updated: 2018/03/26 18:34:45 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATABASE_CLASS_H
# define DATABASE_CLASS_H

# include "Contact.hpp"

class Database
{
	public:
		Database(void);
		~Database(void);

		int		Count(void) const;
		void	AddContact(Contact c);
		Contact	GetContact(int i) const;
		void	List(void) const;

	private:
		int			_count;
		Contact		_contacts[8];
}; // class Database

#endif // DATABASE_CLASS_H
