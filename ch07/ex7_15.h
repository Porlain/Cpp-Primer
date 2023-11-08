#ifndef CP5_ex7_15_h
#define CP5_ex7_15_h

#include <string>
#include <iostream>
using std::string;

struct Person
{
    Person() = default;
    Person() : name(" "), address(" ") {}
    Person(const string sname, const string saddress) : name(sname), address(saddress) {}
    Person(std::istream &is) { read(is, *this); }

    string name;
    string address;

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
