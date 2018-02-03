/* Homework 05 Bank Accounts Program using dynamic memory allocation
 * Name: Stephan Edmonson
 * Class: CISC 3110
 * Professor Ziegler
 * Date: November 20, 2017
 * Extra credit #3 (dynamically allocated transaction)
 */

#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib> //needed to use system() function
#include<iomanip>


//user classes
#include "Bank.h"

using namespace std;

//function prototypes
void read_data(Bank &, ifstream &);
void print_data(Bank , ofstream &);
void menu();
void quitPrint (Bank , ofstream &);
void printNot_open(Bank , ofstream &, int);
void withdrawal(Bank &, ofstream &);
void balance(Bank , ofstream &);
void print_inf(Bank , int , ofstream &);
void account_info(Bank, ofstream &);
void account_info_trans(Bank, ofstream &);
void deposit(Bank &, ofstream &);
void new_acct(Bank &, ofstream &);
void delete_acct(Bank &, ofstream &);
void reopen_acct(Bank &, ofstream &);
void close_acct(Bank &, ofstream &);


int main()
{
    Bank bank;
    char choice;                            //selection for menu
    bool not_done=true;

    // open input test cases file
    //ifstream infile ("C:\\Users\\Stephan\\Desktop\\CISC 3110\\HW5_bank_accounts_Dynamic_Memory_Allocation\\sample_input.txt");
    ifstream infile ("sample_input.txt");

    // open output file
    //ofstream outfile ("C:\\Users\\Stephan\\Desktop\\CISC 3110\\HW5_bank_accounts_Dynamic_Memory_Allocation\\myoutput.txt");
    ofstream outfile ("myoutput.txt");

    //open test file
    //ifstream test ("test.txt");

    outfile.setf(ios::fixed,ios::floatfield);
    outfile.precision(2);                       //set decimal precision

/* first part */
    /* fill and print initial database */


//set read and output file
    read_data(bank, infile);
    print_data(bank, outfile);

/* second part */
/* prompts for a transaction and then */
/* call functions to process the requested transaction */

    do {
        menu();
        cin >> choice;
        switch(choice)
        {
            case 'w':
            case 'W':
                withdrawal(bank, outfile);
                break;
            case 'q':
            case 'Q':
                not_done = false;
                quitPrint(bank, outfile);
                break;
            case 'b':
            case 'B':
                balance(bank, outfile);
                break;
            case 'i':
            case 'I':
                account_info(bank, outfile);
                break;
            case 'h':
            case 'H':
                account_info_trans(bank, outfile);
                break;
            case 'd':
            case 'D':
                deposit(bank,outfile);
                break;
            case 'n':
            case 'N':
                new_acct(bank, outfile);
                break;
            case 'x':
            case 'X':
                delete_acct(bank, outfile);
                break;
            case 'c':
            case 'C':
                close_acct(bank, outfile);
                break;
            case 'r':
            case 'R':
                reopen_acct(bank, outfile);
                break;
            default:
                outfile << endl << "Error: '" << choice << "' is an invalid selection -  try again" << endl << endl;
                break;

        }
        // give user a chance to look at output before printing menu
        //pause();

    } while (not_done);




    infile.close();                             //close input file

    outfile.close();                            // close output file

    return 0;
}

/* Function read_data:
 * Input:
 * p_acc_array - Account class type array
 * bank - Bank class object
 * input - input for data
 * Process:
 * reads data from input and places it into each index
 * of the Bank object's mem var account array
 * length of array is equal to num accounts active
 * Output:
 * none
 */

void read_data(Bank &bank,ifstream &infile)
{
    string lastname, firstname, ssnum, act;//act= account type
    int acn; //account number
    double bl; //balance
    while(infile >> lastname)
    {

        infile >> firstname;
        infile >> ssnum;
        infile >> acn;
        infile >> act;
        infile >> bl;
        bank.addAccount(Depositor (ssnum, Name (firstname, lastname)), acn, act, bl);

    }

}

 /* Function print_data ()
  * Input:
  *  output - output file for data
  *  bank - access to Bank type object
  * Process:
  *  Prints database from the bank object
  * Output:
  *  Prints database from the bank object
  */
