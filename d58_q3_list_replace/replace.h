void replace(const T& x, list<T>& y) {
  for (auto it = begin(); it != end(); ) {
    auto next = it.ptr->next;
    if (it.ptr->data == x) {
      // insert new list
      // move prev pointer to point to
      // make last pointer in y point to next element
      CP::list<T> nl = y;
      nl.mHeader->next->prev = it.ptr->prev;
      it.ptr->prev->next = nl.mHeader->next;
      nl.mHeader->prev->next = it.ptr->next;
      it.ptr->next->prev = nl.mHeader->prev;
      mSize += (int)nl.mSize - 1;

      nl.mSize = 1;
      nl.mHeader->next = it.ptr;
      nl.mHeader->prev = it.ptr;
      it.ptr->prev = nl.mHeader;
      it.ptr->next = nl.mHeader;
    }
    it = next;
  }
}
