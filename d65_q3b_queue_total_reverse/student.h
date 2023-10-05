#ifndef _STUDENT_H_INCLUDED
#define _STUDENT_H_INCLUDED
#include "queue.h"

template <typename T>
void CP::queue<T>::reverse() {
  aux = !aux;
}

template <typename T>
const T& CP::queue<T>::front() const {
  if (aux) return mData[(mFront + mSize - 1) % mCap];
  return mData[mFront];
}

template <typename T>
const T& CP::queue<T>::back() const {
  if (aux) return mData[mFront];
  return mData[(mFront + mSize - 1) % mCap];
}

template <typename T>
void CP::queue<T>::push(const T& element) {
  ensureCapacity(mSize + 1);
  if (!aux) mData[(mFront + mSize) % mCap] = element;
  else {
    mFront = (mFront - 1 + mCap) % mCap;
    mData[mFront] = element;
  }
  mSize++;
}

template <typename T>
void CP::queue<T>::pop() {
  if (!aux) {
    mFront = mFront + 1;
    if (mFront == mCap) mFront = 0;
  }
  mSize--;
}

#endif