void print_data(Bank bank, ofstream &outfile)
{
    Account *account;
    Depositor depositor;
    Name name;

    outfile<< endl << endl;
    outfile<<"\t\t\t Database of Bank Accounts"<<endl<<endl;
    outfile<<"Name"<<endl
    <<"Last\tFirst\t"
    <<left<<setw(9)<<"SS#"
    <<left<<setw(8)<<"\tAccount#"
    <<left<<setw(8)<<"\tAccount Type"
    <<left<<setw(8)<<"\tBalance"
    <<"\t\tAccount Status"
    <<endl;

    for(int index = 0;index < bank.getnumAccounts();index++)
    {
        account = bank.getAccount(index);
        depositor = account->getDepositor();
        name = depositor.getName();

        outfile<<name.getLastname();
        outfile<<"\t"<<name.getFirstname();
        outfile<<"\t"<<left<<setw(9)<<depositor.getSsn();
        outfile<<"\t"<<left<<setw(8)<<account->getAcc_num();
        outfile<<"\t"<<left<<setw(8)<<account->getAcc_type();
        outfile<<"\t"<<left<<setw(8)<<(*account).getBalance();
        outfile<<"\t"<<account->getAcc_status();


        outfile<<endl;


    }
}

/* Function menu()
 * Input:
 *  none
 * Process:
 *  Prints the menu of transaction choices
 * Output:
 *  Prints the menu of transaction choices
 */
void menu()
{

    cout << endl << endl;
    cout << "Select one of the following transactions:" << endl;
    cout << "\t****************************" << endl;
    cout << "\t    List of Choices         " << endl;
    cout << "\t****************************" << endl;
    cout << "\t     W -- Withdrawal" << endl;
    cout << "\t     D -- Deposit" << endl;
    cout << "\t     N -- New Account" << endl;
    cout << "\t     B -- Balance Inquiry" << endl;
    cout << "\t     I -- Account Info(without transaction history)" << endl;
    cout << "\t     H -- Account Info plus Account Transaction History" << endl;
    cout << "\t     C -- Close Account (close but do not delete the account)" << endl;
    cout << "\t     R -- Reopen a closed account" << endl;
    cout << "\t     X -- Delete Account (close and delete the account from the database)" << endl;
    cout << "\t     Q -- Quit" << endl;
    cout << endl << "\tEnter your selection: ";
    return;
}

/* Function quitPrint () - similar to print data but includes transaction history for
 * each individual account
 * Input:
 *  output - output file for data
 *  bank - access to Bank type object
 * Process:
 *  Prints database for each account with transaction history
 * Output:
 *  Prints database from bank object with transaction history appended
 */
void quitPrint (Bank bank, ofstream &outfile)
{
    Account *account;
    Depositor depositor;
    Name name;

    outfile<< endl << endl;
    outfile<<"\t\t\t Database of Bank Accounts"<<endl<<endl;


    for(int index = 0;index < bank.getnumAccounts();index++)
    {
        outfile<<"Name"<<endl
        <<"Last\tFirst\t"
        <<left<<setw(9)<<"SS#"
        <<left<<setw(8)<<"\tAccount#"
        <<left<<setw(8)<<"\tAccount Type"
        <<left<<setw(8)<<"\tBalance"
        <<"\t\tAccount Status"
        <<endl;
        account = bank.getAccount(index);
        depositor = account->getDepositor();
        name = depositor.getName();

        outfile<<name.getLastname();
        outfile<<"\t"<<name.getFirstname();
        outfile<<"\t"<<left<<setw(9)<<depositor.getSsn();
        outfile<<"\t"<<left<<setw(8)<<account->getAcc_num();
        outfile<<"\t"<<left<<setw(8)<<account->getAcc_type();
        outfile<<"\t"<<left<<setw(8)<<(*account).getBalance();
        outfile<<"\t"<<account->getAcc_status();


        outfile<<endl;

        //Transaction history section

        outfile<<"*******************************";

        outfile<<"\t"<<name.getFirstname()<<"'s "<<"Transaction History\t";

        outfile<<"*******************************";

        outfile<<"\n    Trans type   Trans amnt \n";
        int num_trans = account->getNum_trans();

        for(int counter = 1; counter <= num_trans;counter++)
        {

            Transaction *transaction = account->getTransaction((counter-1));

            outfile<<"#"<<counter<<": "<<
            left<<setw(12)<<transaction->getTrans_type()<<" "<<
            left<<transaction->getTrans_amnt()<<endl;

        }


        outfile<<endl<<endl;



    }
}

