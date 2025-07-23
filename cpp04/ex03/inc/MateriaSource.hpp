/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:22:28 by naharumi          #+#    #+#             */
/*   Updated: 2025/06/23 10:22:28 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include <iostream>

#define MEMORY_SIZE 4

class MateriaSource : public IMateriaSource {
	protected:
		AMateria* _memory[MEMORY_SIZE];

	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource& other);
		~MateriaSource(void);
		
		MateriaSource&	operator=(const MateriaSource& other);

		const AMateria*	getMateria(int idx) const;
		void			learnMateria(AMateria* m);
		AMateria*		createMateria(const std::string& type);
};


#endif
