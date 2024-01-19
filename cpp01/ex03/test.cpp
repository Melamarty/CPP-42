#include "Weapon.hpp"

class HumanA
{
	private:
		std::string name;
		// Weapon weapon;

	public:
		HumanA(const std::string name);
		~HumanA();
		void attack();
};

// Constructor definition
HumanA::HumanA(const std::string name)
{
	this->name = name;
}
 int main ()
 {
	return (0);
 }