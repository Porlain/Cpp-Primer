/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-24 13:48:27
 */
// You can use debug mode to view the output of each step
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
struct X
{
    X() { cout << "X()" << endl; }
    X(const X &) { cout << "X(const X&)" << endl; }
    X &operator=(const X &)
    {
        cout << "X& operator=(const X&)" << endl;
        return *this;
    }

    ~X() { cout << "~X()" << endl; }
};

void f(const X &rx, X x)
{
    std::vector<X> vec;
    vec.reserve(2);
    vec.push_back(rx);
    vec.push_back(x);
}

int main()
{
    X *px = new X;
    f(*px, *px);
    delete px;
    return 0;
}