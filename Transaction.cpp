#include "Transaction.h"

#include<string>
using namespace std;

/* Transaction default constructor
 *
 */
Transaction::Transaction()
{

}

/*Transaction constructor - accepts 1 argument*/
Transaction::Transaction(string p_trans_type)
{
    trans_type = p_trans_type;

}


/* Transaction constructor - accepts 2 arguments
 * accepts and subs the 2 parameters as member variable
 * of it's object
 *
 */
Transaction::Transaction(string p_trans_type, double p_trans_amnt)
{
    trans_type = p_trans_type;
    trans_amnt = p_trans_amnt;
}

/* Transaction member function setTrans_type():
 * Input:
 * p_trans_type - input from user to place into Transaction object
 * Process:
 * p_trans_type = trans_type
 * Output:
 * none
 */
void Transaction::setTrans_type(string p_trans_type)
{
    trans_type = p_trans_type;
}

/* Transaction member function setTrans_amnt():
 * Input:
 * p_trans_type - input from user to place into Transaction object
 * Process:
 * p_trans_amnt = trans_amnt
 * Output:
 * none
 */
void Transaction::setTrans_amnt(double p_trans_amnt)
{
    trans_amnt = p_trans_amnt;
}

/* Transaction member function getTrans_type():
 * Input:
 * none
 * Process:
 * retreives the value of member variable trans_type
 * Output:
 * returns the object's transaction type for transaction[index]
 */
string Transaction::getTrans_type() const
{
    return trans_type;
}

/* Transaction member function getTrans_amnt():
 * Input:
 * none
 * Process:
 * retreives the value of member variable trans_amnt
 * Output:
 * returns the object's transaction amount for transaction[index]
 */
double Transaction::getTrans_amnt() const
{
    return trans_amnt;
}
