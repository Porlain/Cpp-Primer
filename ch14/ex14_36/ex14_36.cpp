#include <iostream>
#include <string>
#include <vector>

struct GetInput
{
public:
    GetInput(std::istream &i = std::cin) : in(i) {}
    std::string operator()() const
    {
        std::string str;
        in >> str;
        return in ? str : std::string();
    }

private:
    std::istream &in;
};

int main()
{
    GetInput getInput;
    std::vector<std::string> vec;
    for (std::string temp; !(temp = getInput()).empty(); vec.push_back(temp))
        ;
    for (const auto &str : vec)
        std::cout << str << " ";
    std::cout << std::endl;
    return 0;
}