#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"
#include <algorithm>

template <typename T>
std::vector<std::vector<T>>  CP::stack<T>::split_stack(int k) const {
  std::vector<std::vector<T>> res(k, std::vector<T>());
  for (int i = (int)mSize - 1, cur = 0; i >= 0; i--) {
    res[cur].push_back(mData[i]);
    if (++cur == k) cur = 0;
  }
  for (int i = 0; i < k; i++) reverse(res[i].begin(), res[i].end());
  return res;
}

#endif

