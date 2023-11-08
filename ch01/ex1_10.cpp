#include <iostream>
using namespace std;

int main()
{
    int n = 10;
    while (n >= 0)
    {
        cout << n-- << endl;
    }
    // if you want to use for rather than while, you can use the following code:
    // for(int i = 0; i < 10; i++){
    //     cout << i-- << endl;
    // }

    return 0;
}
