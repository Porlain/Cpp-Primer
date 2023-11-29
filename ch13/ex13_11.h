/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-24 11:21:17
 */
#ifndef CP5_ex13_11_h
#define CP5_ex13_11_h
#include <string>
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
    }
    ~HasPtr(){
        delete ps;
    }

private:
    std::string *ps;
    int i;
};

#endif