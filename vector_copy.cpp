#include <vector>
#include <iostream>
int main(int argc, char const *argv[]) {
  std::vector<int> a = {1,2,3,4};
  std::vector<int> b(a.begin(), a.end());
  std::cout << "b size:" << b.size() << std::endl;
  for(auto i: b) std::cout << i << std::endl;
  std::vector<int> c(a.begin(), a.end()-1);
  std::cout << "c size:" << c.size() << std::endl;
  for(auto i: c) std::cout << i << std::endl;
  return 0;
}
