#include "Serializer.hpp"
#include "Data.hpp"

int main (void) {
    Data    test;
    test.name = "dummy";
    test.value = 24;
    std::cout << test << std::endl;
    uintptr_t serialized = Serializer::serialize(&test);

    std::cout << std::endl;
    std::cout << "serialized unsigned int:\t" << serialized << std::endl;
    std::cout << "address of test struct:\t\t" << &test << std::endl;
    
    Data    *deserialized;
    deserialized = Serializer::deserialize(serialized);

    if (deserialized == &test) {
        std::cout   << std::endl;
        std::cout   << "Deserialization successful" << std::endl;
        std::cout   << "dezerialized: \t"
                    << *deserialized << std::endl;
        std::cout   << "original: \t" << test << std::endl;
    }
    else
        std::cout   << "Deserialization NOT successful" << std::endl;
    return 1;
}