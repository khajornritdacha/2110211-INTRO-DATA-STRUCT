// Task: Most frequent word
// Tag: map, string, introduction
// Date: 19/8/2023

#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<string, int> cnt;
    int n;
    cin >> n;
    int mx = 0;
    string ans;
    for (int i = 1; i <= n; i++)
    {
        string str;
        cin >> str;
        ++cnt[str];
    }

    for (auto &[word, occurence] : cnt)
    {
        if (occurence >= mx)
        {
            mx = occurence;
            ans = word;
        }
    }
    cout << ans << " " << mx << "\n";
}