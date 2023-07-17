// Section 16
// Challenge
#include <iostream>
#include <vector>
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

using namespace std;

int main()
{
    cout << "//////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    cout.precision(2);
    cout << fixed;
    vector<Account *> p_accounts;

    // Savings

    vector<Savings_Account> sav_accounts;
    sav_accounts.push_back(Savings_Account{});
    sav_accounts.push_back(Savings_Account{"Superman"});
    sav_accounts.push_back(Savings_Account{"Batman", 2000});
    sav_accounts.push_back(Savings_Account{"Wonderwoman", 5000, 5.0});

    p_accounts.clear();
    for (int i = 0; i < (int)sav_accounts.size(); i++)
    {
        p_accounts.push_back(&sav_accounts[i]);
    }

    display(p_accounts);
    deposit(p_accounts, 1000);
    withdraw(p_accounts, 2000);

    // Checking

    vector<Checking_Account> check_accounts;
    check_accounts.push_back(Checking_Account{});
    check_accounts.push_back(Checking_Account{"Kirk"});
    check_accounts.push_back(Checking_Account{"Spock", 2000});
    check_accounts.push_back(Checking_Account{"Bones", 5000});

    p_accounts.clear();
    for (int i = 0; i < (int)check_accounts.size(); i++)
    {
        p_accounts.push_back(&check_accounts[i]);
    }

    display(p_accounts);
    deposit(p_accounts, 1000);
    withdraw(p_accounts, 2000);

    // Trust

    vector<Trust_Account> trust_accounts;
    trust_accounts.push_back(Trust_Account{});
    trust_accounts.push_back(Trust_Account{"Athos", 10000, 5.0});
    trust_accounts.push_back(Trust_Account{"Porthos", 20000, 4.0});
    trust_accounts.push_back(Trust_Account{"Aramis", 30000});

    p_accounts.clear();
    for (int i = 0; i < (int)trust_accounts.size(); i++)
    {
        p_accounts.push_back(&trust_accounts[i]);
    }

    display(p_accounts);
    deposit(p_accounts, 1000);
    withdraw(p_accounts, 3000);

    // Withdraw 5 times from each trust account
    // All withdrawals should fail if there are too many withdrawals or if the withdrawl is > 20% of the balance
    for (int i = 1; i <= 5; i++)
        withdraw(p_accounts, 1000);

    return 0;
}
