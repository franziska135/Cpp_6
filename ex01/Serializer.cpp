#include "Serializer.hpp"

Serializer::Serializer(void) {
    std::cout   << "Serializer default constructor" << std::endl;
}

Serializer::Serializer(const Serializer& other) {
    *this = other;
    std::cout   << "Serializer copy constructor" << std::endl;
}

Serializer& Serializer::operator=(const Serializer& other) {
    if (this != &other) {
    }
    std::cout   << "Serializer copy assignment constructor" << std::endl;
    return *this;
}

Serializer::~Serializer  () {
    std::cout   << "Serializer Destructor called"
                << std::endl;
}

uintptr_t    Serializer::serialize(Data *ptr) {
    return  reinterpret_cast<uintptr_t>(ptr);
}

Data*        Serializer::deserialize(uintptr_t address) {
    return  reinterpret_cast<Data*>(address);
}