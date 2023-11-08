#ifndef CP5_ex7_05_h
#define CP5_ex7_05_h

#include <string>
using std::string;

class Person
{
    string name;
    string address;

    // return an object which call this function
    string getname() const { return name; }
    string getaddress() const { return address; }

    // In fact, we can write it in the following form
    // &:Use the object that calls the function instead of a copy of the object
    // const front function: When calling this function, the value of the protected object remains unchanged
    // const string &getname() const { return name; }
    // const string &getaddress() const { return address; }
};

#endif
