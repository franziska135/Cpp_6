#include "Data.hpp"

std::ostream&  operator<<(std::ostream& os, const Data& other) {
    os  << other.name
        << " (name); value of Data struct: "
        << other.value;
    return (os);
}