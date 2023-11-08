#include <iostream>
#include <vector>
using namespace std;

bool compare(int *arr1_begin, int *arr1_end, int *arr2_begin, int *arr2_end)
{
    if (arr1_end - arr1_begin != arr2_end - arr2_begin)
    {
        // the two arrays have different size
        return false;
    }
    else
    {
        for (int *i = arr1_begin, *j = arr2_begin; (i != arr1_end) && (j != arr2_end); i++, j++)
        {
            if (*i != *j)
                return false;
        }
    }
    return true;
}

int main()
{
    // array
    int arr1[3] = {0, 1, 2};
    int arr2[3] = {0, 2, 4};

    for (auto i = 0; i < 10; ++i)
    {
        arr1[i] = i;
        arr2[i] = i;
    }

    if (compare(begin(arr1), end(arr1), begin(arr2), end(arr2)))
        cout << "The two arrays are equal." << endl;
    else
        cout << "The two arrays are not equal." << endl;

    // vector
    vector<int> vec1 = {0, 1, 2};
    vector<int> vec2 = {0, 1, 2};

    if (vec1 == vec2)
        cout << "The two vectors are equal." << endl;
    else
        cout << "The two vectors are not equal." << endl;

    return 0;
}
