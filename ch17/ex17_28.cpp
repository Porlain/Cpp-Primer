/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-20 18:18:15
 */
#include <iostream>
#include <random>
#include <string>

// default version
unsigned random_func()
{
    static std::default_random_engine e;
    static std::uniform_int_distribution<unsigned> ud;
    return ud(e);
}

// with seed spicified
unsigned random_func(unsigned seed)
{
    static std::default_random_engine e(seed);
    static std::uniform_int_distribution<unsigned> ud;
    return ud(e);
}

// with seed and range spicified
unsigned random_func(unsigned seed, unsigned min, unsigned max)
{
    static std::default_random_engine e(seed);
    static std::uniform_int_distribution<unsigned> ud(min, max);
    return ud(e);
}

int main()
{
    std::cout << random_func() << std::endl;
    std::cout << random_func(2) << std::endl;
    std::cout << random_func(19, 1, 10) << std::endl;
    return 0;
}