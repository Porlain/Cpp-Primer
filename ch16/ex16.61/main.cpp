/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-18 10:50:27
 */
#include <iostream>
#include <memory>
#include <string>

namespace ch16
{
    template <typename T, typename... Args>
    auto make_shared(Args &&...args) -> std::shared_ptr<T>
    {
        return std::shared_ptr<T>(new T(std::forward<Args>(args)...));
    }
}

struct Foo
{
    explicit Foo(int b) : bar(b) {}
    int bar;
};

int main()
{
    auto num = ch16::make_shared<int>(42);
    std::cout << *num << std::endl;

    auto str = ch16::make_shared<std::string>(10, 'c');
    std::cout << *str << std::endl;

    auto foo = ch16::make_shared<Foo>(99);
    std::cout << foo->bar << std::endl;
    return 0;
}