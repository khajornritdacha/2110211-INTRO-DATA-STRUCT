#include <bits/stdc++.h>
using namespace std;

int main() {
   cin.tie(0)->sync_with_stdio(0);
   int n, m, earning;
   cin >> n >> m >> earning;
   const int MX_DAY = 100'000;
   vector<int> money(MX_DAY + 1, 0);
   for (int i = 1; i <= n; i++) {
      int day, new_earning; cin >> day >> new_earning;
      money[day] = new_earning;
   }
   for (int i = 0; i <= MX_DAY; i++) {
      if (money[i] != 0) {
         earning = money[i];
      }
      if (i - 1 >= 0) {
         money[i] = money[i - 1];
      }
      money[i] += earning;
   }
   
   // did not handle case which day is infinite
   for (int q = 1; q <= m; q++) {
      int price, cheated_date;
      cin >> price >> cheated_date;
      int res = -1;
      if (money[cheated_date] >= price) {
         res = lower_bound(money.begin(), money.end(), price) - money.begin();
      } else {
         res = lower_bound(money.begin(), money.end(), price + money[cheated_date]) - money.begin();
      }
      cout << res << " ";
   }
}