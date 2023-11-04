#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long lift(long long u, long long K) {
    return (u - 1)/K;
}

int relation(long long S, long long a, long long b)
{
    if (a == 0 and b == 0) return 4;
    
    if (a > b) swap(a, b);
    if (lift(b, S) == a) return 1;
    
    int tmp = b;
    while (tmp > a) tmp = lift(tmp, S);
    if (tmp == a and b != a) return 2;

    int dep_a = 0;
    while (a > 0) a = lift(a, S), dep_a++;
    
    int dep_b = 0;
    while (b > 0) b = lift(b, S), dep_b++;

    if (dep_a != dep_b) return 3;
    return 4;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    long long S, a, b;
    cin >> n;
    while (n--)
    {
        cin >> S >> a >> b;
        cout << relation(S, a, b) << " ";
    }
    cout << endl;
}