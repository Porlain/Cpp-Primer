/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-26 10:46:12
 */
#include <cstdlib>
#include <new>

void *operator new(size_t size)
{
    if (void *mem = malloc(size))
        return mem;
    else
        throw std::bad_alloc();
}

void operator delete(void *mem) { free(mem); }

int main()
{

    return 0;
}