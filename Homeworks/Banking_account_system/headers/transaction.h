#ifndef __Transaction_H__
#define __Transaction_H__

#include <chrono>
#include "account.h"

class TransactionManager {
    public:
        virtual void logTransaction(const std::string& type, double amount) = 0;
        virtual void showTransactionHistory() const = 0;
        virtual ~TransactionManager() = default;
};

class Transaction {
    public:
        Transaction(Account* from, Account* to, double amt, const std::string& type);
        void log();
    private:
        Account* fromAccount;
        Account* toAccount;
        double amount;
        std::string transactionType;
        std::chrono::time_point<std::chrono::system_clock> timestamp;
};

#endif