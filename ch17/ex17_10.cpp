/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-19 14:52:00
 */
#include <iostream>
#include <bitset>
#include <vector>
int main()
{
    std::vector<int> vec = {1, 2, 3, 5, 8, 13, 21};
    std::bitset<32> bset1;

    for (auto i : vec)
        bset1.set(i);

    std::bitset<32> bset2;
    for (unsigned i = 0; i != 32; ++i)
        bset2[i] = bset1[i];
    
    std::cout <<bset1 <<std::endl;
    std::cout <<bset2<<std::endl;
    
    return 0;
}