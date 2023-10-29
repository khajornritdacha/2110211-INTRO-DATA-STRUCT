#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "priority_queue.h"

template <typename T,typename Comp >
std::vector<T> CP::priority_queue<T,Comp>::at_level(size_t k) const {
  std::vector<T> r;
  for (int i = (1<<k)-1, lim = (1<<(k+1)) - 1; i < std::min((int)mSize, lim); i++) {
    r.push_back(mData[i]);  
  }
  std::sort(r.rbegin(), r.rend(), mLess);
  return r;
}

#endif

