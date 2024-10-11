#include "Data.hpp"

std::ostream&  operator<<(std::ostream& os, const Data& other) {
    os  << "name: "
        << other.name
        << "; value of Data struct: "
        << other.value;
    return (os);
}