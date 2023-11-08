#include <iostream>
using namespace std;

int main()
{
    int arr[3][4] =
        {
            {0, 1, 2, 3},
            {4, 5, 6, 7},
            {8, 9, 10, 11}};
    // range for
    // for (const int &row[4] : arr)
    // {
    //     for (int col : row)
    //     {
    //         cout << col << endl;
    //     }
    // }

    // for loop
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //         cout << arr[i][j] << endl;
    // }

    // using pointers
    for (int (*row)[4] = begin(arr); row != end(arr); row++)
    {
        // pay attention to *
        for (int *col = begin(*row); col != end(*row); col++)
            cout << *col << endl;
    }

    return 0;
}
