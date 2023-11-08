#include <iostream>
using namespace std;

int swap(int num1, int num2)
{
    int temp;
    temp = num1;
    num1 = num2;
    num2 = temp;
    return num1, num2;
}

int main()
{
    cout << "Please input two numbers: " << endl;
    int num1, num2;
    cin >> num1 >> num2;
    // make sure num1 < num2
    if (num1 > num2)
    {
        num1, num2 = swap(num1, num2);
    }
    // print the numbers between num1 and num2
    for (; num1 <= num2; num1++)
    {
        cout << "Number is " << num1 << endl;
    }

    // if you want to use while rather than for, you can use the following code:
    while (num1 <= num2)
    {
        cout << "Number is " << num1++ << endl;
    }

    return 0;
}
