#include <iostream>
using namespace std;

int main()
{
    int arr[3][4] =
        {
            {0, 1, 2, 3},
            {4, 5, 6, 7},
            {8, 9, 10, 11}};
    using int_array = int[4];

    // range for
    for (int_array &row : arr)
    {
        for (int col : row)
        {
            cout << col << " ";
        }
    }

    // for loop
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //         cout << arr[i][j] << endl;
    // }

    // using pointers
    // for (int_array* p = arr; p != arr + 3; ++p)
    //     for (int *q = *p; q != *p + 4; ++q)
    //         cout << *q << " ";
    // cout << endl;

    return 0;
}
