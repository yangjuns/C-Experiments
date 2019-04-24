#include <chrono>
#include <iostream>
#include <thread>

int sum = 0;
void Add(uint32_t id) {
  std::cout << "Start thread " << id << std::endl;
  for (int i = 0; i < 1000000000; i++)
    sum++;
  std::cout << "End thread " << id << std::endl;
}

void threadCaller() {}

int main() {
  std::thread t1(Add, 1);
  std::thread t2(Add, 2);
  t1.join();
  t2.join();
  std::cout << sum << std::endl;
}
