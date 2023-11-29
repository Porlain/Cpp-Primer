/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-29 14:36:26
 */
#include "ex13_49_String.cpp"
#include <vector>

// Test reference to http://coolshell.cn/articles/10478.html
// you can use debug to know every step

void foo(String x)
{
    std::cout << x.begin() << std::endl;
}

void bar(const String &x)
{
    std::cout << x.begin() << std::endl;
}

String baz()
{
    String ret("world");
    return ret; // first avoided
}

int main()
{
    char text[] = "world";

    String s0;
    String s1("hello");
    String s2(s0);
    String s3 = s1;
    String s4(text);
    s2 = s1;

    foo(s1);
    bar(s1);
    foo("temporary");
    bar("temporary");
    String s5 = baz(); // second avoided

    std::vector<String> svec;
    svec.reserve(8);
    svec.push_back(s0);
    svec.push_back(s1);
    svec.push_back(s2);
    svec.push_back(s3);
    svec.push_back(s4);
    svec.push_back(s5);
    svec.push_back(baz());
    svec.push_back("good job");

    for (const auto &s : svec)
    {
        std::cout << s.begin() << std::endl;
    }
}
