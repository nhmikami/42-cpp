/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:09:36 by naharumi          #+#    #+#             */
/*   Updated: 2025/06/23 10:09:36 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

#define RESET	"\033[0m"
#define YELLOW	"\033[33m"

class Fixed {
	private:
		int					_rawBits;
		static const int	_fractionalBits = 8;

	public:
		Fixed();
		Fixed(const Fixed& other);
		~Fixed();

		Fixed&	operator=(const Fixed& other);
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
