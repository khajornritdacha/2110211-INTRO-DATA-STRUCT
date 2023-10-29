#ifndef __STUDENT_H
#define __STUDENT_H

#include "priority_queue.h"

template <typename T, typename Comp>
bool CP::priority_queue<T, Comp>::check() {
  for (int i = 0; i < mSize; i++) {
    int c = i*2 + 1;
    if (c < mSize and mLess(mData[i], mData[c])) return false;
    if (c + 1 < mSize and mLess(mData[i], mData[c + 1])) return false;
  }
  return true;
}

#endif