#include "stack.h"
#include "queue.h"

namespace CP {
    template<typename T>
    void stack<T>::appendStack(stack<T> s) {
        size_t tot_sz = mSize + s.size();
        T* res = new T[tot_sz];
        T tmp_new[s.size()];
        T tmp_or[mSize];
        size_t s_size = s.size();
        size_t m_size = size();
        int ptr = 0;
        while (!s.empty()) tmp_new[ptr++] = s.top(), s.pop();
        ptr = 0;
        while (!empty()) tmp_or[ptr++] = top(), pop();
        
        ptr = 0;
        for (int ptr_2 = s_size - 1; ptr_2 >= 0; ptr_2--, ptr++) res[ptr] = tmp_new[ptr_2];
        for (int ptr_2 = m_size - 1; ptr_2 >= 0; ptr_2--, ptr++) res[ptr] = tmp_or[ptr_2];

        mSize = tot_sz;
        mCap = tot_sz;
        delete[] mData;
        mData = res;
    }

    template<typename T>
    void stack<T>::appendQueue(queue<T> q) {
        stack<T> tmp, res, tmp2;
        while (!empty()) tmp.push(top()), pop();
        while (!q.empty()) tmp2.push(q.front()), q.pop();
        while (!tmp2.empty()) res.push(tmp2.top()), tmp2.pop();
        while (!tmp.empty()) res.push(tmp.top()), tmp.pop();
        *this = res;
    }  

    template<typename T>
    void queue<T>::appendStack(stack<T> s) {
        while (!s.empty()) push(s.top()), s.pop();
    }

    template<typename T>
    void queue<T>::appendQueue(queue<T> q) {
        while (!q.empty()) push(q.front()), q.pop();
    }
}
