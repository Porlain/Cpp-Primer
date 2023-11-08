#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    string str;
    while (cin >> str)
    {
        for (char ch : str)
            switch (ch)
            {
            case 'a':
            case 'A':
                ++aCnt;
                break;
            case 'e':
            case 'E':
                ++eCnt;
                break;
            case 'i':
            case 'I':
                ++iCnt;
                break;
            case 'o':
            case 'O':
                ++oCnt;
                break;
            case 'u':
            case 'U':
                ++uCnt;
                break;

            default:
                break;
            }
    }
    cout << "Number of vowel a(A): \t" << aCnt << '\n'
         << "Number of vowel e(E): \t" << eCnt << '\n'
         << "Number of vowel i(I): \t" << iCnt << '\n'
         << "Number of vowel o(O): \t" << oCnt << '\n'
         << "Number of vowel u(U): \t" << uCnt << endl;

    return 0;
}