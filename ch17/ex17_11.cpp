#include <iostream>
#include <bitset>
#include <utility>
#include <string>
#include <iostream>

template <unsigned N>
class Quiz
{
public:
    Quiz() = default;
    Quiz(const std::string &s) : bitquiz(s) {}

private:
    std::bitset<N> bitquiz;
};

int main()
{
    std::string s1("0101010101");
    std::string s2("0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101");
    Quiz<10> q1(s1);
    Quiz<100> q2(s2);
    return 0;
}