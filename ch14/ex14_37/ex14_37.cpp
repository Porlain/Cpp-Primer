#include <iostream>
#include <vector>
#include <algorithm>

struct IsEqual
{
    int value;
    IsEqual(int v) : value(v) {}
    bool operator()(int elem) const
    {
        return value == elem;
    }
};

int main()
{
    std::vector<int> vec = {3, 2, 1, 4, 3, 7, 8, 6};
    // The process of calling IsEqual object in replace_if can be understood in conjunction with the lambda function in the next section.
    // The call process is similar to: 
    // using the given parameters to execute the constructor initialization, 
    // and then calling the overloaded operator() as a predicate for each iteration of vec's iter
    std::replace_if(vec.begin(), vec.end(), IsEqual(3), 5);
    for (int i : vec)
        std::cout << i << " ";
    std::cout << std::endl;
    return 0;
}