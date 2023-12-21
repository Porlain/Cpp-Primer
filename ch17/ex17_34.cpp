/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-21 13:54:30
 */
#include <cstddef>
#include <iostream>
#include <string>
#include <iomanip>
#include <math.h>

using namespace std;

#include <bitset>
using std::bitset;

bool get_status()
{
    return false;
}

int main()
{
    bool b;
    cout << "default bool values: " << true << " "
         << false << "\nalpha bool values:" << boolalpha
         << true << " " << false << endl;
    bool bool_val = get_status();
    cout << boolalpha // Set the internal state of cout
         << bool_val
         << noboolalpha; // Reset internal state to default format
    cout << endl;

    const int ival = 15, jval = 1024; // Const, therefore the value remains unchanged forever
    cout << "default: " << 20 << " " << 1024 << endl;
    cout << "octal: " << oct << 20 << " " << 1024 << endl;
    cout << "hex: " << hex << 20 << " " << 1024 << endl;
    cout << "decimal: " << dec << 20 << " " << 1024 << endl;
    cout << showbase; // Display base when printing integer values
    cout << "default: " << 20 << " " << 1024 << endl;
    cout << "octal: " << oct << 20 << " " << 1024 << endl;
    cout << "hex: " << hex << 20 << " " << 1024 << endl;
    cout << "decimal: " << dec << 20 << " " << 1024 << endl;
    cout << noshowbase;                // Reset the state of the flow
    cout << 10.0 << endl;              // Print 10
    cout << showpoint << 10.0          // Print10.0000
         << noshowpoint << endl;       // Restore default mode for decimal points
    cout << showpos << 10.0 << endl;   // Non negative printing+
    cout << noshowpos << 10.0 << endl; // Non negative numbers do not print+

    cout << uppercase << showbase << hex
         << "printed in hexadecimal: " << 20 << " " << 1024
         << nouppercase << noshowbase << dec << endl;

    int i = -16;
    double d = 3.14159;
    // Fill in the first column with white space, using a minimum of 12 positions in the output
    cout << "i: " << setw(12) << i << " next col " << '\n'
         << "d: " << setw(12) << d << " next col " << '\n';
    // Fill in the first column and align all columns to the left
    cout << left
         << "i: " << setw(12) << i << " next col " << '\n'
         << "d: " << setw(12) << d << " next col " << '\n'
         << right; // Restore normal alignment

    // Fill in the first column and align all columns to the right
    cout << right
         << "i: " << setw(12) << i << " next col " << '\n'
         << "d: " << setw(12) << d << " next col " << '\n';

    // Fill in the first column but within the domain
    cout << internal
         << "i: " << setw(12) << i << " next col " << '\n'
         << "d: " << setw(12) << d << " next col " << '\n';

    // Fill in the first column with # as the fill in character
    cout << setfill('#')
         << "i: " << setw(12) << i << " next col " << '\n'
         << "d: " << setw(12) << d << " next col " << '\n'
         << setfill(' ');

    cout << unitbuf; // All output operations will immediately flush the buffer
    cout << "default format: " << 100 * sqrt(2.0) << '\n'
         << "scientific: " << scientific << 100 * sqrt(2.0) << '\n'
         << "fixed decimal: " << fixed << 100 * sqrt(2.0) << '\n'
         << endl
         << endl;
    cout << nounitbuf;      // Return to normal buffering mode
    cout << "hi!" << endl;  // Output hi and a line break, then flush the buffer
    cout << "hi!" << flush; // Output hi, then flush the buffer without attaching any additional characters
    cout << "hi!" << ends;  // Output hi and a null character, then flush the buffer

    char ch;
    cin >> noskipws; // Set cin to read whitespace characters

    while (cin >> ch)
        cout << ch;
    cin >> skipws; // Restore the cin to its default state, thereby discarding whitespace characters

    return 0;
}