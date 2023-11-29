/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-24 14:59:33
 */
#include <iostream>

using namespace std;

class numbered
{
public:
    numbered()
    {
        cout << "Composite constructor"
             << " " << id << endl;
        mysn = id++;
    }
    int mysn;
    static int id;
};

int numbered::id = 1;

void f(numbered s) { cout << s.mysn << endl; }

int main()
{
    numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c);
    return 0;
}