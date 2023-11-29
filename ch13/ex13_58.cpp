/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-29 16:05:05
 */
#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;

class Foo
{
public:
    Foo sorted() &&;
    Foo sorted() const &;

private:
    vector<int> data;
};

Foo Foo::sorted() &&
{
    sort(data.begin(), data.end());
    std::cout << "&&" << std::endl; // debug
    return *this;
}

Foo Foo::sorted() const &
{
    Foo ret(*this);
    sort(ret.data.begin(), ret.data.end());
    std::cout << "&" << std::endl; // debug
    return ret;
}

int main()
{
    Foo().sorted(); // call "&&"
    Foo f;
    f.sorted(); // call "const &"
}