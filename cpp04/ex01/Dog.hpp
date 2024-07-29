#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	protected:
		std::string type;
		Brain* b;
	public:
		Dog();
		Dog(const Dog &other);
		Dog& operator=(const Dog &other);
		~Dog();
		void makeSound() const;
		std::string getType() const;
};


#endif