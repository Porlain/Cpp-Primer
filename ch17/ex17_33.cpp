/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-21 11:13:18
 * @See ex11_33.cpp
 */
#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <ctime>
#include <random>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::map;
using std::multimap;
using std::string;
using std::vector;

map<string, vector<string>> buildMap(ifstream &ifs_map)
{
    map<string, vector<string>> trans_map;
    for (string key, val; ifs_map >> key && getline(ifs_map, val);)
    {
        if (val.size() > 1)
        {
            trans_map[key].push_back(val.substr(1));
            trans_map[key].push_back("replace_2");
            trans_map[key].push_back("replace_3");
            trans_map[key].push_back("replace_4");
        }

        else
            throw std::runtime_error("no rlue for " + key);
    }
    return trans_map;
}

string transform(const string &s, const map<string, vector<string>> &m)
{
    static std::default_random_engine e(time(0));

    auto it = m.find(s);

    static std::uniform_int_distribution<unsigned> u(0, it->second.size());

    if (it != m.cend())
        return (it->second)[u(e) % it->second.size()]; // Prevent crossing boundaries
    return s;
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