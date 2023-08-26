// Task: Multi Insert
// Tag: Vector
// Date: 26/08/2023

#include <iostream>
#include <vector>
using namespace std;
void multiple_add(vector<int> &v, int value, int position, int count)
{
    vector<int> tmp;
    for (int i = 0; i < count; i++)
        tmp.push_back(value);
    v.insert(v.begin() + position, tmp.begin(), tmp.end());
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, value, position, count;
    cin >> n >> value >> position >> count;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    multiple_add(v, value, position, count);
    cout << "After call multiple_add" << endl
         << "Size = " << v.size() << endl;
    for (auto &x : v)
        cout << x << " ";
    cout << endl;
}