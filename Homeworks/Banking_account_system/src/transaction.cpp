#include <iostream>
#include <ctime>
#include "../headers/transaction.h"
#include "../headers/account.h"

Transaction::Transaction(Account* from, Account* to, double amt, const std::string& type)
    : fromAccount{from},
    toAccount{to},
    amount{amt},
    transactionType{type},
    timestamp{std::chrono::system_clock::now()}
    {}

void Transaction::log() {
    std::time_t time = std::chrono::system_clock::to_time_t(timestamp);

    std::cout << "Transaction: " << transactionType << " of " << amount << " at " << std::ctime(&time) << std::endl;
}
