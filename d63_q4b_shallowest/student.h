#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

//you can use this function
template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT,MappedT,CompareT>::shallowest_leaf(node* n) {
  if (n == NULL) return -1;
  if (n->left == NULL and n->right == NULL) return 0;
  const int INF = 1e9 + 7;
  int ml = INF, mr = INF;
  if (n->left != NULL) ml = shallowest_leaf(n->left);
  if (n->right != NULL) mr = shallowest_leaf(n->right);
  return std::min(ml, mr) + 1;
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT,MappedT,CompareT>::shallowest_leaf() {
  return shallowest_leaf(mRoot);
}


#endif
