/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-14 14:12:33
 */

#include <iostream>
#include <forward_list>

using namespace std;

void remove_evens_and_double_odds(forward_list<int> &data)
{
    for (auto cur = data.begin(), pre = data.before_begin(); cur != data.end();)
    {
        if (*cur % 2)
        {
            cur = data.insert_after(pre, *cur);
            advance(cur, 2);
            advance(pre, 2);
        }

        else
            cur = data.erase_after(pre);
    }
}

int main()
{
    forward_list<int> data{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    remove_evens_and_double_odds(data);
    for (auto i : data)
        cout << i << " ";
    return 0;
}
