#include <iostream>
#include <vector>

using namespace std;

bool is_pre(vector<int> l, vector<int> r)
{
    if (l.size() > r.size())
        return is_pre(r, l);
    for (int i = 0; i < l.size(); ++i)
    {
        if (l[i] != r[i])
            return false;
    }
    return true;
}

int main()
{
    vector<int> l{0, 1, 1, 2};
    vector<int> r{0, 1, 1, 2, 3, 5, 8};

    cout << (is_pre(r, l) ? "yes\n" : "no\n");

    return 0;
}
