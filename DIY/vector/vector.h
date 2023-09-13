#ifndef DIY_VECTOR_H
#define DIY_VECTOR_H

#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif

namespace JO {
    template<typename T>
    class Vector {
        public:
        size_t mSize;
        size_t mCap;
        T* mData;

        // Constructor
        Vector() {
            const int sz = 5;
            const T init = T();
            mData = new T[sz];
            mSize = sz;
            mCap = sz;
            for (size_t i = 0; i < sz; i++) mData[i] = init;
        }

        // Assignment operator
        Vector<T>& operator=(Vector<T> other) {
            T* tmp = other.mData;
            other.mData = this->mData;
            this->mData = tmp;
            return *this;
        }

        void print() {
            for (size_t i = 0; i < mSize; i++) std::cout << mData[i] << " ";
            std::cout << "\n";
        }
    }; 

    template<typename T>
    void swap(T &a, T &b) {
        T tmp = a;
        a = b;
        b = a;
    }
}


#endif
