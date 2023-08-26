// Task: Password
// Tag: set, hash, string
// Date: 26/08/2023

#include <bits/stdc++.h>
using namespace std;

inline char shift(char c, int shift_idx)
{
    char x = c - 'a' + shift_idx;
    if (x >= 26)
        x -= 26;
    return x + 'a';
}

string
my_hash(const string &str, vector<int> &shift_idx)
{
    string res;
    for (size_t i = 0; i < str.length(); i++)
    {
        res.push_back(shift(str[i], shift_idx[i]));
    }
    return res;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, m, L;
    cin >> n >> m >> L;
    vector<int> shift_idx(L);
    for (int &v : shift_idx)
    {
        cin >> v;
        v %= 26;
    }

    set<string> db;
    for (int i = 1; i <= n; i++)
    {
        string str;
        cin >> str;
        db.insert(str);
    }

    for (int i = 1; i <= m; i++)
    {
        string str;
        cin >> str;
        if (db.find(my_hash(str, shift_idx)) != db.end())
        {
            cout << "Match\n";
        }
        else
        {
            cout << "Unknown\n";
        }
    }
}