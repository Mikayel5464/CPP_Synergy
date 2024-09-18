#include <iostream>
#include "../headers/account.h"

Account::Account(int accNum, double bal, const std::string& accType)
    : accountNumber{accNum},
    balance{bal},
    accountType{accType} 
    {}

CheckingAccount::CheckingAccount(int accNum, double bal, double overdraft)
    : Account(accNum, bal, "Checking"),
    overdraftLimit{overdraft}
    {}

void CheckingAccount::deposit(double amount) {
    balance += amount;
    
    std::cout << "Deposited " << amount << " to Checking Account" << std::endl;
}

void CheckingAccount::withdraw(double amount) {
    if (balance + overdraftLimit >= amount) {
        balance -= amount;

        std::cout << "Withdraw " << amount << " from Checking Account" << std::endl;
    } else {
        std::cout << "Insufficient funds" << std::endl;
    }
}

void CheckingAccount::transfer(Account& destination, double amount) {
    if (balance += overdraftLimit >= amount) {
        withdraw(amount);
        destination.deposit(amount);

        std::cout << "Transferred " << amount << "from Checking Account to " << destination.getAccountType() << " Account" << std::endl;
    } else {
        std::cout << "Transfer failed due to insufficient funds" << std::endl;
    }
}

void CheckingAccount::showBalance() const {
    std::cout << "Checking Account Balance: " << balance << std::endl;
}

std::string CheckingAccount::getAccountType() const {
    return accountType;
}

SavingsAccount::SavingsAccount(int accNum, double bal, double interest)
    : Account(accNum, bal, "Savings"),
    interestRate{interest}
    {}

void SavingsAccount::deposit(double amount) {
    balance += amount;
    
    std::cout << "Deposited " << amount << " to Savings Account" << std::endl;
}

void SavingsAccount::withdraw(double amount) {
    if (balance >= amount) {
        balance -= amount;

        std::cout << "Withdraw " << amount << " from Savings Account" << std::endl;
    } else {
        std::cout << "Insufficient funds" << std::endl;
    }
}

void SavingsAccount::transfer(Account& destination, double amount) {
    if (balance >= amount) {
        withdraw(amount);
        destination.deposit(amount);

        std::cout << "Transferred " << amount << "from Savings Account to " << destination.getAccountType() << " Account" << std::endl;
    } else {
        std::cout << "Transfer failed due to insufficient funds" << std::endl;
    }
}

void SavingsAccount::showBalance() const {
    std::cout << "Savings Account Balance: " << balance << std::endl;
}

std::string SavingsAccount::getAccountType() const {
    return accountType;
}

JointAccount::JointAccount(int accNum, double bal, const std::vector<std::string>& owners)
    : Account(accNum, bal, "Joint"),
    jointOwners{owners}
    {}

void JointAccount::addCustomer(const std::string& customerName) {
    jointOwners.push_back(customerName);
    
    std::cout << "Added " << customerName << " as a joint owner" << std::endl;
}

void JointAccount::deposit(double amount) {
    balance += amount;
    
    std::cout << "Deposited " << amount << " to Joint Account" << std::endl;
}

void JointAccount::withdraw(double amount) {
    if (balance >= amount) {
        balance -= amount;

        std::cout << "Withdraw " << amount << " from Joint Account" << std::endl;
    } else {
        std::cout << "Insufficient funds" << std::endl;
    }
}

void JointAccount::transfer(Account& destination, double amount) {
    if (balance >= amount) {
        withdraw(amount);
        destination.deposit(amount);

        std::cout << "Transferred " << amount << "from Joint Account to " << destination.getAccountType() << " Account" << std::endl;
    } else {
        std::cout << "Transfer failed due to insufficient funds" << std::endl;
    }
}

void JointAccount::showBalance() const {
    std::cout << "Joint Account Balance: " << balance << std::endl;
}

std::string JointAccount::getAccountType() const {
    return accountType;
}
