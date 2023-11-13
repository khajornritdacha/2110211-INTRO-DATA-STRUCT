#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "map_bst.h"

template <typename KeyT,typename MappedT, typename CompareT >
size_t CP::map_bst<KeyT,MappedT,CompareT>::process(node* n) {
  if (!n) return 0;
  return process(n->left) + process(n->right) + 1;
}

template <typename KeyT,typename MappedT, typename CompareT >
std::pair<KeyT,MappedT> CP::map_bst<KeyT,MappedT,CompareT>::subtree(map_bst<KeyT,MappedT,CompareT> &left, map_bst<KeyT,MappedT,CompareT> &right) {
  if (mSize == 0) return std::pair<KeyT,MappedT>();
  left.clear();
  right.clear();

  if (mRoot->left != NULL) {
    left.mSize = process(mRoot->left);
    left.mRoot = mRoot->left;
    mRoot->left->parent = left.mRoot;
    mRoot->left = NULL;
  }

  if (mRoot->right != NULL) {
    right.mSize = process(mRoot->right);
    right.mRoot = mRoot->right;
    mRoot->right->parent = right.mRoot;
    mRoot->right = NULL;
  }

  mSize = 1;
  return std::pair<KeyT, MappedT>(mRoot->data);
}

#endif

