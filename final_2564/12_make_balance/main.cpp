// Task: final-2564 12-th question on paper exam

#include <bits/stdc++.h>
using namespace std;
#include "map_bst.h"

int main() {
  CP::map_bst<int, int> mp;
  mp[-2] = 10;
  mp[-1] = -1;
  mp[1] = 22;
  mp[4] = 7;
  mp[7] = 4;
  mp[8] = 5;
  mp[9] = 1;
  mp[10] = 12;

  mp.make_balance();

  mp.print();
}