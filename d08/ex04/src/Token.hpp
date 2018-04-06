/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Token.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 08:02:30 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/06 10:34:03 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# include <ostream>

class Token
{
	public:
		enum Type
		{
			NONE,
			NUMBER,
			OPERATION,
			PAR_OPEN,
			PAR_CLOSE
		};

		Token(void);
		Token(int n);
		Token(char c);
		Token(Token const &obj);
		~Token(void);

		int getValue(void) const;
		Type getType(void) const;

		std::string toString(void) const;

		Token const &operator=(Token const &obj);
	private:
		Type	_type;
		int		_value;
};

std::ostream &operator<<(std::ostream &o, Token const &t);

#endif // TOKEN_H
