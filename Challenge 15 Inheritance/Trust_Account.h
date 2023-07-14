#ifndef _TRUST_ACCOUNT_H_
#define _TRUST_ACCOUNT_H_
#include "Account.h"

class Trust_Account: public Account {
    friend std::ostream &operator<<(std::ostream &os, const Trust_Account &account);
private:
    static constexpr const char *def_name = "Unnamed Trust Account";
    static constexpr double def_int_rate = 0.0;
    static constexpr double def_balance = 0.0;
    static constexpr double bonus = 50;
protected:
    double int_rate;
    int withdraw_number = 0;
public:
    Trust_Account(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);    
    bool deposit(double amount);
    bool withdraw(double amount);
    // Inherits the Account::withdraw methods
};

#endif // _TRUST_ACCOUNT_H_
