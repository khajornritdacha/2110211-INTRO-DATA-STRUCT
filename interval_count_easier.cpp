// Task: Interval Count
// Tag: Vector, sorting, lower bound, upper bound
// Date: 21/08/23

#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, m, K;
    cin >> n >> m >> K;
    vector<int> vec(n);
    for (int &v : vec)
        cin >> v;
    sort(vec.begin(), vec.end());
    while (m--)
    {
        int x;
        cin >> x;

        // Count number in range [x-K, x+K] from difference of indexes between k1, k2
        // Let k1 be the index of the greatest value that is less than x-K
        // Let k2 be the index of the greatest value that is not more than x+K
        int k1 = lower_bound(vec.begin(), vec.end(), x - K) - vec.begin();
        int k2 = upper_bound(vec.begin(), vec.end(), x + K) - vec.begin() - 1;
        cout << k2 - k1 + 1 << " ";
    }
}