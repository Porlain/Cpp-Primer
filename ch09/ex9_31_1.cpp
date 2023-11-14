/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-14 14:09:52
 */
#include <iostream>
#include <list>

using namespace std;

void remove_evens_and_double_odds(list<int> &data)
{
    for (auto iter = data.begin(); iter != data.end();)
    {
        if (*iter % 2)
        {
            iter = data.insert(iter, *iter);
            // equal to ++iter; ++iter;
            // list no iter += 2;
            advance(iter, 2);
        }

        else
            iter = data.erase(iter);
    }
}

int main()
{
    list<int> data{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    remove_evens_and_double_odds(data);
    for (auto i : data)
        cout << i << " ";
    return 0;
}
