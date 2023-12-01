#include <bits/stdc++.h>
using namespace std;

// 0 -> 00, 1 -> 10, 2 -> 01
// dp(i, k) := จำนวนวิธีในการสร้างวางตาราง n col โดยที่ col ที่ n มีรูปแบบที่ k
// dp(i, 0) = dp(i - 1, 0) + dp(i - 1, 1) + dp(i - 1, 2)
// dp(i, 1) = dp(i - 1, 0) + dp(i - 1, 2)
// dp(i, 2) = dp(i - 1, 0) + dp(i - 1, 1)
// dp(0, 0) = 1

int main() {
  const int MOD = 1e8 + 7;
  int n; cin >> n;
  vector<vector<int>> dp(n + 5, vector<int>(3));
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % MOD;
    dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
    dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
  }
  cout << (dp[n][0] + dp[n][1] + dp[n][2]) % MOD << "\n";
}
