/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:22:00 by naharumi          #+#    #+#             */
/*   Updated: 2025/06/23 10:22:00 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

#define RESET	"\033[0m"
#define YELLOW	"\033[33m"
#define MAGENTA	"\033[35m"

class ICharacter;

class AMateria {
	protected:
		const std::string	_type;

	public:
		AMateria(void);
		AMateria(const std::string& type);
		AMateria(const AMateria& other);
		virtual ~AMateria(void);
		
		AMateria&	operator=(const AMateria& other);

		const std::string&	getType() const;
		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);
};

#endif