//function printNot_open - prints the error message if account status is closed
void printNot_open(Bank bank, ofstream &outfile, int index)
{
        outfile << "Error: " << bank.getAccount(index)->getAcc_num() << " is closed" <<
        " no transactions can be performed." << endl;
}

/* Function withdraw()
 * Input:
 *  bank
 *  outfile
 * Process:
 *  prompts for account number
*   checks if account is open
 *  if open, calls Bank method findAccount() to see if account number exists
 *  If ac num exists, prompts for amount to withdraw
 *  If amount is valid, it makes the withdrawal and prints the new balance
 *  records transaction
 *  Otherwise, an error message is printed
 * Output:
 *  For a valid withdrawal the old balance, amount requested
 *  and new balance are printed to the output file.
 */
void withdrawal(Bank &bank, ofstream &outfile)
{
    int requested_account;

    //prompt for account number
    cout << endl << "Enter the account number: ";
    cin >> requested_account;


    int index = bank.findAccount(requested_account);

    if(index != -1 && bank.getAccount(index)->getAcc_status() == "open") //if account is valid and open
    {
        double amount_to_wd;//amount to withdraw
        double balance = bank.getAccount(index)->getBalance();

        //prompt for withdrawal
        cout << "Enter amount to withdraw: ";
        cin >> amount_to_wd;

        if( amount_to_wd >= 0.0 && amount_to_wd <= balance) //valid withdrawal
        {

            outfile<< endl <<"Transaction Requested: Withdrawal"<<endl;
            outfile<<"Account Number: "<< requested_account<<endl;
            outfile<<"Old Balance: $"<<bank.getAccount(index)->getBalance()<<endl;
            outfile<<"Amount To Withdraw: $"<<amount_to_wd<<endl;
            bank.takeWithdrawal(index, amount_to_wd);//sets new balance and records transaction

            outfile<<"New Balance: $"<<bank.getAccount(index)->getBalance()<<endl;


        }
        else if( amount_to_wd < 0.0 )//invalid withdrawal amount requested is not positive
        {
            outfile << endl << "Transaction Requested: Withdrawal" << endl;
            outfile << "Account Number: " << requested_account << endl;
            outfile << "Error: " << amount_to_wd << " is an invalid amount." << endl;
        }
        else //invalid withdrawal insufficient funds
        {
            outfile << endl << "Transaction Requested: Withdrawal" << endl;
            outfile << "Account Number: " << requested_account << endl;
            outfile << "Error: " << amount_to_wd << " is an invalid amount. (Insufficient funds)." << endl;
        }
    }
    else if (index == -1)                                        //invalid account
    {
        outfile << endl << "Transaction Requested: Withdrawal" << endl;
        outfile << "Error: Account number " << requested_account << " does not exist" << endl;
    }
    else {printNot_open(bank, outfile, index);} //account closed
}

/* Function balance()
 * Input:
 *  bank - Bank type object with database information
 *  outfile - output file information
 * Process:
 *  asks user for requested accocunt
 *  checks if account is open
 *  if open, uses bank.findaccount(requested account) to
 *  search for account then prints to outfile
 *  records transaction
 * Output:
 *  if the method returns -1 then prints error message
 *  if not, then bank.findaccount(requested account) returns
 *  the index of the position of the account in the Account array of bank
 */
void balance(Bank bank, ofstream &outfile)
{

    int requested_account, index;

    cout << endl << "Enter the account number: ";
    cin >> requested_account;

    index = bank.findAccount(requested_account);
    if(index != -1 && bank.getAccount(index)->getAcc_status() == "open")//if account is valid and open
    {
        outfile << endl << "Transaction Requested: Balance Inquiry" << endl;
        outfile << "Account Number: " << bank.getAccount(index)->getAcc_num() << endl;
        outfile << "Current Balance: $" << bank.getAccount(index)->getBalance() << endl;

        //records transaction
        bank.getAccount(index)->setTransaction("balance");
    }
    else if(index == -1) //in valid acct
    {
        outfile << endl << "Transaction Requested: Balance Inquiry" << endl;
        outfile << "Error: Account number " << requested_account << " does not exist" << endl;
    }
    else {printNot_open(bank, outfile, index);} //closed account
}

