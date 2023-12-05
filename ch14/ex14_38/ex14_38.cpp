/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-04 20:24:40
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>

struct CompareString
{
private:
    size_t sz;

public:
    CompareString(size_t size) : sz(size) {}
    bool operator()(const std::string &str) const
    {
        return str.size() == sz;
    }
};

int main()
{
    std::ifstream in("../../data/storyDataFile.txt");
    if (!in)
        return -1;
    std::vector<std::string> vec;
    for (std::string str; in >> str; vec.push_back(str))
        ;

    int sum = 0;
    for (int i = 1, n = 0; i < 10; ++i)
    {
        for (auto iter = vec.begin(); iter != vec.end();)
        {
            iter = find_if(iter + 1, vec.end(), CompareString(i));
            if (iter != vec.end())
                ++n;
        }
        std::cout << "length:" << i << "," << n << std::endl;
        sum += n;
        n = 0;
    }
    std::cout << "length between [1, 9]:" << sum << std::endl;
    std::cout << "length upper 10:" << vec.size() - sum - 1<< std::endl;
    return 0;
}