#include "Account.h"

Account::Account(std::string name, double balance) 
    : name{name}, balance{balance} {
}

bool Account::deposit(double amount) {
    if (amount < 0) 
        return false;
    else {
        balance += amount;
        return true;
    }
}

void Account::print(std::ostream &os) const {
    os << "[Account: " << name << ": " << balance << "]";
}

std::ostream &operator<<(std::ostream &os, I_Printable &obj) {
    obj.print(os);
    return os;
}

bool Account::withdraw(double amount) {
    if (balance-amount >=0) {
        balance-=amount;
        return true;
    } else
        return false;
}