/* Function print_inf()
 * Input:
 *  bank - accessing data to print information
 *  index - array position for desired info in the object
 *  outfile - output information
 * Process:
 *  Outputs info to outfile from bank
 * Output:
 *  Prints information from bank
 */
//complains if I write const in front of Bank
void print_inf(Bank bank,int index, ofstream &outfile)
{
    //make accessor variables
    Account *account = bank.getAccount(index);
    Depositor depositor = account->getDepositor();
    Name name = depositor.getName();

    outfile << "Name: " << " "
    << name.getFirstname() << " " << name.getLastname() << endl;
    outfile << "Social Security Number: " << bank.getAccount(index)->getDepositor().getSsn() << endl;
    outfile << "Account Number: " << account->getAcc_num() << "\t";
    outfile << "Account Type: " << account->getAcc_type() << endl;
    outfile << "Available Balance: $" << account->getBalance() << endl;

}

/* Function account info ()
 * Input:
 *  outfile - reference to output file
 *  bank - database
 * Process:
 *  Prompts user for a social security number
 *  checks to see if account is open
 *  If open, calls findssn() to see if account exists
 *  If the account exists, prints the complete account
 *  information for the requested account.
 * Output:
 *  If the account exists, prints all components of
 *  account information
 *  Otherwise, an error message is printed.
 */
void account_info(Bank bank, ofstream &outfile)
{
     string requested_ssn;

    //prompt for account number
    cout << endl << "Enter the Social Security number: ";
    cin >> requested_ssn;

    int index = bank.findAccountSSN(requested_ssn);
    if(index != -1 && bank.getAccount(index)->getAcc_status() == "open")//if account is valid and open
    {
        outfile << endl << "Transaction Requested: Account Info" << endl;
        print_inf(bank, index, outfile);
        //record transaction
        bank.getAccount(index)->setTransaction("Acc. inf");
    }
    else if (index == -1)                                        //invalid account
    {
        outfile << endl << "Transaction Requested: Account Info" << endl;
        outfile << "Error: Social Security Number " << requested_ssn
        << " does not exist" << endl;

    }
    else {printNot_open(bank, outfile, index);} //closed account
}

/* Function account_info_trans() - provides account info plus
 * transaction history
 * Input:
 *  bank - database of acounts
 *  outfile - output file information
 * Process:
 *  Prompts user for a social security number
 *  checks to see if account is open
 *  If open, calls findssn() to see if account exists
 *  If the account exists, calls print_inf()
 *  records transaction
 *  prints transaction to outfile
 * Output:
 *  If the account exists, prints all components of
 *  account information including transaction history for specified account
 *  Otherwise, an error message is printed.
 */
void account_info_trans(Bank bank, ofstream &outfile)
{
         string requested_ssn;

    //prompt for account number
    cout << endl << "Enter the Social Security number: ";
    cin >> requested_ssn;

    int index = bank.findAccountSSN(requested_ssn);

    if(index != -1 && bank.getAccount(index)->getAcc_status() == "open")//if account is valid and open
    {
            outfile << endl << "Transaction Requested: Account Info" << endl;
            print_inf(bank, index, outfile);

            //record transaction
            bank.getAccount(index)->setTransaction("Acc. inf & T.H.");


            //print transaction
            outfile << "Transaction History: " << endl;

            for(int counter = 1; counter <= bank.getAccount(index)->getNum_trans();counter++)
            {
                Transaction *transaction = bank.getAccount(index)->getTransaction((counter-1));

                outfile<<"#"<<counter<<": "<<
                left<<setw(10)<<transaction->getTrans_type()<<" "<<
                left<<transaction->getTrans_amnt()<<endl;
            }


    }

    else if (index == -1)                                        //invalid account
    {
        outfile << endl << "Transaction Requested: Account Info" << endl;
        outfile << "Error: Social Security Number " << requested_ssn
        << " does not exist" << endl;
    }
    else {printNot_open(bank, outfile, index);} //closed account

}

