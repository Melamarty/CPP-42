#ifndef CHARARCTER_HPP
#define CHARARCTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter {
private:
	std::string name;
	AMateria* inventory[4];

public:
	Character(std::string const & name);
	Character(Character const & other);
	Character & operator=(Character const & other);
	virtual ~Character();

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};




#endif