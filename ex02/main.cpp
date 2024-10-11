#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void) {
    srand(time(0));

    int randomValue = rand() % 3;

    switch (randomValue) {
        case 2:
            return new A();
        case 1:
            return new B();
        case 0:
            return new C();
        default:
            return 0;
    }
}

void    identify(Base *p) {
    if (!p) {
        std::cout << "Error: Null pointer" << std::endl;;
        return ;
    }
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Error: type not found" << std::endl;
}

void    identify(Base &p) {
    try {
        if (dynamic_cast<A*>(&p))
            std::cout << "A" << std::endl;
        else if (dynamic_cast<B*>(&p))
            std::cout << "B" << std::endl;
        else if (dynamic_cast<C*>(&p))
            std::cout << "C" << std::endl;
        else
            std::cout << "Error" << std::endl;
    }
    catch (const std::exception &e) {
        std::cout << "Error" << e.what() << std::endl;
    }
}

int main(void) {
    Base *oA = NULL;
    Base *oB = new B();
    Base *oC = new C();

    std::cout << "Identification using pointers:" << std::endl;

    std::cout << "Should identify A: ";
    
    identify(oA);
    std::cout << "Should identify B: ";
    identify(oB);
    std::cout << "Should identify C: ";
    identify(oC);
    std::cout << std::endl;
    std::cout << "Identification using references:" << std::endl;

    std::cout << "Should identify A: ";
    if (oA)
        identify(*oA);
    else
        std::cout << "Error: NULL pointer cannot be passed to reference-based identify" << std::endl;
    
    std::cout << "Should identify B: ";
    if (oB)
        identify(*oB);
    else
        std::cout << "Error: NULL pointer cannot be passed to reference-based identify" << std::endl;
    
    std::cout << "Should identify C: ";
    if (oC)
        identify(*oC);
    else
        std::cout << "Error: NULL pointer cannot be passed to reference-based identify" << std::endl;

    if (oA)
        delete oA;
    if (oB)
        delete oB;
    if (oC)
        delete oC;
    return 1;
}