/*
 * @Author: Porlain szbj2023@163.com
 * @Date: 2023-11-13 20:09:03
 *
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved.
 */
// cause the reallocation will lead the iterators and references
// after the insertion point to invalid. Thus, we need to call reserver at first.

#include <iostream>
#include <vector>
using namespace std;

vector<int>::iterator cal_mid(vector<int> &vec)
{
    return vec.begin() + vec.size() / 2;
}

void double_and_insert(vector<int> &v, int some_val)
{
    auto mid = cal_mid(v);

    for (auto curr = v.begin(); curr != cal_mid(v); ++curr)
        if (*curr == some_val)
            ++(curr = v.insert(curr, 2 * some_val));
}

int main()
{
    vector<int> v{1, 9, 1, 9, 9, 9, 1, 1};
    double_and_insert(v, 1);

    for (auto i : v)
        cout << i << endl;
}
