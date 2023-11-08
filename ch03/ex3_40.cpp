#include <iostream>
#include <cstring>
using namespace std;

const char cstr1[] = "Hello";
const char cstr2[] = "world!";

int main()
{
    int new_size = strlen(cstr1) + strlen(" ") + strlen(cstr2) + 1;
    char cstr3[new_size];

    strcpy(cstr3, cstr1);
    strcat(cstr3, " ");
    strcat(cstr3, cstr2);

    cout << cstr3 << endl;
}
