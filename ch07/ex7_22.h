/*
 * @Author: Porlain szbj2023@163.com
 * @Date: 2023-11-08 14:39:03
 * @LastEditors: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-08 14:45:33
 * @FilePath: \cpp_learning\ch07\ex7_22.h
 * @Description: 
 * 
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved. 
 */

#ifndef CP5_ex7_22_h
#define CP5_ex7_22_h

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
    Person(std::istream &is) { read(is, *this); }

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
