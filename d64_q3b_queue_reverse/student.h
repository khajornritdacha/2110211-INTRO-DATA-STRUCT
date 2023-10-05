#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <cassert>

template <typename T>
void CP::queue<T>::reverse(int a,int b) {
  int sz = b - a + 1;
  for (int i = 0, l = (mFront + a) % mCap, r = (mFront + b) % mCap; i < sz/2; i++) {
    std::swap(mData[l], mData[r]);
    if (++l >= mCap) l = 0;
    if (--r < 0) r = mCap - 1;
  }
}

#endif
