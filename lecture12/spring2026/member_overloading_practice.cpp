#include <string>
#include <iostream>
 
class BankAccount {
public:
    BankAccount(std::string owner, double balance);
 
    std::string getOwner() const;
    double getBalance() const;
 
    BankAccount& operator+=(double amount);
    BankAccount& operator-=(double amount);
    bool operator==(const BankAccount& other) const;
    bool operator<(const BankAccount& other) const;
 
private:
    std::string owner;
    double balance;
};
 
// --- Provided for you ---
 
BankAccount::BankAccount(std::string owner, double balance)
    : owner(owner), balance(balance) {}
 
std::string BankAccount::getOwner() const { return owner; }
double BankAccount::getBalance() const { return balance; }
 
// --- Your turn: implement the 4 operators below ---
 
// TODO: implement +=  (deposit amount into balance, return *this)
BankAccount& BankAccount::operator+=(double amount) {
    balance += amount;
    return *this;
}
 
// TODO: implement -=  (withdraw amount from balance, return *this)
BankAccount& BankAccount::operator-=(double amount) {
    balance -= amount;
    return *this;
}
 
// TODO: implement ==  (true if same owner and same balance)
bool BankAccount::operator==(const BankAccount& other) const {
    return owner == other.owner && balance == other.balance;
}
 
// TODO: implement <<   (transfer all the funds from the first bankAccount to the second bankAccount)
bool BankAccount::operator<(const BankAccount& other) const {
    return balance < other.balance;
}
 
// --- Test your work ---
 
int main() {
    BankAccount alice("Alice", 500.0);
    BankAccount bob("Bob", 300.0);
 
    alice += 200.0;
    std::cout << "Alice balance (expect 700): " << alice.getBalance() << "\n";
 
    bob -= 100.0;
    std::cout << "Bob balance (expect 200):   " << bob.getBalance() << "\n";
 
    BankAccount alice2("Alice", 700.0);
    std::cout << "alice == alice2 (expect 1): " << (alice == alice2) << "\n";
    std::cout << "bob < alice (expect 1):     " << (bob < alice) << "\n";
 
    return 0;
}
