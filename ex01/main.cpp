#include "Serializer.hpp"

int main (void) {
    Data    test;
    test.name = "dummy";
    test.value = 24;
    std::cout << test << std::endl;
    uintptr_t serialized = Serializer::serialize(&test);

    std::cout << "serialized unsigned int:\t" << serialized << std::endl;
    std::cout << "address of test struct:\t" << &test << std::endl;
    
    Data    *deserialized;
    deserialized = Serializer::deserialize(serialized);

    if (deserialized == &test) {
        std::cout   << "Deserialization successful" << std::endl;
        std::cout   << "deserialized Data:"
                    << deserialized << std::endl;
        std::cout   << "original:"
                    << test << std::endl;
    }
    else
        std::cout   << "Deserialization NOT successful" << std::endl;
    return 1;
}