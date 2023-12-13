/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-13 10:39:24
 */
#include <iostream>
#include <vector>
#include <list>

template <typename Container>
std::ostream &print(const Container &container, std::ostream &os = std::cout)
{
    for (auto iter = container.cbegin(); iter != container.cend(); ++iter)
        os << *iter << " ";
    return os;
}

int main()
{
    std::vector<int> v = {1, 23, 6, 4, 5, 7, 4};
    std::list<std::string> l = {"ss", "sszz", "saaas", "s333s", "ss2", " sss"};
    print(v, std::cout) << std::endl;
    print(l, std::cout) << std::endl;
    return 0;
}