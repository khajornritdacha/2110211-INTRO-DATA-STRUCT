#ifndef JO_DIY_PAIR2_H
#define JO_DIY_PAIR2_H
#include "jo_type.h"

namespace JO2 {
    class Pair {
        public:
        Complex first;
        Complex second;

        // If not value is passed into list constructor, it uses default constructor of its respective type.
        Pair() {}
        Pair(Complex const &_first, Complex const &_second) : first(_first), second(_second) {}
    };
}

#endif
