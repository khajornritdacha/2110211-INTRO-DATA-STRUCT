// Task: Hiatus
// Tag: Set, Hashing, Upper bound
// Date: 22/08/23

#include <bits/stdc++.h>
using namespace std;

inline int serialize(int year, int month)
{
    return year * 100 + month;
}

inline pair<int, int> deSerialize(int x)
{
    return {x / 100, x % 100};
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    set<int> publish;
    for (int i = 1; i <= n; i++)
    {
        int year, month;
        cin >> year >> month;
        publish.insert(serialize(year, month));
    }
    while (m--)
    {
        int year, month;
        cin >> year >> month;
        int val = serialize(year, month);
        auto it = publish.upper_bound(val);
        if (it == publish.begin())
        {
            cout << "-1 -1 ";
            continue;
        }

        it--;
        if (*it == val)
        {
            cout << "0 0 ";
        }
        else
        {
            pair<int, int> res = deSerialize(*it);
            cout << res.first << " " << res.second << " ";
        }
    }
}