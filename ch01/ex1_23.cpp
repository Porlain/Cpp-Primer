#include <iostream>
#include "include/Sales_item.h"

using namespace std;
int main()
{
    Sales_item curVal, temVal;
    if (cin >> curVal)
    {
        int count = 1;
        while (cin >> temVal)
        {
            if (curVal.isbn() == temVal.isbn())
            {
                count++;
            }
            else
            {
                cout << curVal << "occurs" << count << " times" << endl;
                curVal = temVal;
                count = 1;
            }
        }
        cout << curVal << "occurs" << count << " times" << endl;
    }
    else
    {
        cout << "Invalid input" << endl;
    }

    return 0;
}
