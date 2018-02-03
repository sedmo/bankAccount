#ifndef BANK_H
#define BANK_H

#include <iostream>
#include <string>

#include"Account.h"

//constant definitions

const int MAX_NUM_ACCOUNTS = 50;

class Bank
{

    //Bank class declaration
    int numAccounts; //number of all accounts (active & closed)
    Account *account[MAX_NUM_ACCOUNTS]; //array of pointers to Accounts

    public:
        //cstr & dstr
        Bank();
        ~Bank();

        //member functions
        void addAccount(Depositor p_Depositor, int p_Accnum, string p_Acctype, double p_Bal);
        int getnumAccounts();
        Account *getAccount(int index);
        int findAccount(int requested_account);
        int findAccountSSN(string given_SSN);
        void addDeposit(int index,
        double amount_to_deposit);
        void takeWithdrawal (int index, double amount_to_wd);
        void deleteAccount(int index);
};

#endif // BANK_H

