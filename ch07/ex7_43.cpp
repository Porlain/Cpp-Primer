/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-14 13:47:37
 */

#include <vector>
using std::vector;

class NoDefault
{
public:
    NoDefault(int i) {}
};

class C
{
public:
    C() : test(0) {}

private:
    NoDefault test;
};

int main()
{
    C c;
    vector<C> vec(10);
    return 0;
}