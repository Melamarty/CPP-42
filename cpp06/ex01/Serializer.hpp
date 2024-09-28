#pragma once

#include <iostream>

typedef struct Data_t
{
    int value;
} Data;

class Serializer
{
    private:
        Serializer();
    public:
        ~Serializer();
        Serializer(const Serializer &);
        Serializer &operator = (const Serializer & );
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};