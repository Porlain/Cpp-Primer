/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-29 10:53:25
 */
// same as ex13_11.h
#ifndef CP5_ex13_27_h
#define CP5_ex13_27_h
#include <string>
class HasPtr
{
public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0), use(new size_t(1)){};
    HasPtr(const HasPtr &hp) : ps(new std::string(*hp.ps)), i(hp.i) { ++*use; };
    HasPtr &operator=(const HasPtr &rhs_hp)
    {
        ++*rhs_hp.use;
        if (--*rhs_hp.use == 0)
        {
            delete ps;
            delete use;
        }
        ps = rhs_hp.ps;
        i = rhs_hp.i;
        use = rhs_hp.use;
        return *this;
    }
    ~HasPtr()
    {
        if (--*use == 0)
        {
            delete ps;
            delete use;
        }
    }

private:
    std::string *ps;
    int i;
    size_t *use;
};

#endif