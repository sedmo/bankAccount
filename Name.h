#ifndef NAME_H
#define NAME_H

#include<string>
using namespace std;

class Name
{
    string firstname;
    string lastname;

    public:
    //cstr
        Name();
        Name(string fname, string lname);

            //member functions              //public variables

    //setter

    void setLastname(string);
    void setFirstname(string);

    //getter

    string getLastname() const;
    string getFirstname() const;

};

#endif // NAME_H
