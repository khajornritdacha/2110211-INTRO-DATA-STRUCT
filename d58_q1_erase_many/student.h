#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos) {
  //write your code here
  int idx = 0;
  CP::vector<T> new_vec;
  for (int i = 0; i < size(); i++) {
    if (idx < pos.size() and pos[idx] == i) {
      idx++;
      continue;
    }
    new_vec.push_back(mData[i]);
  }
  *this = new_vec;
}

#endif
