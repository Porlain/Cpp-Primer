#include <iostream>
using namespace std;

int main()
{
    int sum = 0, value = 0;
    // if you want to exit the program, you should use Ctrl-Z
    while (cin >> value)
    {
        sum += value;
    }
    // if you want to use for rather than while, you can use the following code:
    // for(;cin>>value;){
    //     sum+=value;
    // }

    // For a more concise version, refer to the following code:
    // for(int value = 0;cin>>value; sum+=value);
    cout << sum << endl;
    return 0;
}