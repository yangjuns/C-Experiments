#include <stdio.h>

int main(int argc, char const *argv[]) {
  uintptr_t a = static_cast<uint64_t>(-1);
  printf("%x\n", a);
  return 0;
}
