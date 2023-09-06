#include <iostream>
#include <vector>
#include <map>
using namespace std;
void insert_into_sv(map<int, int> &v, int pos, int value)
{
   auto st_del_it = v.lower_bound(pos);
   vector<pair<int, int>> to_edit(st_del_it, v.end());
   v.erase(st_del_it, v.end());
   v[pos] = value;

   // Inserting value to the correct position render inserting in O(1) instead of O(logN)
   for (auto &[key, value] : to_edit) {
      v.insert(v.end(), {key + 1, value});
   }
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   int n;
   map<int, int> v;
   cin >> n;
   for (int i = 0; i < n; i++)
   {
      int a, b;
      cin >> a >> b;
      insert_into_sv(v, a, b);
   }
   cout << v.size() << "\n";
   for (auto &x : v)
   {
      cout << x.first << ": " << x.second << "\n";
   }
}