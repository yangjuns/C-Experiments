#include <iostream>

void Function(int && bar){
  std::cout << bar << std::endl;
}

int global = 0;

int& get_global(){
  return global;
}

int main(int argc, char const *argv[]) {
  int a = 1;
  int& b = a;
  int&& c = 3;

  int& d = b;
  d = 3;
  std::cout << b << std::endl;

  int test1 = get_global();
  test1 = 4;
  std::cout << global << std::endl;
  int& test2 = get_global();
  test2 = 5;
  std::cout << global << std::endl;

  // Function(a);
  // Function(b);
  // Function(c);
  return 0;
}
