#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
class Ice : public AMateria
{
	public:
		Ice();
		virtual ~Ice();
		virtual AMateria *clone() const;
		Ice &operator=(const Ice &other);
		virtual void use(ICharacter& target);
};

#endif