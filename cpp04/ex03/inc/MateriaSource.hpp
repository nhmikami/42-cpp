#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include <iostream>

class MateriaSource : public IMateriaSource {
	protected:
		AMateria* _materias[4];

	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource& other);
		MateriaSource&	operator=(const MateriaSource& other);
		~MateriaSource(void);

		const AMateria*	getMateria(int idx) const;
		void			learnMateria(AMateria*);
		AMateria*		createMateria(std::string const& type);
};


#endif
