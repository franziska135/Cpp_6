#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include "Data.hpp"
#include <iostream>
#include <stdint.h>

class Serializer {
    private:
        Serializer(void);
        Serializer(const Serializer &other);
        Serializer&         operator=(const Serializer &other);
        ~Serializer(void);

    public:
        static uintptr_t    serialize(Data *ptr);
        static Data*        deserialize(uintptr_t address);
};

#endif