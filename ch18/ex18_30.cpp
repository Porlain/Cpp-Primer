/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-25 13:58:50
 */
#include <iostream>
using namespace std;

class Class
{
};

class Base : public Class
{
public:
    Base() = default;
    Base(int) { cout << "Base(int)" << endl; }
    Base(const Base &b) {}
};

class D1 : virtual public Base
{
public:
    D1() = default;
    D1(int i) : Base(i) { cout << "D1(int)" << endl; }
    D1(const D1 &d) {}
};

class D2 : virtual public Base {
public:
	D2() = default;
	D2(int i) : Base(i) { cout << "D2(int)" << endl; }
	D2(const D2 &d) {}
};

class MI : public D1, public D2 {
public:
	MI() = default;
	MI(int i) : D1(i), D2(i) { cout << "MI(int)" << endl; }
	MI(const MI &m) {}
};

class Final : public MI, public Class {
public:
	Final() = default;
	// Final(int i) : MI(i) { cout << "Final(int)" << endl; }
	Final(int i) : MI(i), Base(i) { cout << "Final(int)" << endl; }
	Final(const Final &f) {}
};

int main()
{
	Final f(1);

	return 0;
}
