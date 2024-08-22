#include<iostream>
#include "user.h"

void foo(User*);

int main() {
    User ob("Mikayel", "mikayel@gmail.com", "test1234");

    User* ptr = &ob;
    ob.foo(ptr);
    
    //User ob;
    //ob.setFullName("Mikayel");
    //ob.setEmail("mikayel@gmail.com");
    //ob.setPassword("test1234");

    std::cout << "Full Name: " << ob.getFullName() << std::endl;
    std::cout << "Email: " << ob.getEmail() << std::endl;
    std::cout << "Password: " << ob.getPassword() << std::endl;

    std::cout << std::endl;

    ob.changePassword("test111");
    std::cout << std::endl;
    
    ob.updateEmail("abcd@gmail.com");
    std::cout << std::endl;

    return 0;
}
