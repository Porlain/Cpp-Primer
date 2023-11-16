/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-16 14:24:35
 */
//  Run: ./ex10_33.exe "../data/input.txt" "../data/odd.txt" "../data/even.txt"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iterator>

using namespace std;

int main(int argc, char **argv)
{
    // if you forget this, refer to section 6.2.5
    if (argc != 4)
        return -1;
    ifstream ifs(argv[1]);
    ofstream ofs_odd(argv[2]), ofs_even(argv[3]);

    istream_iterator<int> ins(ifs), eof;
    ostream_iterator<int> out_odd(ofs_odd, " "), out_even(ofs_even, "\n");

    for_each(ins, eof, [&](const int i)
             { ((i % 2 == 1) ? out_odd : out_even) = i; });
            //  it's equal to *((i % 2 == 1) ? out_odd : out_even)++ = i;

    return 0;
}
