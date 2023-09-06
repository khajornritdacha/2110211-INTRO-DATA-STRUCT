#include <bits/stdc++.h>
using namespace std;


int main() {
   cin.tie(0)->sync_with_stdio(0);
   int n, m;
   cin >> n >> m;
   vector<int> T(n + 5);
   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
   for (int i = 1; i <= n; i++) {
      cin >> T[i];
      pq.push({T[i], i});
   }
   for (int i = 1; i <= m; i++) {
      if (i <= n) {
         cout << "0\n";
      } else {
         auto top = pq.top();
         pq.pop();
         cout << top.first << "\n";
         pq.push({top.first + T[top.second], top.second});
      }
   }
}