#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename KeyT,
          typename MappedT,
          typename CompareT>
size_t CP::map_bst<KeyT,MappedT,CompareT>::process(node* ptr) const {
  if (!ptr) return 0;
  size_t res = 0;
  if (ptr->left) res += process(ptr->left);
  if (ptr->right) res += process(ptr->right);
  if ((ptr->left and !ptr->right) or (!ptr->left and ptr->right)) res += 1;
  return res;
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
size_t CP::map_bst<KeyT,MappedT,CompareT>::count_unary() const {
  return process(mRoot);
}

#endif
