#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> l{0, 1, 1, 2};
    vector<int> r{0, 1, 1, 2, 3, 5, 8};

    if (l.size() > r.size())
    {
        vector<int> temp(l);
        l = r;
        r = temp;
    }

    for (int i = 0; i < l.size(); ++i)
    {
        if (l[i] == r[i])
            continue;
        else
        {
            cout << "no" << endl;
            break;
        }
    }
    cout << "yes" << endl;
    
    return 0;
}
