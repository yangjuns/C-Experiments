#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // notice this! you need it!

#define GB_32 (34359738368)
int main(int argc, char const *argv[]) {
  char *addr = malloc(GB_32.);
  if (addr == NULL) {
    printf("allocation failed\n");
  }
  long long i;
  for (i = 0; i < GB_32; i++)
    addr[i] = 1;
  printf("addlocation succeeeded\n");
  sleep(5);
  return 0;
}
