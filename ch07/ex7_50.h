/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-14 13:47:45
 */

#ifndef CP5_ex7_50_h
#define CP5_ex7_50_h

#include <string>
#include <iostream>
using std::string;

struct Person
{
    friend std::istream &read(std::istream &is, Person &person);
    friend std::ostream &print(std::ostream &os, const Person &person);

public:
    Person() = default;
    Person() : name(" "), address(" ") {}
    Person(const string sname, const string saddress) : name(sname), address(saddress) {}
    // only this function
    explicit Person(std::istream &is) { read(is, *this); }

    const string &getname() const { return name; }
    const string &getaddress() const { return address; }

private:
    string name;
    string address;
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
