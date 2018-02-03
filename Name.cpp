#include "Name.h"

Name::Name()
{

}

Name::Name(string fname, string lname)
{
    firstname = fname;
    lastname = lname;
}

/* Name member function setLastname:
 * Input:
 * lastname - object's last name
 * Process:
 * sets the value member variable last
 * Output:
 * none
 */
void Name::setLastname(string last)
{
    lastname = last;
    return;
}

/* Name member function setFirstname:
 * Input:
 * firstname - object's first name
 * Process:
 * sets the value member variable first
 * Output:
 * none
 */
void Name::setFirstname(string first)
{
     firstname = first;
     return;
}

/* Name member function getLastname:
 * Input:
 * none
 * Process:
 * retrieves the value of member variable last
 * Output:
 * returns the object's last name
 */
string Name::getLastname() const
{
 return (lastname);
}

/* Name member function getFirstname:
 * Input:
 * none
 * Process:
 * retrieves the value of member variable first
 * Output:
 * returns the object's first name
 */
string Name::getFirstname() const
{
 return (firstname);
}

