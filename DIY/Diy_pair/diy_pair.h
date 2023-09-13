#ifndef JO_DIY_PAIR_H
#define JO_DIY_PAIR_H

namespace JO {
    template<typename T1, typename T2>
    class Pair {
        public:
        T1 first;
        T2 second;

        Pair() : first(), second() {}

        /**
         * @brief Construct a new Pair object
         * 
         * @param _first 
         * @param _second 
         */
        Pair(T1 const &_first, T2 const &_second) : first(_first), second(_second) {}

        bool operator!=(Pair const &o) const {
            // Compile error
            // o.first = this->first;

            // Compile error
            // o = *this;

            return !(this->first == o.first and this->second == o.second);
        }
    };
}

#endif
