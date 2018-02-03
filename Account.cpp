#include<string>
#include <iostream>
#include "Account.h"
#include "Transaction.h"

using namespace std;

//default constructor
Account::Account()
{
    acc_num = 0;
    acc_type = "/null";
    balance = 0.00;  //put other account values
    num_trans = 0;
}

/* Depositor constructor 2 - accepts 5 arguments
 * Input:
 * p_acc_num - The object's account number
 * p_acc_type - The object's account type
 * p_balance - The object's balance
 * p_depositor - A Depositor object used by the Account class
 * p_acc_status - The object's account status
 * Process:
 * set acc_num = p_acc_num
 * set acc_type =  p_acc_type
 * set balance = p_balance
 * set depositor = p_depositor
 * set acc_status = p_acc_status
 * Output:
 * none
 */
 Account::Account(Depositor p_Depositor, int p_Accnum, string p_Acctype, double p_Bal, bool p_acc_status)
 {
     acc_num = p_Accnum;
     acc_type =  p_Acctype;
     balance = p_Bal;
     depositor = p_Depositor;
     acc_status = p_acc_status;
     num_trans = 0;
 }

 /* Depositor constructor 2 - accepts 4 arguments
 * Input:
 * p_acc_num - The object's account number
 * p_acc_type - The object's account type
 * p_balance - The object's balance
 * p_depositor - A Depositor object used by the Account class
 * Process:
 * set acc_num = p_acc_num
 * set acc_type =  p_acc_type
 * set balance = p_balance
 * set depositor = p_depositor
 * Output:
 * none
 */
 Account::Account(Depositor p_Depositor, int p_Accnum, string p_Acctype, double p_Bal)
 {
     acc_num = p_Accnum;
     acc_type =  p_Acctype;
     balance = p_Bal;
     depositor = p_Depositor;
     num_trans = 0;
 }

//destructor
Account::~Account()
{
   // cout<<"Account Destructor running. Destroying number: "<<num_trans<<endl;
   //never runs since account gets delted
    /*while(num_trans > 0)
    {
        num_trans--;
        delete transaction[num_trans];
        transaction[num_trans] = NULL;
    }
    */

}

/*Account member function is_open:
 * Input:
 * none
 * Process:
 * sets account status depending on answer
 * Output:
 * none
 */
void Account::is_open(bool answer){
    acc_status = answer;
}

//setters

/* Account member function setAcc_num:
 * Input:
 * p_acc_num - variable for account number member var
 * Process:
 * sets acc_num = p_acc_num
 * Output:
 * none
 */
void Account::setAcc_num(int p_acc_num)
{
    acc_num = p_acc_num;
}

/* Account member function setAcc_type:
 * Input:
 * p_acc_type - variable for account type member var
 * Process:
 * sets acc_type = p_acc_type
 * Output:
 * none
 */

 void Account::setAcc_type(string p_acc_type)
{
    acc_type = p_acc_type;
}

/* Account member function setBalance:
 * Input:
 * p_balance - variable for balance member var
 * Process:
 * sets balance = p_balance
 * Output:
 * none
 */
 void Account::setBalance(double p_balance)
{
    balance = p_balance;
}


/* Account member function setDepositor:
 * Input:
 * p_depositor - user inputted object substitution for Account object's
 * depositor member variable
 * Process:
 * set depositor = p_depositor
 * Output:
 * none
 */
void Account::setDepositor(Depositor p_depositor)
{
    depositor = p_depositor;
}

/* Account member function setAcc_status():
 * Input:
 * answer - determines status of account
 * Process:
 * acc_status = answer
 * Output:
 * none
 */
void Account::setAcc_status(bool answer)
{
    acc_status = answer;
}

/* Account member function setTransaction:
 * Input:
 * p_transaction - user inputted Transaction object substitution for Account object's
 * transaction member variable
 * Process:
 * set transaction = p_transaction
 * Output:
 * none
 */
void Account::setTransaction( string trans_type, double trans_amnt)
{
    transaction[num_trans] = new Transaction(trans_type, trans_amnt);

    //increase number of transactions
    num_trans++;

}

//Overloaded setTransaction uses only one argument
void Account::setTransaction( string trans_type)
{
    transaction[num_trans] = new Transaction(trans_type);

    //increase number of transactions
    num_trans++;

}

//getters

/* member function getAcc_num
 * Input:
 * none
 * Process:
 * returns mem var acc_num
 * Output:
 * none
 */
int Account::getAcc_num() const
{
    return (acc_num);
}

/* member function getAcc_type
 * Input:
 * none
 * Process:
 * returns mem var acc_type
 * Output:
 * none
 */
string Account::getAcc_type() const
{
    return (acc_type);
}

/* member function getBalance
 * Input:
 * none
 * Process:
 * returns mem var Balance
 * Output:
 * none
 */
double Account::getBalance() const
{
    return (balance);
}


/* member function getDepositor:
 * Input:
 * none
 * Process:
 * returns mem var depositor
 * Output:
 * none
 */
Depositor Account::getDepositor() const
{
    return (depositor);
}

/* member function getAcc_status:
 * Input:
 * none
 * Process:
 * returns mem var account status
 * Output:
 * none
 */
string Account::getAcc_status() const
{
    if(acc_status==true)
    {
        return "open";
    }
    return "closed";
}

/* member function getTransaction () :
 * Input:
 * index - requested index of object's Transaction array
 * Process:
 * returns transaction[index]
 * Output:
 * none
 */
Transaction *Account::getTransaction (int index)
{
    return (transaction[index]);
}

/* Account member function getNum_trans():
 * Input:
 * none
 * Process:
 * retrieves the value of member variable num_trans
 * Output:
 * returns object's number of transaction
 */
int Account::getNum_trans() const
{
    return num_trans;
}
