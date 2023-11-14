/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-14 13:41:44
 */


#include <iostream>
#include <forward_list>

using namespace std;

void remove_odds(forward_list<int> &data)
{
    auto prev = data.before_begin();
    auto curr = data.begin();
    while (curr != data.end())
    {
        if (*curr % 2 == 1)
            curr = data.erase_after(prev);
        else
        {
            prev = curr;
            ++curr;
        }
    }
}

int main()
{
    forward_list<int> data = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    remove_odds(data);
    for (auto i : data)
        cout << i << " ";

    return 0;
}