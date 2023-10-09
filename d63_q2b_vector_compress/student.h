#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::compress() {
    T* tmp = new T[mSize]();
    for (size_t i = 0; i < mSize; i++) tmp[i] = mData[i];
    delete[] mData;
    mData = tmp;
    mCap = mSize;
}

#endif
