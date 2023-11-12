#ifndef __STUDENT_H__
#define __STUDENT_H__


template <typename T>
bool CP::list<T>::check() {
  if (mHeader == NULL) return false;
  std::vector<node *> rem(mSize + 1);
  auto it = mHeader;
  for (int i = 0; i < mSize + 1; i++) {
    if (it->next == NULL) return false;
    rem[i] = it;
    it = it->next;
  }
  if (it != mHeader) return false;
  for (int i = 0; i < mSize + 1; i++) {
    if (it->prev == NULL) return false;
    it = it->prev;
    if (rem[mSize - i] != it) return false;
  }
  if (it != mHeader) return false;
  return true;
}


#endif
