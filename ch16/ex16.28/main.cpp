#include <iostream>
#include <string>
#include "shared_pointer.h"

int main()
{
    auto foo = SharedPointer<int>{ new int(42) };
    auto bar(foo) ;
    std::cout << *foo << std::endl;
    std::cout << foo.use_count() << std::endl;

    auto string_ptr = SharedPointer<std::string>{ new std::string{ "Yue" } };
    std::cout << *string_ptr << std::endl;
    std::cout << string_ptr->size() << std::endl;

    return 0;
}