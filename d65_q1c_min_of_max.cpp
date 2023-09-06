#include <bits/stdc++.h>
using namespace std;

int main() {
   cin.tie(0)->sync_with_stdio(0);
   int n, m; cin >> n >> m;
   vector<int> pw(n + 5), ty(n + 5);
   for (int i = 1; i <= n; i++) {
      cin >> pw[i];
   }
   for (int i = 1; i <= n; i++) {
      cin >> ty[i];
   }
   vector<int> mx(m, 1);
   multiset<int> mn;
   for (int i = 1; i <= m; i++) mn.insert(1);
   for (int i = 1; i <= n; i++) {
      if (pw[i] > mx[ty[i]]) {
         mn.erase(mn.find(mx[ty[i]]));
         mx[ty[i]] = pw[i];
         mn.insert(pw[i]);
      }
      cout << *mn.begin() << " ";
   }
}