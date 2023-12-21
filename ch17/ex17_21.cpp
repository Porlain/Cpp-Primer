/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-20 13:53:18
 * @See ex8_13.cpp, but I can't remember clearly, so I wrote a new one
 */

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

struct PersonInfo
{
    string name;
    vector<string> phones;
};

bool read_record(istream &is, vector<PersonInfo> &people)
{
    if (is)
    {
        string line, phone;
        while (getline(is, line))
        {
            PersonInfo info;
            istringstream record(line);
            record.clear();
            record >> info.name;
            while (record >> phone)
                info.phones.push_back(phone);
            people.push_back(info);
        }
        return true;
    }
    return false;
}

bool valid(const smatch &m)
{
    // if there is an open parenthesis before the area code
    if (m[1].matched)
        // the area code must be followed by a close parenthesis
        // and followed immediately by the rest of the number or a space
        return m[3].matched && (m[4].matched == 0 || m[4].str() == " ");
    else
        // then there can't be a close after the area code
        // the delimiters between the other two components must match
        return !m[3].matched && m[4].str() == m[6].str();
}

int main()
{
    // Regular expression matching rules
    string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
    regex r(phone);
    // Save the contents of the txt file to the vector
    vector<PersonInfo> people;
    ifstream ifs("../data/record.txt");

    if (read_record(ifs, people))
    {
        smatch result;
        for (auto person : people)
        {
            ostringstream formatted, badNums;
            for (auto it = person.phones.begin(); it != person.phones.end(); ++it)
                if (regex_match(*it, result, r) && valid(result))
                    formatted << " " << *it;
                else
                    badNums << " " << *it;

            if (!formatted.str().empty())
                cout << person.name << " " << formatted.str() << endl;
            if (!badNums.str().empty())
                cout << person.name << " invalid number(s) " << badNums.str() << endl;
        }
    }

    return 0;
}
