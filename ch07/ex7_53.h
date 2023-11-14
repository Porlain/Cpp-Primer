/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-14 13:47:57
 */

#ifndef CP5_ex7_53_h
#define CP5_ex7_53_h

class Debug
{
public:
    constexpr Debug(bool b = true) : rt(b), io(b), other(b) {}
    constexpr Debug(bool r, bool i, bool o) : rt(r), io(i), other(o) {}
    constexpr bool any() { return rt || io || other; }

    void set_rt(bool b) { rt = b; }
    void set_io(bool b) { io = b; }
    void set_other(bool b) { other = b; }

private:
    bool rt;    // runtime error
    bool io;    // I/O error
    bool other; // the others
};

#endif