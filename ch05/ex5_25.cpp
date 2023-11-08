#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{
    for (int i, j; cout << "Input two integers:\n", cin >> i >> j;)
    {
        try
        {
            if (j == 0)
                throw runtime_error("divisor is 0");
            cout << i / j << endl;
        }
        catch (runtime_error err)
        {
            cout << err.what() << "\nTry again? Enter y or n" << endl;
            char c;
            cin >> c;
            if (!cin || c == 'n')
                break;
        }
    }

    return 0;
}
