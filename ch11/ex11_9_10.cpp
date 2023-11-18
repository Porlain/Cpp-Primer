/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-17 10:58:59
 */
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <list>
#include <vector>

int main()
{
    // ex 11.9
    std::map<std::string, std::list<std::size_t>> m;

    // ex 11.10
    // can be declared.
    std::map<std::vector<int>::iterator, int> mv;
    std::map<std::list<int>::iterator, int> ml;

    // vector has operator "<" but list not operator,such as:
    std::vector<int> vi;
    mv.insert(std::pair<std::vector<int>::iterator, int>(vi.begin(), 0));

    // but when using this one the compiler complained that
    // error: no match for 'operator<' in '__x < __y'
    std::list<int> li;
    ml.insert(std::pair<std::list<int>::iterator, int>(li.begin(), 0));
    return 0;
}