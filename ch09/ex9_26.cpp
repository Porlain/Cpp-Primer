/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-14 13:45:35
 */

#include <iostream>
#include <vector>
#include <list>

using namespace std;
int main()
{
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};

    // init, ia is an array, the address of the array is passed during creation, so we used begin(ia) and end(ia)
    vector<int> vec(ia, end(ia));
    list<int> list1(ia, end(ia));

    // remove odd value
    // if you use list1.erase(iter) rather than iter = list1.erase(iter)
    // it will be a endless loop, because erase return an iterator referring to the location after the (last) element that was removed.
    // and if you use list1.erase(iter) the iterator originally pointing to list1 will disappear
    // you can see section 9.3.6

    // it looks like this:
    //    iter      ------------->     iter
    //     ↓        ------------->         ↘ 3   3 However, 3 is no longer in list1, so the iterator disappeared
    // 1 2 3 4 5    ------------->  1 2   4 5   


    // and if you use iter = list1.erase(iter), it looks like:
    //    iter      ------------->     iter
    //     ↓        ------------->      ↘       3  The iterator is still point to list1
    // 1 2 3 4 5    ------------->  1 2   4 5   
    for (auto iter = list1.begin(); iter != list1.end();)
        if (*iter % 2 == 1)
            iter = list1.erase(iter);
        else
            ++iter;

    // remove even value
    // vec.erase(iter) and iter = vec.erase(iter)
    // you can use both of them
    for (auto iter = vec.begin(); iter != vec.end();)
        if (*iter % 2 == 0)
            iter = vec.erase(iter);
        else
            ++iter;

    // print
    cout << "list : ";
    for (auto i : list1)
        cout << i << " ";
    cout << "\nvector : ";
    for (auto i : vec)
        cout << i << " ";
    cout << endl;
    return 0;
}