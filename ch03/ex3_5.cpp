#include <iostream>
#include <string>
using namespace std;

int main()
{

    // ===================================================================================================
    // question one
    // string concatenated;
    // for (string str; cin >> str; concatenated += str);
    // cout << "The concatenated string is " << concatenated << endl;

    // ===================================================================================================
    // question two
    string concatenated;
    for (string str; cin >> str; concatenated += (concatenated.empty() ? "" : " ") + str)
        ;
    cout << "The concatenated string is " << concatenated << endl;

    return 0;
}