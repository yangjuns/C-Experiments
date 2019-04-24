#include <functional>
#include <iostream>
#include <atomic>

// namespace temp{
struct MyStruct{
  long x; long y;
};

struct X{
  std::atomic<MyStruct> myStruct;
};
// }

// int main(){
//   temp::X x;
//   temp::MyStruct s = atomic_load(&x.myStruct);
// }
//
// int main(){
//   X x;
//   MyStruct s = atomic_load(&x.myStruct);
// }

#include "bwtree/include/bwtree.h"
using TEST_TYPE = char;
using BwTree = ::wangziqi2013::bwtree::BwTree<TEST_TYPE, TEST_TYPE, std::less<TEST_TYPE>, std::equal_to<TEST_TYPE>, std::hash<TEST_TYPE>,
                                              std::equal_to<TEST_TYPE>, std::hash<TEST_TYPE>>;

int main(){
  BwTree tree;
  bool ret = tree.Insert(1, 1, true);
  std::cout << ret << std::endl;
  return 0;
}
