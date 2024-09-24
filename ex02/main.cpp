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
        std::cout << "Error: Nullptr" << std::endl;
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
    identify(&p);
}

int main(void) {
    Base *oA = new A();
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
    identify(*oA);
    std::cout << "Should identify B: ";
    identify(*oB);
    std::cout << "Should identify C: ";
    identify(*oC);

    delete oA;
    delete oB;
    delete oC;
    return 1;
}