#include <iostream>
#include "diy_pair.h"
#include "diy_pair2.h"

int main() {
  JO::Pair<int, std::string> p1(1, "hello");
  JO::Pair<int, std::string> p2(10, "johnny");
  JO::Pair<int, std::string> p3(1, "hello");
  JO2::Pair p4;

  std::cout << "P1 == P3: " << !(p1 != p3) << "\n";
  // std::cout << "P1 == P3: " << (p1 == p3) << "\n";
  // std::cout << "P1 == P3: " << (p1 <= p3) << "\n";
  std::cout << p1.first << " " << p1.second << "\n";
  std::cout << p2.first << " " << p2.second << "\n";
  std::cout << p4.first.real << " " << p4.first.im << "\n";

}
