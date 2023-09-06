#include <iostream>
#include <vector>
using namespace std;
void cross_2d(vector<vector<int>> &m, int r1, int r2, int c1, int c2)
{
  vector<vector<int>> res;
  for (size_t r = 0; r < m.size(); r++) {
    vector<int> tmp;
    for (size_t c = 0; c < m[0].size(); c++) {
      if ((r1 <= r and r <= r2) or (c1 <= c and c <= c2)) continue;
      tmp.push_back(m[r][c]);
    }
    if (!tmp.empty()) 
      res.push_back(tmp);
  }
  m = res;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  vector<vector<int>> m;
  int r, c, r1, r2, c1, c2;
  cin >> r >> c;
  cin >> r1 >> r2 >> c1 >> c2;
  m.resize(r);
  for (int i = 0; i < r; i++)
  {
    m[i].resize(c);
    for (int j = 0; j < c; j++)
    {
      cin >> m[i][j];
    }
  }
  cross_2d(m, r1, r2, c1, c2);
  for (int i = 0; i < m.size(); i++)
  {
    for (int j = 0; j < m[i].size(); j++)
    {
      cout << m[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}