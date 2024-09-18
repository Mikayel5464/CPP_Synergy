#ifndef __Customer_H__
#define __Customer_H__

#include <string>
#include <vector>
#include "account.h"

class Customer {
    public:
        Customer(const std::string& customerName, const std::string& contact);
        void addAccount(Account* account);
        void viewAccounts() const;
        void viewTransactionHistory() const;
    private:
        std::string name;
        std::string contactInfo;
        std::vector<Account*> accounts;
};

#endif