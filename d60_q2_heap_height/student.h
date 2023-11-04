#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <stdio.h>
#include "priority_queue.h"
#include <iostream>

template <typename T,typename Comp >
int CP::priority_queue<T,Comp>::height() const {
  int cur = 0, cnt = -1;
  while (cur < mSize) {
    cur = (cur * 2) + 1;
    cnt++;
  }
  return cnt;
}

#endif

