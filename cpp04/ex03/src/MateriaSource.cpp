#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) {
	for (int i = 0; i < 4; i++)
		_materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	for (int i = 0; i < 4; i++) {
		if (other._materias[i])
			_materias[i] = other._materias[i]->clone();
		else
			_materias[i] = NULL;
	}
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& other) {
	if (this != &other) {
		for (int i = 0; i < 4; i++) {
			delete _materias[i];
			if (other._materias[i])
				_materias[i] = other._materias[i]->clone();
			else
				_materias[i] = NULL;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource(void) {
	for (int i = 0; i < 4; i++)
		delete _materias[i];
}

void	MateriaSource::learnMateria(AMateria* materia) {
	if (!materia)
		return ;
		
	for (int i = 0; i < 4; i++) {
		if (!_materias[i]) {
			_materias[i] = materia->clone();
			return ;
		}
	}
	std::cout << "MateriaSource is full, cannot learn more materias." << std::endl;
	return ;
}

AMateria*	MateriaSource::createMateria(std::string const& type) {
	for (int i = 0; i < 4; i++) {
		if (_materias[i] && _materias[i]->getType() == type) {
			AMateria* new_materia = _materias[i]->clone();
			return new_materia;
		}
	}
	std::cout << "Materia of type " << type << " not found." << std::endl;
	return NULL;
}
