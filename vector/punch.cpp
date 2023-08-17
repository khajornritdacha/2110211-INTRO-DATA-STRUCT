// Task: d62_q1a_punch
// Tag: vector, iterator
// Date: 8/17/2023

#include <iostream>
#include <vector>
using namespace std;

vector<string> punch(vector<string> &v, vector<string>::iterator it, int k)
{
    vector<string>::iterator st = it;
    int cnt = k;
    for (int i = 0; i < k and st != v.begin(); i++)
    {
        st--;
        cnt--;
    }
    while (st != v.end() and cnt < 2 * k + 1)
    {
        v.erase(st);
        cnt++;
    }
    return v;
}

int main()
{
    int n, j, k;
    cin >> n >> j >> k;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << "Result after punch" << endl;
    vector<string> result = punch(v, v.begin() + j, k);
    for (auto &x : result)
    {
        cout << x << endl;
    }
}