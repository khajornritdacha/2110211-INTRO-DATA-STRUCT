#include <bits/stdc++.h>
using namespace std;

class Key {
public:
  int x;
  int y;
};


namespace CP {
  template<class Key, class T>
  class geometric_hash_grid {
  protected:
    class MyEqual {
    public:
      bool operator()(const Key &a, const Key &b) const {
        return (a.x == b.x and a.y == b.y);
      } 
    };
    class MyHasher {
    public:
      size_t operator()(const Key &k) const {
        return (k.x*31ul + k.y);
      }
    };
    unordered_map<Key, multiset<T>, MyHasher, MyEqual> ump;

    bool is_valid_key(int x, int y) {
      return (ump.find({x, y}) != ump.end());
    }
  public:
    geometric_hash_grid() {}

    void insert(int x, int y, const T& data) {
      ump[{x, y}].insert(data);
    }

    void remove(int x, int y, const T& data) {
      if (!is_valid_key(x, y)) return;
      auto it = ump[{x, y}].find(data);
      if (it != ump[{x, y}].end()) ump[{x, y}].erase(it);
      if (ump[{x, y}].size() == 0) ump.erase({x, y});
    }

    vector<T> getDataAt(int x, int y) {
      if (!is_valid_key(x, y)) return {};
      vector<T> res;
      for (const T &x : ump[{x, y}]) res.push_back(x);
      return res;
    }

    vector<T> neighbors(int x, int y) {
      vector<T> res;
      for (int dx : {-1, 0, 1}) for (int dy : {-1, 0, 1}) {
        vector<T> tmp = getDataAt(x + dx, y + dy);
        res.insert(res.end(), tmp.begin(), tmp.end());
      }
      return res;
    }
  };
};

void print(const vector<string> vec) {
  for (string x : vec) cout << x << " ";
  cout << "\n";
}

int main() {
  CP::geometric_hash_grid<Key, string> ghg;
  ghg.insert(10, 999, "A");
  ghg.insert(10, 999, "B");
  ghg.insert(10, 998, "B");

  print(ghg.getDataAt(10, 999));
  print(ghg.getDataAt(10, 998));
  print(ghg.neighbors(10, 998));

  ghg.remove(10, 998, "C");
  ghg.remove(10, 998, "B");
  print(ghg.neighbors(10, 997));
}