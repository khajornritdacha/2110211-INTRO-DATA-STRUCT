#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::block_swap(iterator a, iterator b, size_t m) {
  int pos_a = a - begin();
  int pos_b = b - begin();
  if (pos_a < 0 or pos_b < 0 or pos_a + m - 1 >= size() or pos_b + m - 1 >= size() or m <= 0) return false;
  if (std::min(pos_a + m - 1, pos_b + m - 1) >= std::max(pos_a, pos_b)) return false;
  for (int i = 0; i < m; i++) std::swap(mData[pos_a + i], mData[pos_b + i]);
  return true;
}

#endif
