/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-14 13:49:19
 */


#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::isdigit;
using std::istringstream;
using std::ostringstream;
using std::string;
using std::vector;

struct PersonInfo
{
    string name;
    vector<string> phones;
};

bool valid(const string &str)
{
    return isdigit(str[0]);
}

string format(const string &str)
{
    return str.substr(0, 3) + "-" + str.substr(3, 3) + "-" + str.substr(6);
}

int main()
{
    string filename = "../data/phonenumbers.txt";
    ifstream ifs(filename);
    if (!ifs)
    {
        cerr << "no phone numbers?" << endl;
        return -1;
    }

    string line, word;
    vector<PersonInfo> people;
    istringstream record;
    while (getline(ifs, line))
    {
        PersonInfo info;
        record.clear();
        record.str(line);
        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);
        people.push_back(info);
    }

    for (const auto &entry : people)
    {
        ostringstream formatted, badNums;
        for (const auto &nums : entry.phones)
            if (!valid(nums))
                badNums << " " << nums;
            else
                formatted << " " << format(nums);
        if (badNums.str().empty())
            cout << entry.name << " " << formatted.str() << endl;
        else
            cerr << "input error: " << entry.name
                 << " invalid number(s) " << badNums.str() << endl;
    }

    return 0;
}
