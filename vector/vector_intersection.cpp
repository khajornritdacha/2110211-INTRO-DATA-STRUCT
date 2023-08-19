// Task: vector intersection
// Tag: Two pointer, vector, sorting
// Date: 19/8/2023

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v1(n), v2(m);
    for (int &v : v1)
        cin >> v;
    for (int &v : v2)
        cin >> v;

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    int i = 0, j = 0;
    vector<int> res;

    auto add = [&](int x)
    {
        if (res.empty() || res.back() != x)
        {
            res.push_back(x);
            return true;
        }
        return false;
    };

    for (int i = 0, j = 0; i < n and j < m; i++)
    {
        while (j < m and v2[j] < v1[i])
            j++;
        if (j < m and v2[j] == v1[i])
            add(v1[i]);
    }

    for (int v : res)
        cout << v << " ";
}