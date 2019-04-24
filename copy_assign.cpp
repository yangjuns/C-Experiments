#include <iostream>
class a {
public:
    a() {
        printf("constructor called\n");
    };
    a(const a& other) {
        printf("copy constructor called\n");
    };
    a& operator=(const a& other) {
        printf("copy assignment operator called\n");
        return *this;
    };
};

int main(int argc, char const *argv[]) {
  a b , d;
  a c = b;
  d = b;
  return 0;
}
