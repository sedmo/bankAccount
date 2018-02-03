#ifndef DEPOSITOR_H
#define DEPOSITOR_H

#include"Name.h"


class Depositor
{
    //member variables (private)
    Name name;
    string social_security_number;

    public:
    //constructor
        Depositor(); // default cstor

        Depositor(string, Name);//with ssn

    //member functions

    //setters
        void setSsn(string);
        void setName(Name);//parameter data type : Name

    //getters
        string getSsn() const;
        Name getName() const;


};

#endif // DEPOSITOR_H
