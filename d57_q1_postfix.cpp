#ifndef __STUDENT_H__
#define __STUDENT_H__
#include <vector>

using namespace std;

int eval_postfix(vector<pair<int,int> > v) {
   //WRITE YOUR CODE HERE
   //DON"T FORGET TO RETURN THE RESULT
   vector<int> st;
   for (auto &[op, num] : v) {
      if (op == 0) {
         int y = st.back();
         st.pop_back();
         int x = st.back();
         st.pop_back();
         if (num == 0) {
            st.push_back(x + y);
         } else if (num == 1) {
            st.push_back(x - y); 
         } else if (num == 2) {
            st.push_back(x * y);
         } else {
            st.push_back(x / y);
         }
      } else {
         st.push_back(num);
      }
   }
   return st.back();
}

#endif

