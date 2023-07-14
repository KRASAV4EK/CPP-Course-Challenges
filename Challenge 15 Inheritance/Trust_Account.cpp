#include "Trust_Account.h"
#include "Savings_Account.h"

Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
    : Account {name, balance}, int_rate{int_rate} {
}

bool Trust_Account::deposit(double amount) {
    if (amount >= 5000) {
        balance += bonus;
    }
    amount += amount * (int_rate/100);
    return Account::deposit(amount);
}

bool Trust_Account::withdraw(double amount) {
    if (withdraw_number == 3) {
        return false;
    }

    withdraw_number++;
    return Account::withdraw(amount);
}

std::ostream &operator<<(std::ostream &os, const Trust_Account &account) {
    os << "[Trust_Account: " << account.name << ": " << account.balance << ", " << account.int_rate << "%]";
    return os;
}

