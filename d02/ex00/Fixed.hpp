/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 22:52:23 by pbondoer          #+#    #+#             */
/*   Updated: 2018/03/28 23:15:26 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_H
# define FIXED_CLASS_H

class Fixed
{
	public:
		Fixed(void);
		Fixed(Fixed const &src);
		~Fixed(void);

		Fixed &				operator=(Fixed const &rhs);

		int					getRawBits(void) const;
		void				setRawBits(int const raw);
	private:
		int					_value;
		static const int	_fractionalBits;
};

#endif // FIXED_CLASS_H
