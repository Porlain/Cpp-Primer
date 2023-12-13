/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-09 15:11:46
 */
#include <iostream>
#include <string>
using namespace std;

template <typename Arr>
void print(const Arr &arr)
{
    for (auto const &elem : arr)
        cout << elem << " ";
    cout << endl;
}

int main()
{
    string s[] = {"ssss", "aaa", "ssssss"};
    char c[] = {'a', 'b', 'c', 'd'};
    int i[] = {1};
    print(i);
    print(c);
    print(s);
    return 0;
}