/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-21 14:35:38
 * Perhaps this file does not meet the requirements of the title
 */
#include <iostream>
#include <fstream>

using namespace std;
int main()
{
    ifstream in("../data/letter.txt");
    if (!in)
    {
        cerr << "the file open error!" << endl;
        return -1;
    }

    const size_t size = 300;
    char text[size];
    while (!in.eof())
    {
        in.getline(text, size);
        cout << text << endl;

        // No delimiter encountered, but the number of characters read reached the specified maximum size-1
        if (!in.good())
        {
            if (in.gcount() == size - 1) // size-1
                in.clear();              // Reset the flow to a valid state
            else
                break;
        }
    }
    in.close();
    return 0;
}