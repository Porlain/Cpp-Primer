/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-21 11:15:44
 */
#include <iostream>
#include <string>
#include <memory>

int main()
{
    std::allocator<std::string> alloc;
    int n;
    std::cout << "Please input n: ";
    std::cin >> n;
    auto const p = alloc.allocate(n);
    std::string s;
    auto q = p;
    while (q != p + n && std::cin >> s)
        alloc.construct(q++, s);

    while (q != p)
    {
        std::cout << *--q << " ";
        alloc.destroy(q);
    }
    alloc.deallocate(p, n);

    return 0;
}