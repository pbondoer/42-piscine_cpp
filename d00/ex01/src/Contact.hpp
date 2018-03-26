/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 17:37:10 by pbondoer          #+#    #+#             */
/*   Updated: 2018/03/26 19:02:31 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

# include <string>

# define FIELD_COUNT 11

class Contact
{
	public:
		Contact(void);
		~Contact(void);

		void		Prompt(void);
		void		Display(void) const;
		std::string	GetField(int field) const;
		void		SetField(int field, std::string value);

		static int	FindField(std::string field);

	private:
		static std::string _fieldNames[FIELD_COUNT];
		std::string _fields[FIELD_COUNT];
};

#endif // CONTACT_CLASS_H
