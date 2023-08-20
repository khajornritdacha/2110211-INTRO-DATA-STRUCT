// Task: vote
// Tag: vector, map, sorting
// Date: 20/08/23

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, K;
    cin >> n >> K;
    map<string, int> vote;
    for (int i = 1; i <= n; i++)
    {
        string str;
        cin >> str;
        vote[str]++;
    }

    vector<int> scores;
    for (auto &[name, score] : vote)
    {
        scores.emplace_back(score);
    }
    sort(scores.begin(), scores.end(), greater<int>());

    cout << scores[min(K - 1, (int)scores.size() - 1)] << "\n";
}