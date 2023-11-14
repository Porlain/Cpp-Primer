/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-14 19:49:42
 */

#include <stack>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string expression{"This is (Porlain)."};
    bool judge = false;
    stack<float> stack1;
    for (auto s : expression)
    {
        if (s == '(')
        {
            judge = true;
            continue;
        }
        else if (s == ')')
            judge = false;

        if (judge)
            stack1.push(s);
    }

    string res;
    while (!stack1.empty())
    {
        res += stack1.top();
        stack1.pop();
    }

    expression.replace(expression.find('(') + 1, res.size(), res);

    cout << expression << endl;

    return 0;
}