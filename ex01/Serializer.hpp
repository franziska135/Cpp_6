#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include "Data.hpp"
#include <iostream>
#include <cstdint>
//#include <stdint.h>

class Serializer {
    public:
        Serializer(void);
        Serializer(const Serializer &other);
        ~Serializer(void);

        Serializer&         operator=(const Serializer &other);

        static uintptr_t    serialize(Data *ptr);
        static Data*        deserialize(uintptr_t address);
};

#endif