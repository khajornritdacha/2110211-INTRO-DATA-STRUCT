#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <vector>

template <typename T>
template <typename Comp>
T CP::queue<T>::min_element(std::vector<size_t> pos,Comp comp) const {
  bool isFirst = true;
  size_t res;
  auto get_value = [&](const size_t idx) -> T {
    return mData[(mFront + idx >= mCap) ? (mFront + idx - mCap) : (mFront + idx)];
  };

  for (size_t p : pos) {
    if (p >= mSize) continue;
    if (isFirst || comp(get_value(p), get_value(res))) res = p, isFirst = false;
  }
  return get_value(res);
}

#endif
