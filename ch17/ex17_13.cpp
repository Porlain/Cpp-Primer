#include <iostream>
#include <bitset>
#include <utility>
#include <string>
#include <iostream>

// class Quiz
template <std::size_t N>
class Quiz
{
public:
    // constructors
    Quiz() = default;
    Quiz(std::string &s) : bitquiz(s) {}

    // generate grade
    template <std::size_t M>
    friend std::size_t grade(Quiz<M> const &, Quiz<M> const &);

    // print
    template <std::size_t M>
    friend std::ostream &operator<<(std::ostream &, Quiz<M> const &);

    // update bitset
    void update(size_t n, bool b);

private:
    std::bitset<N> bitquiz;
};

template <std::size_t M>
std::size_t grade(Quiz<M> const &corAns, Quiz<M> const &stuAns)
{
    auto result = stuAns.bitquiz ^ corAns.bitquiz;
    result.flip();
    return result.count();
}

template <std::size_t M>
std::ostream &operator<<(std::ostream &os, Quiz<M> const &quiz)
{
    os << quiz.bitquiz;
    return os;
}

template <std::size_t N>
void Quiz<N>::update(size_t n, bool b)
{
    bitquiz.set(n, b);
}

int main()
{
    std::string s = "1010101";
    Quiz<10> quiz(s);
    std::cout << quiz << std::endl;

    quiz.update(1, true);
    std::cout << quiz << std::endl;

    std::string answer = "10011";
    std::string stu_answer = "11001";
    Quiz<5> ans(answer), stu_ans(stu_answer);
    std::cout << grade(ans, stu_ans) << std::endl;

    return 0;
}