#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
void CP::list<T>::extract(const T& value,iterator a, iterator b,CP::list<T>& output) {
  for (auto it = a; it != b; ) {
    auto next = it.ptr->next;
    if (it.ptr->data == value) {
      it.ptr->prev->next = it.ptr->next;
      it.ptr->next->prev = it.ptr->prev;
      
      output.mHeader->next->prev = it.ptr;
      it.ptr->next = output.mHeader->next;
      output.mHeader->next = it.ptr;
      it.ptr->prev = output.mHeader;

      mSize -= 1;
      output.mSize += 1;
    }
    it = next;
  }

}

#endif
