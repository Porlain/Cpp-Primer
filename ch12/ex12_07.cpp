/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-20 15:52:17
 */
#include <iostream>
#include <string>
#include <vector>
#include <memory>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

auto make_vec()
{
    return std::make_shared<vector<int>>();
}

auto populate(std::shared_ptr<vector<int>> vec)
{
    for (int i; cin >> i; vec->push_back(i))
        ;
    return vec;
}

void print(std::shared_ptr<vector<int>> vec)
{
    for (auto p : *vec)
        cout << p << " ";
    cout << endl;
}

int main()
{
    auto vec = populate(make_vec());
    print(vec);

    return 0;
}