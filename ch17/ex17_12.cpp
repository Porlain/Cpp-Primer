#include <bitset>
#include <iostream>

template <std::size_t N>
class Quiz
{
public:
    template <std::size_t M>
    friend std::ostream &operator<<(std::ostream &, const Quiz<M> &);

public:
    Quiz(std::string &s) : bitquiz(s) {}
    void update(size_t n, bool b);

private:
    std::bitset<N> bitquiz;
};

template <std::size_t M>
std::ostream &operator<<(std::ostream &os, const Quiz<M> &q)
{
    os << q.bitquiz;
    return os;
}

template <std::size_t N>
void Quiz<N>::update(size_t n, bool b)
{
    bitquiz.set(n, b);
}

int main()
{
    std::string s1("0101010101");
    std::string s2("0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101");
    Quiz<10> q1(s1);
    Quiz<100> q2(s2);

    q1.update(0, false);
    std::cout << q1 << std::endl;

    return 0;
}
