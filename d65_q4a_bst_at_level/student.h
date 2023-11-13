#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>
#include "map_bst.h"

// you can modify and use this function
template <typename KeyT,
          typename MappedT,
          typename CompareT>
void CP::map_bst<KeyT,MappedT,CompareT>::my_recur(node* n,size_t level,size_t tmp,std::vector<KeyT> &v) {
  if (level == tmp) {
    v.push_back(n->data.first);
    return;
  }
  if (tmp + 1 <= level and n->right) my_recur(n->right, level, tmp + 1, v);
  if (tmp + 1 <= level and n->left) my_recur(n->left, level, tmp + 1, v);
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
std::vector<KeyT> CP::map_bst<KeyT,MappedT,CompareT>::at_level(size_t level) {
  std::vector<KeyT> res;
  my_recur(mRoot, level, 0, res);
  return res;
}


#endif
