#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename T>
void CP::stack<T>::moveInsert(int k,CP::stack<T> &s2, int m) {
  m = std::min(m, (int)s2.size());
  size_t newSize = size() + m;
  T* newArray = new T[newSize]();
  int idx = newSize - 1;

  for (int i = 0; i < k; i++, idx--) newArray[idx] = mData[size() - i - 1];
  for (int i = 0; i < m; i++, idx--) newArray[idx] = s2.top(), s2.pop();
  for (int i = 0; idx >= 0; idx--, i++) newArray[idx] = mData[size() - i - k - 1];
  
  delete[] mData;
  mData = newArray;
  mSize = newSize;
  mCap = newSize;
}
#endif
