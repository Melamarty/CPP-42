#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; ++i) {
		templates[i] = nullptr;
	}
}

MateriaSource::MateriaSource(MateriaSource const & other) {
	for (int i = 0; i < 4; ++i) {
		if (other.templates[i])
			templates[i] = other.templates[i]->clone();
		else
			templates[i] = nullptr;
	}
}

MateriaSource & MateriaSource::operator=(MateriaSource const & other) {
	if (this != &other) {
		for (int i = 0; i < 4; ++i) {
			if (templates[i])
				delete templates[i];
			if (other.templates[i])
				templates[i] = other.templates[i]->clone();
			else
				templates[i] = nullptr;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; ++i) {
		if (templates[i])
			delete templates[i];
	}
}

void MateriaSource::learnMateria(AMateria* m) {
	for (int i = 0; i < 4; ++i) {
		if (!templates[i]) {
			templates[i] = m;
			break;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; ++i) {
		if (templates[i] && templates[i]->getType() == type) {
			return templates[i]->clone();
		}
	}
	return nullptr;
}