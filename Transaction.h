#ifndef TRANSACTION_H
#define TRANSACTION_H

#include<string>
using namespace std;

class Transaction
{
    string trans_type; //transaction type i.e. create etc.
    double trans_amnt; //transaction amount

    public:
        Transaction();
        Transaction(string);
        Transaction(string, double);

        //setters
        void setTrans_type(string p_trans_type);
        void setTrans_amnt(double p_trans_amnt);

        //getters
        string getTrans_type() const;
        double getTrans_amnt() const;

};

#endif // TRANSACTION_H
