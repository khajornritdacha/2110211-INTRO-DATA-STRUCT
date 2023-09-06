#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e6 + 10;
set<pair<int, int>> ms[MXN];

void erase(set<pair<int, int>> &s, int U) {
   auto it = s.lower_bound({U, -1});
   if (it != s.end() and it->first == U) {
      s.erase(it);
   }
}

int main() {
   int n, M, A; cin >> n >> M >> A;
   vector<int> cnt(n + 5);
   for (int i = 1; i <= n; i++) {
      cin >> cnt[i];
   }

   for (int i = 1; i <= A; i++) {
      char op; cin >> op;
      if (op == 'B') {
         int U, I, V; cin >> U >> I >> V;
         erase(ms[I], U);
         ms[I].insert({U, V});
      } else if (op == 'W') {
         int U, I; cin >> U >> I;
         erase(ms[I], U);
      }
   }

   set<int> ans[M + 5];
   for (int i = 1; i <= n; i++) {
      vector<pair<int, int>> players(ms[i].begin(), ms[i].end());
      sort(players.begin(), players.end(), [](const pair<int, int> &A, const pair<int, int> &B) {
         if (A.second != B.second) return A.second > B.second;
         return A.first > B.first;
      });
      for (int k = 0; k < min((int)players.size(), cnt[i]); k++) {
         ans[players[k].first].insert(i);
      }
   }

   for (int i = 1; i <= M; i++) {
      if (ans[i].empty()) { cout << "NONE\n"; continue; }
      for (int v : ans[i]) cout << v << " ";
      cout << "\n";
   }
}