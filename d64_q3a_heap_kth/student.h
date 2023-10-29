#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "priority_queue.h"

template <typename T,typename Comp >
T CP::priority_queue<T,Comp>::get_kth(size_t k) const {
  std::vector<T> vec;
  for (size_t i = 0; i < std::min(7, (int)mSize); i++) vec.push_back(mData[i]);
  std::sort(vec.rbegin(), vec.rend(), mLess);
  return vec[k - 1];
}

#endif
