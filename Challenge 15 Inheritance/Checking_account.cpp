#include "Checking_Account.h"

Checking_Account::Checking_Account(std::string name, double balance, double int_rate)
    : Account {name, balance}, int_rate{0} {
}

bool Checking_Account::deposit(double amount) {
    return Account::deposit(amount);
}

bool Checking_Account::withdraw(double amount) {
    return Account::withdraw(amount + fee);
}

std::ostream &operator<<(std::ostream &os, const Checking_Account &account) {
    os << "[Checking_Account: " << account.name << ": " << account.balance << ", " << account.int_rate << "%]";
    return os;
}

