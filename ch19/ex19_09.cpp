/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-26 14:20:30
 */
#include <iostream>
#include <typeinfo>
 
using namespace std;
 
class Base { };
class Derived: public Base { };
 
int main()
{
    Base b, *pb;
    pb = nullptr;
    Derived d;
 
    cout << typeid (int).name() << endl
         << typeid (unsigned).name() << endl
         << typeid (long).name() << endl
         << typeid (unsigned long).name() << endl
         << typeid (char).name() << endl
         << typeid (unsigned char).name() << endl
         << typeid (float).name() << endl
         << typeid (double).name() << endl
         << typeid (string).name() << endl
         << typeid (Base).name() << endl
         << typeid (b).name() << endl
         << typeid (pb).name() << endl
         << typeid (Derived).name() << endl
         << typeid (d).name() << endl
         << typeid (type_info).name() << endl;
 
    return 0;
}