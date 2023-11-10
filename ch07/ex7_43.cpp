/*
 * @Author: Porlain szbj2023@163.com
 * @Date: 2023-11-10 15:59:07
 *
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved.
 */
#include <vector>
using std::vector;

class NoDefault
{
public:
    NoDefault(int i) {}
};

class C
{
public:
    C() : test(0) {}

private:
    NoDefault test;
};

int main()
{
    C c;
    vector<C> vec(10);
    return 0;
}