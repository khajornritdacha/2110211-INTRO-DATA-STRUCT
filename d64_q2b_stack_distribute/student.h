#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename T>
std::vector<std::vector<T>> CP::stack<T>::distribute(size_t k) const {
  int sz = mSize / k;
  int rem = mSize % k;
  std::vector<std::vector<T>> res(k, std::vector<T>());
  int idx = (int)mSize - 1;
  for (int rp = 0; rp < k; rp++) {
    for (int i = 0; i < sz; i++, idx--) {
      res[rp].push_back(mData[idx]);
    }
    if (rem > 0) {
      res[rp].push_back(mData[idx]);
      idx--;
      rem--;
    }
  }
  return res;
}
#endif
