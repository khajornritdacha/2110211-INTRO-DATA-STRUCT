// Task: Inside interval
// Tag: Event point, map, upper bound
// Date: 22/8/2023

#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    map<int, int> ep;
    ep[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        ep[a]++;
        ep[b + 1]--;
    }

    int sum = 0;
    for (auto &[key, val] : ep)
    {
        sum += val;
        val = sum;
    }

    while (m--)
    {
        int x;
        cin >> x;
        auto it = ep.upper_bound(x);
        assert(it != ep.begin());
        it--;
        cout << (it->second > 0) << " ";
    }
}