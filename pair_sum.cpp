// Task: Pair Sum
// Tag: Unordered Map
// Date: 19/8/2023

#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    int arr[n + 5] = {};
    unordered_map<int, int> cnt;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        cnt[arr[i]]++;
    }

    while (m--)
    {
        int x;
        cin >> x;
        bool isAnswered = false;
        for (int i = 1; i <= n; i++)
        {
            int target = x - arr[i];

            // Necessary to prevent creating new key in map
            if (cnt.find(target) == cnt.end())
                continue;
            if ((target == arr[i] and cnt[target] >= 2) || (target != arr[i] and cnt[target] >= 1))
            {
                cout << "YES\n";
                isAnswered = true;
                break;
            }
        }

        if (!isAnswered)
        {
            cout << "NO\n";
        }
    }
}