// Task: Remove even
// Tag: Vector, loops
// Date: 16/8/2023
// Author: Jo

#include <iostream>
#include <vector>
using namespace std;
void remove_even(vector<int> &v, int a, int b)
{
    if (a % 2)
        a++;
    for (int i = a, cnt = 0; i <= b; i += 2, cnt++)
    {
        v.erase(v.begin() + a + cnt);
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
    remove_even(v, a, b);
    // display content of the vector
    for (auto &x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}