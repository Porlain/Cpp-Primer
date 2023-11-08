#include <iostream>
#include "include/Sales_item.h"

using namespace std;
int main()
{
    Sales_item total;
    if (cin >> total)
    {
        Sales_item item;
        while (cin >> item)
        {
            if (total.isbn() == item.isbn())
            {
                total += item;
            }
            else
            {
                cout << total << endl;
                total = item;
            }
        }
        cout << total << endl;
    }
    else
    {
        cerr << "Invalid input" << endl;
    }

    return 0;
}
