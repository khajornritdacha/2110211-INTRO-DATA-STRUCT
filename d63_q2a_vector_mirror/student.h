#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::mirror() {
  T* tmp = new T[2*mSize]();
  for (size_t i = 0; i < mSize; i++) tmp[i] = mData[i];
  for (size_t i = mSize, idx = (int)mSize - 1; i < 2*mSize; i++, idx--) tmp[i] = mData[idx];
  delete[] mData;
  mData = tmp;
  mSize = 2*mSize;
  mCap = 2*mSize;
}

#endif
