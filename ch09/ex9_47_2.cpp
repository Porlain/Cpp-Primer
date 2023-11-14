/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-14 15:40:29
 */

#include <string>
#include <iostream>

using namespace std;

int main()
{
    string numbers{"123456789"};
    string alphabet{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string str{"ab2c3d7R4E6"};
    cout << "numeric characters: ";
    for (int pos = 0; (pos = str.find_first_not_of(alphabet, pos)) != string::npos; ++pos)
        cout << str[pos] << " ";
    cout << endl;

    cout << "alphabetic characters: ";
    for (int pos = 0; (pos = str.find_first_not_of(numbers, pos)) != string::npos; ++pos)
        cout << str[pos] << " ";
    cout << endl;
    return 0;
}