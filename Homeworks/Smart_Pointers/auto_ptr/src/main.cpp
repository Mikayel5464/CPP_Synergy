#include <iostream>
#include "../headers/Auto_ptr.h"

class Test {
    public:
        void sayHello() const {
            std::cout << "Hello" << std::endl;
        }
};

int main() {
    AutoPtr<int> ptr(new int(10));
    AutoPtr<Test> ptr2(new Test());
    
    std::cout << "Pointer dereferancing: " << *ptr << std::endl;
    
    std::cout << "-> operator: ";
    ptr2->sayHello();
    std::cout << std::endl;

    AutoPtr<double> ptr3(new double(42.1));
    AutoPtr<double> ptr4 = ptr3;

    std::cout << "*ptr4 = " << *ptr4 << std::endl;

    AutoPtr<int> ptr5(new int(30));
    AutoPtr<int> ptr6(new int(40));
    ptr5 = ptr6;

    std::cout << "*ptr5 = " << *ptr5 << std::endl;

    return 0;
}
