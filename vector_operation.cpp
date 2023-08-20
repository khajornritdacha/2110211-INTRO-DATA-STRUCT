#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int Q;
    cin >> Q;
    vector<int> vec;
    while (Q--)
    {
        string op;
        cin >> op;
        if (op == "pb")
        {
            int x;
            cin >> x;
            vec.push_back(x);
        }
        else if (op == "sa")
        {
            sort(vec.begin(), vec.end());
        }
        else if (op == "sd")
        {
            sort(vec.begin(), vec.end(), greater<int>());
        }
        else if (op == "r")
        {
            reverse(vec.begin(), vec.end());
        }
        else if (op == "d")
        {
            int idx;
            cin >> idx;
            vec.erase(vec.begin() + idx);
        }
    }
    for (int v : vec)
        cout << v << " ";
    return 0;
}