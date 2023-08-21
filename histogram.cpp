// Task: Histogram
// Tag: Map, Count frequency
// Date: 21/08/23

#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<string, int> cnt;
    for (int i = 1; i <= n; i++)
    {
        string str;
        cin >> str;
        cnt[str]++;
    }

    for (auto &[name, freq] : cnt)
    {
        if (freq <= 1)
            continue;
        cout << name << " " << freq << "\n";
    }
}