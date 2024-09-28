#include "Serializer.hpp"

int main() {

    Data myData;
    myData.value = 5;
    std::cout << "Original Data Value: " << myData.value << std::endl;

    uintptr_t ptr = Serializer::serialize(&myData);
    std::cout << "Serialized ptr: " << ptr << std::endl;

    Data* deptr = Serializer::deserialize(ptr);
    std::cout << "Deserialized Data Value: " << deptr->value << std::endl;

    return 0;
}
