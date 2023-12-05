#include <iostream>
#include <string>

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
    std::cout << getInput() << std::endl;
    return 0;
}