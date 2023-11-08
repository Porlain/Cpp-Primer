#include <iostream>
#include <string>

using namespace std;

int main()
{
    string read, tmp;
    while (cin >> read)
        if (read == tmp)
            break;
        else
            tmp = read;

    // cin.eof():determine if the stream has reached the end of file.
    // In fact, when we use CTRL+Z to stop the program, cin.eof() is true
    if (cin.eof())
        cout << "no word was repeated." << endl;
    else
        cout << read << " occurs twice in succession." << endl;

    return 0;
}
