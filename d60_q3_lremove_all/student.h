#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::list<T>::remove_all(const T& value) {
  for (auto it = begin(); it != end(); ) {
    auto next = it.ptr->next;
    if (it.ptr->data == value) {
      it.ptr->prev->next = it.ptr->next;
      it.ptr->next->prev = it.ptr->prev;
      mSize -= 1;
      delete it.ptr;
    }
    it = next;
  }  
}

#endif
