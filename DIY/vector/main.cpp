#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif
#include "vector.h"

int main() {
    JO::Vector<int> vec1;
    JO::Vector<int> vec2;
    
    vec2.mData[0] = 1;
    vec2.mData[2] = 2;
    vec2.mData[3] = 15;

    vec2 = vec1;

    vec1.print();
    vec2.print();

    vec1.mData[1] = 10;

    vec1.print();
    vec2.print();
}