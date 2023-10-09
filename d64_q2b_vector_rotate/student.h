#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::rotate(iterator first, iterator last, size_t k) {
  T tmp[last-first];
  for (int i = 0; i < k; i++) tmp[i] = mData[first - begin() + i];
  int idx = first - begin();
  for (int i = first - begin() + k; i < last - begin(); i++, idx++) mData[idx] = mData[i];
  for (int i = 0; idx < last - begin(); idx++, i++) mData[idx] = tmp[i];
}

#endif
