void splitList(list<T>& list1, list<T>& list2) {
    if (mSize <= 0) return;

    int sz = (mSize + 1)/2;
    auto l = begin();
    auto r = begin();
    for (int i = 0; i < sz - 1; i++) r = r.ptr->next;

    // insert into list1
    l.ptr->prev = list1.mHeader->prev; 
    list1.mHeader->prev->next = l.ptr;
    
    mHeader->next = r.ptr->next;
    r.ptr->next->prev = mHeader;

    r.ptr->next = list1.mHeader;
    list1.mHeader->prev = r.ptr;

    mSize -= sz;
    list1.mSize += sz;

    // insert into list2
    if (mSize > 0) {
        mHeader->next->prev = list2.mHeader->prev;
        list2.mHeader->prev->next = mHeader->next;

        mHeader->prev->next = list2.mHeader;
        list2.mHeader->prev = mHeader->prev;

        mHeader->next = mHeader;
        mHeader->prev = mHeader;
    }

    list2.mSize += mSize;
    mSize = 0;
}
