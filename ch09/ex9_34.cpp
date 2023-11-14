/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-14 14:21:16
 */

//  @Answer "infinite loop". Becasue the `++iter` is outside of the scope of the `while` loop.
//          Fixed as following.

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> data { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    for(auto cur = data.begin(); cur != data.end(); ++cur)
        if(*cur & 0x1)
            cur = data.insert(cur, *cur), ++cur;
    
    for (auto i : data)
        cout << i << " ";

    return 0;
}
