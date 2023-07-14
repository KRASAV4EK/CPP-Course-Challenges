#ifndef _CHECKING_ACCOUNT_H_
#define _CHECKING_ACCOUNT_H_

#include "Account.h"

class Checking_Account: public Account {
    friend std::ostream &operator<<(std::ostream &os, const Checking_Account &account);
private:
    static constexpr const char *def_name = "Unnamed Checking Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;
    static constexpr double fee = 1.5;
protected:
    double int_rate;
public:
    Checking_Account(std::string name = def_name, double balance =def_balance, double int_rate = def_int_rate);    
    bool deposit(double amount);
    bool withdraw(double amount);
};

#endif // _CHECKING_ACCOUNT_H_
