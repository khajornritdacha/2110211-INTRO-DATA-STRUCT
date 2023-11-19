void shift(int k) {
	int tmp = mSize;
	k = (k%tmp + tmp)%tmp;
	iterator it = begin();

	if (k == 0) return;

	while (k--) it++;

	mHeader->next->prev = mHeader->prev;
	mHeader->prev->next = mHeader->next;

	mHeader->prev = it.ptr->prev;
	it.ptr->prev->next = mHeader;

	it.ptr->prev = mHeader;
	mHeader->next = it.ptr;
}
