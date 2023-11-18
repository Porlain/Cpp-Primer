/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-16 17:15:06
 */
// note: www.com www ww httpe://www.google.com is differnet
// if you use using namespace std, then find_if() will error reporting
// I think there is some conflict in the namespace
#include <iostream>
#include <map>
#include <algorithm>
#include <string>

int main()
{
    std::map<std::string, size_t> word_count;
    std::string word;
    while (std::cin >> word)
    {
        // here can use remove_if to erase
        // str.erase(remove_if(str.begin(), str.end(), ispunct), str.end());
        auto beg = find_if(word.cbegin(), word.cend(), ispunct);
        word.erase(beg, find_if_not(beg, word.cend(), ispunct));
        
        for (auto &c : word)
            c = tolower(c);

        ++word_count[word];
    }

    for (auto const &w : word_count)
        std::cout << w.first << " occurs: " << w.second << ((w.second > 1) ? " times" : " time") << std::endl;

    return 0;
}