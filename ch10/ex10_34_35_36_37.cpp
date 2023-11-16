/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-16 14:47:02
 */
#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <iterator>

using namespace std;

int main(int argc, char **argv)
{
    vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    // 10.34
    for_each(vec.crbegin(), vec.crend(), [](const int &iter)
             { cout << iter << " "; });
    cout << endl;

    // 10.35
    for (auto iter = vec.cend() - 1; iter != vec.cbegin() - 1; --iter)
        cout << *iter << " ";
    cout << endl;

    // 10.36
    list<int> lst = {1, 2, 3, 4, 0, 5, 6};
    auto found_0 = find(lst.crbegin(), lst.crend(), 0);
    cout << distance(found_0, lst.crbegin()) << endl;
    cout << distance(found_0, lst.crend()) << endl;

    // 10.37
    list<int> list2(8 - 3);
    copy(vec.cbegin() + 3, vec.cbegin() + 8, list2.rbegin());
    for (auto i : list2)
        cout << i << " ";
    cout << endl;
    //     0, 1, 2, 3, 4, 5, 6, 7, 8, 9
    //           ^              ^
    //          rend          rbegin
    // @note: cbegin and cend the range [first, last), [2, 8)
    //        so rbegin and rend the range [7, 2)
    //        std::copy copies the range [first, last) into result.
    //        hence, the arguments here denote:
    //        [7 6 5 4 3 2)
    //                   ^ this one is specified but not included.

    return 0;
}
