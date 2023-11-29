/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-27 19:17:54
 */
#ifndef CP5_ex13_30_h
#define CP5_ex13_30_h
#include <string>
#include <iostream>
class HasPtr
{
public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0){};
    HasPtr(const HasPtr &hp) : ps(new std::string(*hp.ps)), i(hp.i){};
    HasPtr &operator=(const HasPtr &rhs_hp)
    {
        std::string *temp_ps = new std::string(*rhs_hp.ps);
        delete ps;
        ps = temp_ps;
        i = rhs_hp.i;
        return *this;
    }
    ~HasPtr()
    {
        delete ps;
    }

    friend void swap(HasPtr &, HasPtr &);
    void show() { std::cout << *ps << std::endl; }

private:
    std::string *ps;
    int i;
};
inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    std::cout << "call swap(HasPtr& lhs, HasPtr& rhs)" << std::endl;
}

#endif