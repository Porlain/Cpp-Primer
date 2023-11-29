/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-29 16:03:04
 */

#ifndef CP5_ex13_19_h
#define CP5_ex13_19_h
#include <string>
using std::string;
class Employee
{
    Employee() { id_ = temp_id++; }
    Employee(const string &name)
    {
        id_ = temp_id++;
        name_ = name;
    };
    Employee(const Employee &) = delete;
    Employee &operator=(const Employee &) = delete;
    
    const int id() const { return id_; };

private:
    string name_;
    static int temp_id;
    int id_;
};

int Employee::temp_id = 0;

#endif