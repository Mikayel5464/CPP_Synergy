#include <iostream>
#include "../headers/Unique_ptr.h"

class Test {
    public:
        void sayHello() {
            std::cout << "Hello" << std::endl;
        }
};

int main() {
    UniquePtr<Test> ptr(new Test());
    ptr->sayHello();

    UniquePtr<Test> ptr2(std::move(ptr));

    if (!ptr.get()) {
        std::cout << "ptr no longer owns the resource!!!" << std::endl;
    }

    ptr2->sayHello();

    UniquePtr<int> i_ptr(new int(10));
    UniquePtr<int> i_ptr2(new int(20));

    std::cout << "i_ptr = " << *i_ptr << std::endl;
    std::cout << "i_ptr2 = " << *i_ptr2 << std::endl;
    
    i_ptr = std::move(i_ptr2);
    
    if (!i_ptr.get()) {
        std::cout << "i_ptr no longer owns the resource!!!" << std::endl;
    }

    //std::cout << "i_ptr = " << *i_ptr << std::endl; -> segmentation fault

    return 0;
}
