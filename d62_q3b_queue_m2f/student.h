#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

size_t add(size_t x, size_t y, size_t mod) {
    return ((x + y)%mod + mod)%mod;
}

template <typename T>
void CP::queue<T>::move_to_front(size_t pos) {
   for (; pos > 0; pos--) {
    std::swap(mData[add(mFront, pos, mCap)], mData[add(mFront, pos - 1, mCap)]);
   }
}

#endif
