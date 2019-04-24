#include <chrono>
#include <iostream>
#include <thread>

int sum = 0;
void Add() {
  for (int i = 0; i < 10000; i++)
    sum++;
}

void threadCaller() {}

int main() {
  std::thread t1(Add);
  std::thread t2(Add);
  t1.join();
  t2.join();
  std::cout << sum << std::endl;
}
