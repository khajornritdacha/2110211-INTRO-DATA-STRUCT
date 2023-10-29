#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
CP::list<T> CP::list<T>::split(iterator it,size_t pos) {
  //write your code here
  CP::list<T> result;

  iterator cur_it = begin();
  for (int i = 0; i < pos; i++) cur_it++;
  result.mHeader = cur_it;
  result.mSize = size() - pos;
  mSize -= size() - pos;
  cur_it->next = 
  return result;
}

#endif
