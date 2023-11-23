/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-20 15:41:38
 */
#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

auto make_vec()
{
    return new vector<int>{};
}

auto populate(vector<int> *vec)
{
    for (int i; cin >> i; vec->push_back(i))
        ;
    return vec;
}

void print(vector<int> *vec)
{
    for (auto p : *vec)
        cout << p << " ";
    cout << endl;
}

int main()
{
    auto vec(populate(make_vec()));
    print(vec);
    delete vec;

    return 0;
}