/* Function deposit()
 * Input:
 *  bank
 *  outfile
 * Process:
 *  prompt account number then assigns it an index
 *  checks if account is open
 *  prompts amount to deposit and runs it through the method addDeposit()
 *
 * Output:
 *  If account doesn't exist, prints error message and quits
 *  If index = -1 prints error message and quits
 *  If amount_to_deposit is <= 0 prints error message and quits
 *  Else prints account num, old bal, amount to deposit and new balance
 */
void deposit(Bank &bank, ofstream &outfile)
{
    int requested_account;

    //prompt for account number
    cout << endl << "Enter the account number: ";
    cin >> requested_account;

    int index = bank.findAccount(requested_account);

    //check if account is open
    if(index != -1 && bank.getAccount(index)->getAcc_status() == "open")   //if account is valid and open
    {
        double amount_to_deposit;

        //prompt for amount to deposit
        cout << "Enter amount to deposit: ";
        cin >> amount_to_deposit;

        if(amount_to_deposit <=0) //vld acc num but invald amnt to dpst
        {
            outfile << endl << "Transaction Requested: Deposit" << endl;
            outfile << "Account Number: " << requested_account << endl;
            outfile << "Error! $" << amount_to_deposit << " is an invalid amount" << endl;
        }
        else //valid
        {
            outfile << endl << "Transaction Requested: Deposit" << endl;
            outfile << "Account Number: " << requested_account << endl;
            outfile << "Old Balance: $" << bank.getAccount(index)->getBalance() << endl;
            outfile << "Amount to Deposit: $" << amount_to_deposit << endl;
            //add deposit
            bank.addDeposit(index, amount_to_deposit);      //make the deposit & records the transaction
            outfile << "New Balance: $" << bank.getAccount(index)->getBalance() << endl;

        }

    }
    else if (index == -1)                                        //invalid account
    {
        outfile << endl << "Transaction Requested: Deposit" << endl;
        outfile << "Error: Account number " << requested_account << " does not exist" << endl;
    }
    else {printNot_open(bank, outfile, index);} //closed account
}

/* Function new_acct
 * Input:
 *  bank - database
 *  outfile - reference to the output file
 *Process:
 *  Prompt for account number
 *  Calls findAccount() method to see if account exists
 *  If account is valid ,
 *  prompts for info needed to call addAccount() method
 *  calls print_inf() to print account info for new account
 *Output:
 *  For a valid new account,
 *  prints account info via print_inf()
 *  otherwise, prints error
 */
void new_acct(Bank &bank, ofstream &outfile)
{
    int requested_account, index;
    string first, last, ssn, type;
    double balance;

    //prompt for account number
    cout << endl << "Enter the account number: ";
    cin >> requested_account;

    //if requested_account d.n.e. (is -1), proceed
    index = bank.findAccount(requested_account);

    if(index == -1)                                     //valid account
    {
        //fill in values

         // prompt for first name
        cout << endl << "Enter First name: ";
        cin >> first;
        // prompt for last name
        cout << endl << "Enter Last Name: ";
        cin >> last;
        // prompt for SSN
        cout << endl << "Enter Social Security Number: ";
        cin >> ssn;
        // prompt for account type
        cout << endl << "Enter Account Type: ";
        cin >> type;
        // prompt for balance
        cout << endl << "Enter Balance: ";
        cin >> balance;

        Name name(first, last);
        Depositor depositor(ssn, name);
        bank.addAccount(depositor, requested_account, type, balance);


        outfile << endl << "Transaction Requested: New Account" << endl;
        //print info of new account using print_inf()
        //index should be the last array (numaccounts-1)
        index = ((bank.getnumAccounts()) - 1);
        print_inf(bank, index, outfile);
    }
    else                                                //invalid account
    {
        outfile << endl << "Transaction Requested: New Account" << endl;
        outfile << "Error: Account number " << requested_account ;
        outfile << " already exists and therefore cannot be used." << endl;
    }

}

