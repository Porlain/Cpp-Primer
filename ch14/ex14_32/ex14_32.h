/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-04 16:03:15
 */
#ifndef STRBLOBPTR_POINTER_H
#define STRBLOBPTR_POINTER_H

class StrBlobPtr;
class StrBlobPtr_point
{
public:
    StrBlobPtr_point() = default;
    StrBlobPtr_point(StrBlobPtr *ps) : p(ps) {}

    StrBlobPtr &operator*() const;
    StrBlobPtr *operator->() const;

private:
    StrBlobPtr *p = nullptr;
};

#endif