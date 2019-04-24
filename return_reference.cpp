#include <iostream>
#include <vector>

class A {
public:
  A() { columns_.emplace_back(123); }
  std::vector<int>& GetVector(){
    return columns_;
  }
private:
  std::vector<int> columns_;
};


void PrintVector(std::vector<int> &v){
  for(auto i: v){
    printf("%d ", i);
  }
  printf("\n");
}

int main(int argc, char const *argv[]) {
  A a;
  std::vector<int> columns = a.GetVector();
  PrintVector(columns);
  columns.emplace_back(3);
  PrintVector(columns);
  PrintVector(a.GetVector());
  return 0;
}