/* Function delete_acct - close the account delete it and record the transaction
 * Input:
 *  bank - database
 *  outfile - reference to the output file
 * Process:
 *  Prompt for account number
 *  Calls findacct() to see if account exists
 *  if so, checks balance to see if it is non-zero
 *  if so, replaces components of account[index of acct to delete]
 *  with the following index.
 *  Minus one from num_accts
 *  otherwise, prints error message
 * Output:
 *  For a valid and sure delete request,
 *  prints confirmation of deleted account
 *  and returns num_accts
 *otherwise, prints error
 */
void delete_acct(Bank &bank, ofstream &outfile )
{
    int requested_account;

    //prompt for account number
    cout << endl << "Enter the account number: ";
    cin >> requested_account;

    int index = bank.findAccount(requested_account);

    if (index != -1)                                        //valid account
    {
        if(bank.getAccount(index)->getBalance()==0) //valid to delete if balance is 0
        {
            //close the account
            bank.getAccount(index)->setAcc_status(false);
            outfile << endl << "Transaction Requested: Delete Account" << endl;
            //bank delete acct
            bank.deleteAccount(index);
            outfile << "Account number " << requested_account << " has been deleted."<<endl;
        }
        else
        {
        outfile << endl << "Transaction Requested: Delete Account" << endl;
        outfile << "Error: Account number " << requested_account <<
        " cannot be used. Account balance must be 0 before removing account." << endl;
        }
    }

    else                                                //invalid account non-existent
    {
        outfile << endl << "Transaction Requested: Delete Account" << endl;
        outfile << "Error: Account number " << requested_account <<
        "cannot be used. Account does not exist." << endl;
    }

}
/* Function reopen_acct - reopens a closed account
 * Input:
 *  bank - database
 *  outfile - reference to the output file
 * Process:
 *  checks if account exists and that it is closed
 *  if so, reopen account by calling Account method setAcc_status()
 * Output:
 *  none
 */
void reopen_acct(Bank &bank, ofstream &outfile)
{
    int requested_account, index;

    cout << endl << "Enter the account number: ";
    cin >> requested_account;

    index = bank.findAccount(requested_account);

    if(index != -1 && bank.getAccount(index)->getAcc_status() == "closed")//if account is valid and closed
    {
        //reopen account and record transaction
        bank.getAccount(index)->setAcc_status(true);
        bank.getAccount(index)->setTransaction("Reopen");

        outfile << endl << "Transaction Requested: Reopen Account" << endl;
        outfile << "Account number: " << bank.getAccount(index)->getAcc_num() << " is now reopened.";

    }
    else if(index == -1) //invalid account
    {
        outfile << endl << "Transaction Requested: Reopen Account" << endl;
        //print error
        outfile << "Error: Account number " << requested_account << " does not exist" << endl;
    }
    else //invalid account
    {        outfile << endl << "Transaction Requested: Reopen Account" << endl;
        //print error
        outfile << "Error: Account number " << requested_account << " was always open." << endl;

    }

}


/* Function close_acct - closes an open account
 * Input:
 *  bank - database
 *  outfile - reference to the output file
 * Process:
 *  checks if account exists and that it is open
 *  if so, closes account by calling Account method setAcc_status()
 * Output:
 *  none
 */
void close_acct(Bank &bank, ofstream &outfile)
{
    int requested_account, index;

    cout << endl << "Enter the account number: ";
    cin >> requested_account;

    index = bank.findAccount(requested_account);

    if(index != -1 && bank.getAccount(index)->getAcc_status() == "open")//if account is valid and open
    {
        //close account and record transaction
        bank.getAccount(index)->setAcc_status(false);
        bank.getAccount(index)->setTransaction("Close Acct");

        outfile << endl << "Transaction Requested: Close Account" << endl;
        outfile << "Account Number: " << bank.getAccount(index)->getAcc_num() << " is now closed.\n";
    }
    else if(index == -1) //invalid account
    {
        //print error
        outfile << endl << "Transaction Requested: Close Account" << endl;
        outfile << "Error: Account number " << requested_account << " does not exist" << endl;
    }
    else //invalid account
    {
        //print error
        outfile << endl << "Transaction Requested: Close Account" << endl;
        outfile << "Error: Account number " << requested_account << " was always closed." << endl;

    }

}

