#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
int CP::stack<T>::compare_reserve(const CP::stack<T> &other) const {
    int ra = mCap - mSize;
    int rb = other.mCap - other.mSize;

    if (ra < rb) return -1;
    else if (ra == rb) return 0;
    return 1;
}

#endif
