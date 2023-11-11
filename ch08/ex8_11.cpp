/*
 * @Author: Porlain szbj2023@163.com
 * @Date: 2023-11-11 15:22:25
 *
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved.
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using std::cin;
using std::istringstream;
using std::string;
using std::vector;

struct PersonInfo
{
    string name;
    vector<string> phones;
};

int main(){
    string line, word;
    vector<PersonInfo> people;
    istringstream record;
    while (getline(cin, line))
    {
        PersonInfo info;
        record.clear();
        record.str(line);
        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);
        people.push_back(info);
    }
    
    for (auto &p : people)
    {
        std::cout << p.name << " ";
        for (auto &s : p.phones)
            std::cout << s << " ";
        std::cout << std::endl;
    }
    
    return 0;
}