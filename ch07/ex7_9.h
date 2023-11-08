#ifndef CP5_ex7_09_h
#define CP5_ex7_09_h

#include <string>
#include <iostream>
using std::string;

struct Person
{
    string name;
    string address;
    // if you have any questions about this, please refer to ex7_5.h
    // &:Use the object that calls the function instead of a copy of the object
    // const front function: When calling this function, the value of the protected object remains unchanged
    const string &getname() const { return name; }
    const string &getaddress() const { return address; }
};

std::istream &read(std::istream &is, Person &person)
{
    return is >> person.name >> person.address;
}

std::ostream &print(std::ostream &os, const Person &person)
{
    return os << person.name << " " << person.address;
}

#endif
