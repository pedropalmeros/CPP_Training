#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <string> 

class BankAccount{
    private:
        std::string accountHolder;
        double balance;

    public:
        BankAccount();
        BankAccount(std::string holder, double bal);
        ~BankAccount();

        void deposit(double amount); 
        void showInfo() const; 
};

#endif