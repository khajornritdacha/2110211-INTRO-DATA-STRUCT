#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
CP::list<T> CP::list<T>::split(iterator it,size_t pos) {
  //write your code here
  CP::list<T> result;

  if (it == end()) return result;

  // ตัวถูกแก้ค่าไว้หลังสุด

  it.ptr->prev->next = mHeader; // 1

  result.mHeader->next = it.ptr; // 3

  mHeader->prev->next = result.mHeader; // 5
  result.mHeader->prev = mHeader->prev; // 6
  
  mHeader->prev = it.ptr->prev; // 2
  it.ptr->prev = result.mHeader; // 4

  result.mSize = mSize - pos;
  mSize = pos;

  return result;
}

#endif