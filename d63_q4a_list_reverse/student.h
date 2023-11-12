#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
typename CP::list<T>::iterator CP::list<T>::reverse(iterator a, iterator b) {
  b--;
  iterator prev = nullptr, res = a;
  while (a.ptr != b.ptr and b.ptr != prev.ptr) {
    std::swap(a.ptr->data, b.ptr->data);
    prev = a;
    a.ptr = a.ptr->next;
    b.ptr = b.ptr->prev;
  }
  return res;
}

#endif
