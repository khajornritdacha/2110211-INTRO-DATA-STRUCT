// Task: Max 2D Matrix
// Tag: Brute Force
// Date: 9/8/2023
// Author: Jo

#include <bits/stdc++.h>
using namespace std;

int main()
{
    const int INF = 1e9;
    int n, m, Q;
    cin >> n >> m >> Q;
    int arr[n + 5][m + 5] = {};
    for (int r = 1; r <= n; r++)
    {
        for (int c = 1; c <= m; c++)
        {
            cin >> arr[r][c];
        }
    }
    while (Q--)
    {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        if (r1 > r2 || c1 > c2)
        {
            cout << "INVALID\n";
            continue;
        }

        if (r1 > n || c1 > m || r2 < 1 || c2 < 1)
        {
            cout << "OUTSIDE\n";
            continue;
        }

        int mx = -INF;
        for (int r = max(1, r1); r <= min(r2, n); r++)
        {
            for (int c = max(1, c1); c <= min(c2, m); c++)
            {
                mx = max(mx, arr[r][c]);
            }
        }
        cout << mx << "\n";
    }
}