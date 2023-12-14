#pragma once
#include <iostream>

class DebugDelete
{
public:
    DebugDelete(std::ostream &s = std::cerr) : os(s) {}
    template <typename T>
    void operator()(T *p) const
    {
        delete p;
    }

private:
    std::ostream &os;
};
