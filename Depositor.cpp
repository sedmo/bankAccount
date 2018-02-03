#include "Depositor.h"


//Depositor default constructor
Depositor::Depositor()
{
    social_security_number=" "; //ctor

}

/* Depositor constructor 2 - accepts 2 arguments:
 * Input:
 * pName - Name type
 * pSSN - member value social_security_number
 * Process:
 * default's the object's
 */
Depositor::Depositor(string pSSN, Name pname )
{

    social_security_number = pSSN;//ctor
    name = pname;
}

/* Depositor member function setSsn:
 * Input:
 * pSSN - object's SSN
 * Process:
 * sets the value member variable
 * social_security_number
 * Output:
 * none
 */
void Depositor::setSsn(string pSSN)
{
    social_security_number = pSSN;
}
/* Depositor member function setName:
 * Input:
 * pName - Name object from user
 * Process:
 * set pName as the new object for name
 * member variable
 * Output:
 * none
 */
void Depositor::setName(Name pName)
{
    name = pName;
}

/* Depositor member function getSsn:
 * Input:
 * none
 * Process:
 * retrieve the value stored in the
 * member variable social_security_number
 * Output:
 * none
 */

string Depositor::getSsn() const
{
    return (social_security_number);
}

/* Depositor member function getName:
 * Input:
 * none
 * Process:
 * return the value stored in object name
 * Output:
 * none
 */

Name Depositor::getName() const
{
    return (name);
}
