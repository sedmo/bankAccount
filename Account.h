#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "Depositor.h"
#include "Transaction.h"

#include<string>

using namespace std;

//constant definitions

const int MAX_TRANSACTIONS = 10;

class Account
{

    //member variables (private)


    int acc_num;
    string acc_type; //Checking, CD, or Savings
    double balance;
    Depositor depositor;
    bool acc_status; //Open or closed
    int num_trans; //Number of transactions performed
    Transaction *transaction[MAX_TRANSACTIONS]; //Array of transactions

    public:
    //constructor
        Account();
        Account(Depositor p_Depositor, int p_Accnum, string p_Acctype, double p_Bal);
        Account(Depositor p_Depositor, int p_Accnum, string p_Acctype, double p_Bal, bool p_acc_status);

    //destructor
        ~Account();

    //member functions (public)
    void is_open(bool); //sets account status


    //setters
    void setAcc_num(int);
    void setAcc_type(string);
    void setBalance(double);
    void setDepositor(Depositor);
    void setAcc_status(bool);
    void setTransaction(string), setTransaction(string, double);


    //getters
    int getAcc_num() const;
    string getAcc_type() const;
    double getBalance() const;
    Depositor getDepositor() const;
    string getAcc_status() const;
    Transaction *getTransaction (int index);
    int getNum_trans() const;
};

#endif // ACCOUNT_H
