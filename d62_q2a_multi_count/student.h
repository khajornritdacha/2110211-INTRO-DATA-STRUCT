#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <map>

template <typename T>
std::vector<std::pair<T,size_t>> CP::queue<T>::count_multi(std::vector<T> &k) const {
    std::map<T, size_t> freq;
    std::vector<std::pair<T, size_t>> res;
    for (int i = 0, pos = mFront; i < mSize; i++) {
        freq[mData[pos]]++;
        if (++pos == mCap) pos = 0;
    }
    for (T cur : k) res.push_back({cur, freq[cur]});
    return res;
}

#endif
