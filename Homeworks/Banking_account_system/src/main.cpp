#include <iostream>
#include "../headers/account.h"
#include "../headers/customer.h"
#include "../headers/transaction.h"

int main() {
    std::cout << "Creating a new customer" << std::endl;
    Customer customer1("Mikayel", "mikayel@gmail.com");

    std::cout << "Creating a Checking Account and a Savings Account" << std::endl;
    CheckingAccount* checkingAccount = new CheckingAccount(1001, 500.0, 300.0);
    SavingsAccount* savingsAccount = new SavingsAccount(1002, 1000.0, 2.5);

    customer1.addAccount(checkingAccount);
    customer1.addAccount(savingsAccount);

    std::cout << "Depositing $200 into Checking Account" << std::endl;
    checkingAccount->deposit(200.0);

    std::cout << "Withdrawing $100 from Checking Account" << std::endl;
    checkingAccount->withdraw(100.0);

    std::cout << "Transferring $300 from Savings Account to Checking Account" << std::endl;
    savingsAccount->transfer(*checkingAccount, 300.0);

    std::cout << "Showing account balances:" << std::endl;
    checkingAccount->showBalance();
    savingsAccount->showBalance();

    delete checkingAccount;
    delete savingsAccount;

    return 0;
}
