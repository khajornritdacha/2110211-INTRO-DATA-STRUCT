#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

template <typename T>
void CP::stack<T>::mitosis(int a, int b)
{
    stack<T> tmp;
    for (int i = 0; i <= b; i++) {
        tmp.push(this->top());
        this->pop();
    }
    for (int i = a; i <= b; i++) {
        this->push(tmp.top());
        this->push(tmp.top());
        tmp.pop();
    }
    while (!tmp.empty()) {
        this->push(tmp.top());
        tmp.pop();
    }
}

#endif