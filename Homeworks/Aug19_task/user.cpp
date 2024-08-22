#include <iostream>
#include "user.h"

User::User() {
    fullname = "";
    email = "";
    password = "";
}

User::User(std::string fullname, std::string email, std::string password) {
    this->fullname = fullname;
    this->email = email;
    this->password = password;
}

void User::setFullName(std::string fullname) {
    this->fullname = fullname;
}

void User::setEmail(std::string email) {
    this->email = email;
}

void User::setPassword(std::string password) {
    size_t length = password.length();

    for (int i = 0; i < length; ++i) {
        if ((length < 4) || (password[i] == '#') || (password[i] == '?') || (password[i] == '@') || (password[i] == ' ')) {
            std::cout << "The password must contain at least four characters and must not contain the following characters: ' ', '#', '?', '@'" << std::endl;
            return;
        }
    }

    this->password = password;
}

void User::changePassword(std::string new_password) {
    std::string current_password;
    
    std::cout << "Please enter your current password: ";
    std::getline(std::cin, current_password);
    
    if (this->password == current_password) {
        User::setPassword(new_password);
        std::cout << "The password successfully changed! New password: " << this->password << std::endl;

        return;
    }

    std::cout << "Entered current password is wrong! Try again." << std::endl;
}

void User::updateEmail(std::string new_email) {
    std::string current_password;
    
    std::cout << "Please enter your current password: ";
    std::getline(std::cin, current_password);
    
    if (this->password == current_password) {
        this->email = new_email;
        std::cout << "Email successfully changed!" << "New email: " << this->email << std::endl;

        return;
    }

    std::cout << "Entered current password is wrong! Try again." << std::endl;
}

std::string User::getFullName() {
    return this->fullname;
}

std::string User::getEmail() {
    return this->email;
}

std::string User::getPassword() {
    return this->password;
}

void User::foo(User* user_ptr) {
    std::cout << "Name of 'User' type: " << typeid(user_ptr).name() << std::endl;
}
