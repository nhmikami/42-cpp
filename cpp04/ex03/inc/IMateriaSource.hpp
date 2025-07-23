/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:22:24 by naharumi          #+#    #+#             */
/*   Updated: 2025/06/23 10:22:24 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include <iostream>

class AMateria;

class IMateriaSource {
	public:
		virtual	~IMateriaSource(void) {}
		virtual void		learnMateria(AMateria* m) = 0;
		virtual AMateria*	createMateria(const std::string& type) = 0;
};


#endif
