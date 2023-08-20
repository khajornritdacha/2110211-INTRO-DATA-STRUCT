// Task: Grandfather
// Tag: Map, Unordered_map, Graph
// Date: 20/08/23

#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e6 + 10;

bool hasSameGrandpa(unordered_map<long long, long long> &pa, long long a, long long b)
{
    if (a == b)
        return false;
    if (pa.count(a) == 0 || pa.count(b) == 0)
        return false;
    if (pa.count(pa[a]) == 0 || pa.count(pa[b]) == 0)
        return false;
    if (pa[pa[a]] == pa[pa[b]])
        return true;
    return false;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    unordered_map<long long, long long> pa(MXN);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        long long f, s;
        cin >> f >> s;
        assert(f != s);
        pa[s] = f;
    }
    while (m--)
    {
        long long a, b;
        cin >> a >> b;
        if (hasSameGrandpa(pa, a, b))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}