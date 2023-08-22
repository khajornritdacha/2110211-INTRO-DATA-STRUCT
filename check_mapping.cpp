// Task: Check Mapping
// Tag: Set
// Date: 22/08/23

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    set<int> perm;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        perm.insert(x);
    }

    for (int i = 1; i <= n; i++)
    {
        if (perm.find(i) == perm.end())
        {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
}