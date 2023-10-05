#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

//DO NOT INCLUDE ANYTHING


template <typename T>
CP::stack<T>::stack(typename std::set<T>::iterator first,typename std::set<T>::iterator last) {
  int sz = 0;  
  auto it1 = first;
  for (; first != last; first++) {
    sz++;
  }
  mCap = sz;
  mSize = sz;
  mData = new T[sz]();
  for (int i = sz - 1; i >= 0 and it1 != last; i--, it1++) {
    mData[i] = *it1;
  }
}

#endif
