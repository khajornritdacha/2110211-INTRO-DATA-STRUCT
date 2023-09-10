// Task: https://programming.in.th/tasks/1147
// Author: JO
// Date: 10/09/2023
// Note: Code segment tree with OOP concept

#include <bits/stdc++.h>
using namespace std;

template<typename T>
class SegmentTree {
private:
  size_t n;
  const T invalid_value;
  vector<T> seg;
public:
  // Publicly accessible to combine function allows to merge only 2 values when needed.
  const function<T(T, T)> combine;

  // Initialize order should be the in same order as they are declared.
  SegmentTree(const size_t &n,const T &init_value, const T &invalid_value, const function<T(T, T)> &combine) : n(n), invalid_value(invalid_value), combine(combine) { 
    seg.assign(4*n + 10, init_value);
  }

  void update(int idx, T val) {
    update(idx, val, 1, n, 1);
  }

  void update(int idx, T val, int l, int r, int node) {
    if (l == r) {
      seg[node] = val;
      return;
    }
    int mid = (l+r)/2;
    if (idx <= mid) update(idx, val, l, mid, node*2);
    else update(idx, val, mid+1, r, node*2 + 1);
    seg[node] = combine(seg[node*2], seg[node*2 + 1]);
  }

  T query(int ql, int qr) {
    return query(ql, qr, 1, n, 1);
  }

  T query(int ql, int qr, int nl, int nr, int node) {
    if (nr < nl or nr < ql or nl > qr) return invalid_value;
    if (ql <= nl and nr <= qr) return seg[node];
    int mid = (nl + nr)/2;
    return combine(query(ql, qr, nl, mid, node*2), query(ql, qr, mid + 1, nr, node*2 + 1));
  }

  size_t get_size() {
    return this->n;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  const int INF = 1e9+7;
  int n, Q; cin >> n >> Q;
  
  SegmentTree<int> tr = SegmentTree<int>(n, 0, -INF, [](const int &a, const int &b) -> int {
    return max(a, b);
  });

  while (Q--) {
    char op; cin >> op;
    if (op == 'U') {
      int idx, val; cin >> idx >> val;
      tr.update(idx, val);
    } else {
      int l, r; cin >> l >> r;
      cout << tr.query(l, r) << "\n";
    }
  }
}