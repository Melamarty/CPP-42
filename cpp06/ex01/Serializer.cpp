#include "Serializer.hpp"

Serializer::Serializer()
{
    std::cout << "Serializer Created\n";
}
Serializer::~Serializer()
{
    std::cout << "Serializer Destroyed\n";
}
Serializer::Serializer(const Serializer &s)
{
    std::cout << "CC for Serializer called" << std::endl;
    (void)s;
}
Serializer &Serializer::operator = (const Serializer &s )
{
    std::cout << "CAO for Serializer called" << std::endl;
    (void)s;
    return *this;
}
uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}
Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data *>(raw);
}