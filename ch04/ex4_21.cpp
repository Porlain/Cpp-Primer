#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> ivec{1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (auto i : ivec)
    {
        cout << ((i % 2 == 0) ? i : i * 2) << " ";
    }
    cout << endl;

    return 0;
}
