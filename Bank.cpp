#include "Bank.h"
#include<string>

Bank::Bank()//ctor
{
    numAccounts=0;
}

/* Destructor:
 * deletes memory for the member variable account and sets account [] to a null ptr
 */
Bank::~Bank()//dtor
{
    //Program periodically crashes when using the delete operator as such
   // cout<<"Bank Destructor running.";
    /*while(numAccounts > 0)
    {
        cout<<numAccounts<<endl;
        numAccounts--;
        delete account[numAccounts];
        account[numAccounts] = NULL;
    }
    */
    cout<<"Bank destructor running."<<endl;
    delete [] account;

}

/* Function addAccount()
 * Input:
 *  p_Accnum - object's account num
 *  p_Acctype - object's account type
 *  p_Bal - object's balance
 *  p_Depositor - a Depositor type variable for inputting user data
 * p_acc_status - object's account status
 * Process:
 *  starting at numAccounts = 0, users input gets stored into memvariable
 *  account[numAccounts] the parameter is used to set the appropriate
 *  Account constructor
 *  transaction type is "creat" and respective balance is added for the trans history
 * Output:
 *  none
 */

void Bank::addAccount(Depositor p_Depositor, int p_Accnum, string p_Acctype, double p_Bal)
{
    account[numAccounts] = new Account(p_Depositor, p_Accnum, p_Acctype, p_Bal, true);
    //record transaction and increase num of transactions for the specific account
    account[numAccounts]->setTransaction("Create", p_Bal);
    //after filling in for new account array, increase num of active accounts
    numAccounts++;

}

/* Function getnumAccounts()
 * Input:
 *  none
 * Process:
 *  returns mem var numAccounts
 * Output:
 *  none
 */
int Bank::getnumAccounts()
{
    return numAccounts;
}

/* Function getAccount()
 * Input:
 *  index - index of object's Account array
 * Process:
 *  returns account[index]
 * Output:
 *  none
 */
Account *Bank::getAccount(int index)
{
    return (account[index]);
}

/* Function findAccount()
 * Input:
 *  requested_account
 * Process:
 *  Performs a linear search on Bank object for the requested account
 * Output:
 *  If found, returns index of the requested account
 *  Else, returns -1
 */
int Bank::findAccount(int requested_account)
{

    for(int x =0;x < numAccounts ;x++)
    {

        if(account[x]->getAcc_num() == requested_account)
        {
            return x;
        }


    }
    return -1;
}

/* Function findAccountSSN()
 * Input:
 *  given_SSN - user input string
 * Process:
 *  Performs a linear search on Bank object for the
 *  given SSN
 *  Output:
 *  If found, returns the position (via index) of
 *  the Account type array where SSN is located,
 *  If not found, returns -1
 */
int Bank::findAccountSSN(string given_SSN)
{
    for(int i = 0; i < numAccounts; i++)
    {
        if(account[i]->getDepositor().getSsn() == given_SSN)
        {
            return i;
        }
    }
    return -1;
}

/* Function addDeposit() - sets amount_to_deposit as being the new balance
 * Input:
 *  index
 *  amount_to_deposit
 * Process:
 *  sums amount to deposit with old balance
 * Output:
 *  none.
 */
void Bank::addDeposit(int index, double amount_to_deposit)
{
    double new_balance = (amount_to_deposit + account[index]->getBalance());
    account[index]->setBalance(new_balance);

    //record transaction

    account[index]->setTransaction("Deposit", amount_to_deposit);
}

/* Function takeWithdrawal - sets new balance and records transaction
 * Process:
 *  subtract's balance of current account
 *  by amount desired to withdraw
 *  sets as new balance
 *  records the transaction
 *
 */
void Bank::takeWithdrawal (int index, double amount_to_wd)
{
    double new_balance = (account[index]->getBalance() - amount_to_wd);
    account[index]->setBalance(new_balance);

    //record transaction

    account[index]->setTransaction("Withdrawal", amount_to_wd);

}

/* Function deleteAccount - replaces current index with the subsequent index
 * then removes one account
 * Input:
 * Process:
 * Output:
 */
void Bank::deleteAccount(int index)
{
    for(int i=index; i<(numAccounts - 1); ++i)              //i = index of requested account to delete. must be one less than num_accts
            {
                //requested account will be replaced by the preceeding account
                //in array
                account[i] = account[i+1];
            }
    //when done running loop, delete one account

    numAccounts -= 1;

    //record transaction

    account[index]->setTransaction("Delete");
}













