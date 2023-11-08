#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str("Hello, world!");
    // question one
    // int i = str.size();
    // // or decltype(str.size()) i  = str.size();
    // while(i>=0){
    //     str[i--]='X';
    // }

    // question two
    for(int i = 0; i < str.size();i++){
        str[i]='X';
    }
    cout << str << endl;
    return 0;
}