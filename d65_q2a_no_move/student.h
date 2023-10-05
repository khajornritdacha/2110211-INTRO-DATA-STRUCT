#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
T& CP::vector_no_move<T>::operator[](int idx) {
  //your code here
  int k = upper_bound(aux.begin(), aux.end(), idx) - aux.begin();
  return mData[k-1][idx - aux[k-1]];
}

template <typename T>
void CP::vector_no_move<T>::expand_hook() {
  //your code here
  //you MAY need this function
  if (aux.empty()) aux.push_back(0);
  aux.push_back(mCap);
}

#endif
