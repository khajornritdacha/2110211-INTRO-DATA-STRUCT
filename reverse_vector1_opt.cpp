// Task: Reverse Vector1
// Tag: Vector, Loops
// Date: 16/8/2023
// Author: Jo

#include <iostream>
#include <vector>
using namespace std;
void reverse(vector<int> &v, int a, int b)
{
    for (int mid = (a + b) / 2, i = a; i <= mid; i++)
    {
        swap(v[i], v[b - (i - a)]);
    }
}
int main()
{
    // read input
    int n, a, b;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        v.push_back(c);
    }
    cin >> a >> b;
    // call function
    reverse(v, a, b);
    // display content of the vector
    for (auto &x : v)
        cout << x << " ";
    cout << endl;
}