#ifndef __BANK_ACCOUNT_H__
#define __BANK_ACCOUNT_H__

struct BankAccount {

    // member variables
    double balance;

    // constructors
    BankAccount();
    explicit BankAccount(const double initial_balance);

    // member functions
    void deposit(double amount);
    bool withdraw(double amount);
    
};

#endif  // __BANK_ACCOUNT_H__