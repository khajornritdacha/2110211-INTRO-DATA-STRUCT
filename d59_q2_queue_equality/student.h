#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::queue<T>::operator==(const CP::queue<T> &other) const {
  if (size() != other.size()) return false;
  for (size_t i = 0, a = mFront, b = other.mFront; i < size(); i++) {
    if (mData[a] != other.mData[b]) return false;
    if (++a == mCap) a = 0;
    if (++b == other.mCap) b = 0;
  }
  return true;
}

#endif
