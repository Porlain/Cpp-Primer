/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-19 17:28:15
 */
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <regex>
using std::regex;
using std::sregex_iterator;

int main()
{
    std::string pattern("[[:alpha:]]*[^c]ei[[:alpha:]]*");
    std::regex r(pattern, std::regex::icase);
    std::smatch results;
    std::string s("freind receipt theif receive");

    std::vector<std::string> vec{"neighbor", "albeit", "beige", "feint", "heir", "reign", "their",
                                 "counterfeit", "foreign", "inveigh", "rein", "veil", "deign",
                                 "forfeit", "inveigle", "seize", "veineiderdown", "freight",
                                 "leisure", "skein", "weigheight", "heifer", "neigh", "sleigh",
                                 "weighteither", "height", "neighbour", "sleight", "weirfeign",
                                 "heinous", "neither", "surfeit", "weird"};

    for (sregex_iterator it(s.begin(), s.end(), r), end_it; it != end_it; ++it)
    {
        if (std::find(vec.begin(), vec.end(), it->str()) != vec.end())
            continue;
        cout << it->str() << endl;
    }
}