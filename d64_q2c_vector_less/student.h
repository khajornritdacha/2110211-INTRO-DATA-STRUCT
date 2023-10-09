#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::operator<(const CP::vector<T> &other) const {
  if (empty() and !other.empty()) return true;
  for (int i = 0; i < std::min(size(), other.size()); i++) {
    if (mData[i] > other.mData[i]) return false;
    if (mData[i] < other.mData[i]) return true;
  }
  return (size() < other.size());
}

#endif
