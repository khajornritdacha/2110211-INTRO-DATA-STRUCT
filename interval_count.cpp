// Task: Interval Count
// Tag: Map, Lower bound, Upper bound
// Date: 21/08/23

#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, m, K;
    cin >> n >> m >> K;
    map<int, int> cnt;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }

    int sum = 0;
    cnt[-2e9] = 0;
    for (auto &[key, val] : cnt)
    {
        sum += val;
        val = sum;
    }

    while (m--)
    {
        int x;
        cin >> x;
        auto it1 = cnt.lower_bound(x - K);
        auto it2 = cnt.upper_bound(x + K);

        it1--;
        it2--;

        cout << it2->second - it1->second << " ";
    }
}