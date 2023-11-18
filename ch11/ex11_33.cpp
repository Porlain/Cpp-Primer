/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-18 14:12:28
 */
#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

using std::cout;
using std::endl;
using std::ifstream;
using std::map;
using std::multimap;
using std::string;

map<string, string> buildMap(ifstream &ifs_map)
{
    map<string, string> trans_map;
    for (string key, val; ifs_map >> key && getline(ifs_map, val);)
    {
        if (val.size() > 1)
            trans_map[key] = val.substr(1);
        else
            throw std::runtime_error("no rlue for " + key);
    }
    return trans_map;
}

string transform(const string &s, const map<string, string> &m)
{
    auto it = m.find(s);
    return it == m.cend() ? s : it->second;
}

void word_tarnsform(ifstream &ifs_map, ifstream &ifs_content)
{
    auto trans_map = buildMap(ifs_map);
    for (string text; getline(ifs_content, text);)
    {
        std::istringstream iss(text);
        for (string word; iss >> word;)
            cout << transform(word, trans_map) << " ";
        cout << endl;
    }
}

int main()
{
    ifstream ifs_map("../data/word_transformation.txt"), ifs_content("../data/given_to_transform.txt");
    if (ifs_map && ifs_content)
        word_tarnsform(ifs_map, ifs_content);
    else
        std::cerr << "can't find the documents." << endl;

    return 0;
}