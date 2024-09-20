#include "Intern.hpp"

int main() {
    {
        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("robotomy reques", "Bender");
        
        std::cout << rrf->get_name() << std::endl;
        Bureaucrat someBureaucrat("John", 50);
    }
    return 0;
}
