#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
std::vector<T> CP::queue<T>::to_vector(int k) const {
  std::vector<T> res;
  for (int i = 0, lim = std::min(k, (int)mSize); i < lim; i++) {
    res.push_back(mData[(mFront + i) % mCap]);
  }
  return res;
}

template <typename T>
CP::queue<T>::queue(iterator from,iterator to) {
  std::vector<T> vec;
  for (; from != to; from++) {
    vec.push_back(*from);
  }
  mSize = vec.size();
  mCap = vec.size();
  mData = new T[mCap]();
  mFront = 0;
  for (int i = 0; i < mCap; i++) mData[i] = vec[i];
}

#endif
