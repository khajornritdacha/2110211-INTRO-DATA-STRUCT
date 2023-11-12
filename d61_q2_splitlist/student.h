void splitList(list<T>& list1, list<T>& list2) {
    int m = mSize;
    int n = (mSize + 1)/2;

    for (int i = 0; i < n; i++) {
        mHeader->next->next->prev = mHeader;
        list1.mHeader->prev->next = mHeader->next;
        
        node* tmp = mHeader->next->next;
        mHeader->next->next = list1.mHeader;

        mHeader->next->prev = list1.mHeader->prev;
        list1.mHeader->prev = mHeader->next;

        mHeader->next = tmp;
    }

    for (int i = n; i < m; i++) {
        mHeader->next->next->prev = mHeader;
        list2.mHeader->prev->next = mHeader->next;
        
        node* tmp = mHeader->next->next;
        mHeader->next->next = list2.mHeader;

        mHeader->next->prev = list2.mHeader->prev;
        list2.mHeader->prev = mHeader->next;

        mHeader->next = tmp;
    }

    mSize = 0;
    list1.mSize += n;
    list2.mSize += m - n;
}
