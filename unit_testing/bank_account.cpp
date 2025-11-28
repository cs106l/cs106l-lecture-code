#include "bank_account.hpp"

// default constructor initializes to balance of 0
BankAccount::BankAccount() 
    : balance(0) {}

// custom constructor that initializes balance to initial_balance
BankAccount::BankAccount(const double initial_balance) 
    : balance(initial_balance) {}

// deposit amount into the account
void BankAccount::deposit(double amount) { 
    balance += amount;
}

// withdraws amount from balance if funds exist.
bool BankAccount::withdraw(double amount)
{
    if (amount <= balance) {
        balance -= amount;
        return true;
    }
    return false;
}
