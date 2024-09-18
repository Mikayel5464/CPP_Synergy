#include <iostream>
#include <string>
#include <vector>
#include "../headers/customer.h"
#include "../headers/account.h"

Customer::Customer(const std::string& customerName, const std::string& contact)
    : name{customerName},
    contactInfo{contact}
    {}

void Customer::addAccount(Account* account) {
    accounts.push_back(account);
}

void Customer::viewAccounts() const {
    std::cout << name << "'s Accounts:" << std::endl;

    for (int i = 0; i < accounts.size(); ++i) {
        accounts[i]->showBalance();
    }
}
