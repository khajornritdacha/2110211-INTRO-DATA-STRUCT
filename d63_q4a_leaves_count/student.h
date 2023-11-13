#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

// you can modify and use this function
template <typename KeyT,
          typename MappedT,
          typename CompareT>
size_t CP::map_bst<KeyT,MappedT,CompareT>::leaves_count(node* n) {
  if (!n) return 0;
  if (!n->left and !n->right) return 1;
  size_t ll = 0, rl = 0;
  if (n->left) ll = leaves_count(n->left);
  if (n->right) rl = leaves_count(n->right);
  return ll + rl;
}


template <typename KeyT,
          typename MappedT,
          typename CompareT>
size_t CP::map_bst<KeyT,MappedT,CompareT>::leaves_count() {
  return leaves_count(mRoot);
  //write your code here
}


#endif
