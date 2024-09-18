#ifndef __Account_H__
#define __Account_H__

#include <string>
#include <vector>

class Account {
    public:
        Account(int, double, const std::string&);
        Account(const Account&) = delete;
        Account(Account&&) = delete;
        Account& operator=(Account&&) = delete;
        Account& operator=(const Account&) = delete;
        virtual void deposit(double amount) = 0;
        virtual void withdraw(double amount) = 0;
        virtual void transfer(Account& destination, double amount) = 0;
        virtual void showBalance() const = 0;
        virtual std::string getAccountType() const = 0;
        virtual ~Account() = default;
    protected:
        int accountNumber;
        double balance;
        std::string accountType;
};

class CheckingAccount : public Account {
    public:
        CheckingAccount(int accNum, double bal, double overdraft);
        void deposit(double amount) override;
        void withdraw(double amount) override;
        void transfer(Account& destination, double amount) override;
        void showBalance() const override;
        std::string getAccountType() const override;
        ~CheckingAccount() = default;
    private:
        double overdraftLimit;
};

class SavingsAccount : public Account {
    public:
        SavingsAccount(int accNum, double bal, double interest);
        void deposit(double amount) override;
        void withdraw(double amount) override;
        void transfer(Account& destination, double amount) override;
        void showBalance() const override;
        std::string getAccountType() const override;
        ~SavingsAccount() = default;
    private:
        double interestRate;
};

class JointAccount : public Account {
    public:
        JointAccount(int accNum, double bal, const std::vector<std::string>& owners);
        void addCustomer(const std::string& customerName);
        void deposit(double amount) override;
        void withdraw(double amount) override;
        void transfer(Account& destination, double amount) override;
        void showBalance() const override;
        std::string getAccountType() const override;
        ~JointAccount() = default;
    private:
        std::vector<std::string> jointOwners;
};

#endif