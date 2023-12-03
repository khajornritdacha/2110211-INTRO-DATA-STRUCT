#include <bits/stdc++.h>
using namespace std;
#include "unordered_map.h"

int main() {
  CP::unordered_map<int, int> ump;
  ump[5] = 10;
  ump[15] = 10;
  // ump[25] = 10;
  // ump[35] = 10;
  // ump[45] = 10;
  // ump[1] = 11;
  // ump[13] = 13;
  // ump[6] = 10;

  int k = 5;
  cout << ump.get_probe_count(k) << "\n";
  k = 15;
  cout << ump.get_probe_count(k) << "\n";
  k = 25;
  cout << ump.get_probe_count(k) << "\n";
  k = 35;
  cout << ump.get_probe_count(k) << "\n";

  ump.print();
}