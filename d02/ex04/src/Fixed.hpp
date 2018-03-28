/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 22:52:23 by pbondoer          #+#    #+#             */
/*   Updated: 2018/03/29 00:31:09 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_H
# define FIXED_CLASS_H

# include <iostream>

class Fixed
{
	public:
		Fixed(void);
		Fixed(int const value);
		Fixed(float const value);
		Fixed(Fixed const &src);
		~Fixed(void);

		Fixed &				operator=(Fixed const &rhs);

		// Comparison
		bool				operator==(Fixed const &rhs) const;
		bool				operator!=(Fixed const &rhs) const;
		bool				operator<(Fixed const &rhs) const;
		bool				operator<=(Fixed const &rhs) const;
		bool				operator>(Fixed const &rhs) const;
		bool				operator>=(Fixed const &rhs) const;

		// Arithmetic
		Fixed				operator+(Fixed const &rhs);
		Fixed				operator-(Fixed const &rhs);
		Fixed				operator/(Fixed const &rhs);
		Fixed				operator*(Fixed const &rhs);

		// Increment / decrement
		Fixed &				operator++(void);
		Fixed				operator++(int);
		Fixed &				operator--(void);
		Fixed				operator--(int);

		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		float				toFloat(void) const;
		int					toInt(void) const;

		static Fixed &		min(Fixed &a, Fixed &b);
		static const Fixed &min(Fixed const &a, Fixed const &b);
		static Fixed &		max(Fixed &a, Fixed &b);
		static const Fixed &max(Fixed const &a, Fixed const &b);
	private:
		int					_value;
		static const int	_fractionalBits;
		static const int	_power;
};

std::ostream &operator<<(std::ostream &o, Fixed const &rhs);

#endif // FIXED_CLASS_H
