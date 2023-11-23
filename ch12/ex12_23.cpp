/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-21 10:29:07
 */
#include <iostream>
#include <string>
#include <cstring>

int main()
{   
    // char
    const char a[] = "hello";
    const char b[] = "porlain";
    char *con_char = new char[strlen("hello" "porlain") + 1];
    std::strcat(con_char, a);
    std::strcat(con_char, b);
    std::cout << con_char << std::endl;
    delete[] con_char;

    // string
    const std::string str1 = "hi";
    const std::string str2 = "word";
    int n = str1.size() + str2.size();
    // In fact, here we can define an array with a length of 1
    // con_string is "hiword" and "" "" "" ...
    std::string *con_string = new std::string[n]; 
    con_string[0] = str1 + str2;
    std::cout << con_string[0] << std::endl;

    return 0;
}
