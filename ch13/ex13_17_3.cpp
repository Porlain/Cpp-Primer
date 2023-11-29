/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-24 14:59:08
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
    numbered(const numbered &hp)
    {
        cout << "copy constructor"
             << " " << hp.id << endl;
        mysn = id++;
    }

    int mysn;
    static int id;
};

int numbered::id = 10;

void f(const numbered &s) { cout << s.mysn << endl; }

int main()
{
    numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c);
    return 0;
}