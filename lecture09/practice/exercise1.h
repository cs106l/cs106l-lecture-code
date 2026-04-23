#include <string>

class BankAccount {
private:
    std::string owner;
    double balance;

public:
    BankAccount(std::string owner, double initialBalance);
    void deposit(double amount);
    bool withdraw(double amount);   // returns false if insufficient funds
    double getBalance() const;
    void printStatement() const;
};
