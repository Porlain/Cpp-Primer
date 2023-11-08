#include <iostream>
using namespace std;
int main()
{
    int sum = 0;
    int n = 50;
    while (n < 100)
    {
        sum += n;
        n++;
    }

    // if you want to use for rather than while, you can use the following code:
    // int sum = 0;
    // for (int i = 50; i <100;i++){
    //     sum += i;
    // }
    cout << sum << endl;
    return 0;
}
