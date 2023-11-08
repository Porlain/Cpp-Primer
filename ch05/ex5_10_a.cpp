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
        for (char c : str)
        {
            if (c == 'a' || c == 'A')
                ++aCnt;
            else if (c == 'e' || c == 'E')
                ++eCnt;
            else if (c == 'i' || c == 'I')
                ++iCnt;
            else if (c == 'o' || c == 'O')
                ++oCnt;
            else if (c == 'u' || c == 'U')
                ++uCnt;
        }
    }
    cout << "Number of vowel a(A): \t" << aCnt << '\n'
         << "Number of vowel e(E): \t" << eCnt << '\n'
         << "Number of vowel i(I): \t" << iCnt << '\n'
         << "Number of vowel o(O): \t" << oCnt << '\n'
         << "Number of vowel u(U): \t" << uCnt << endl;

    return 0;
}