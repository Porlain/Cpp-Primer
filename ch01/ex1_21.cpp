#include <iostream>
#include "include/Sales_item.h"

using namespace std;
int main()
{
    Sales_item book1, book2;
    cin >> book1 >> book2;
    if (book1.isbn() == book2.isbn())
    {
        cout << "Book's isbn is same" << endl;
        cout << book1 + book2 << endl;
    }
    else
        cerr << "Book's isbn is different" << endl;

    return 0;
}
